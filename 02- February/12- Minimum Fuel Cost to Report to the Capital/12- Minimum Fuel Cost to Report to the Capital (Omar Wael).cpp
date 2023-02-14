// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<vector<int>>adj;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        adj.resize(n);
        vector<int>vis(n,0);
        // add the roads to adjacency matrix
        for(auto road:roads){
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        long long ans=0;
        dfs(vis,0,ans,seats);
        return ans;
    }
    long long dfs(vector<int>& vis,int cur,long long& ans,int& seats){
        // cnt -> number of people will be at current city
        long long cnt=0;
        // set cuurent city to be visited
        vis[cur]=1;
        //search on its neighbours
        for(int i=0;i<adj[cur].size();i++){
            // check if this node not visited yet
            if(!vis[adj[cur][i]]){
                // search of this city neighbours and update cnt
                cnt+=dfs(vis,adj[cur][i],ans,seats);
            }
        }
        if(cur!=0){
            // add current city representatives 
            cnt+=1;
            // calculate number of cars needed to move from this city
            ans+=cnt/seats;
            if(cnt%seats!=0){
                ans++;
            }
        }
        return cnt;
    }
};