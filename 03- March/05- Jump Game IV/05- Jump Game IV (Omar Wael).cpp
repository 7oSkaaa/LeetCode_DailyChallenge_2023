// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int minJumps(vector<int>& arr) {
        // declare unordered_map to save on it the indices of each value
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        // visited array to visit each node at most once
        // and to avoid runtime error
        int vis[n];
        for(int i=0;i<n;i++){
            vis[i]=0;
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        // start from index 0
        q.push(0);
        vis[0]=1;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            // try go through all nodes from queue
            for(int i=0;i<size;i++){
                int cur=q.front();
                q.pop();
                // if current node equal n-1
                // return number of steps
                if(cur==n-1){
                    return ans;
                }
                // try all possible ways from current node
                // i+1 if not visited try it
                if(vis[cur+1]==0){
                    vis[cur+1]=1;
                    q.push(cur+1);
                }
                // i-1 if not visited try it
                if(cur>0 && vis[cur-1]==0){
                    vis[cur-1]=1;
                    q.push(cur-1);
                }    
                // try all indices of current value
                for(auto it=mp[arr[cur]].begin();it!=mp[arr[cur]].end();it++){
                    if(*it!=cur && vis[*it]==0){
                        vis[*it]=1;
                        q.push(*it);
                    }
                }
                // clear all indices of current value
                // you will not need them again so clear them
                // to avoid extra searching nodes
                mp[arr[cur]].clear();
            }
            // increase the number of steps
            ans++;
        }
        return 0;
    }
};

