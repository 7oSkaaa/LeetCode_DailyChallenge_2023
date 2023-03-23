// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // adjacency matrix to save all roads from ith city and its distance
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        // create queue to apply BFS
        queue<int>q;
        // start from city 1
        q.push(1);
        int ans=INT_MAX;
        // visited array to avoid cycles
        vector<int>vis(n+1,0);
        vis[1]=1;
        while(!q.empty()){
            // get current city
            int cur=q.front();
            q.pop();
            // go throw all unvisited cities connected to current city
            for(auto i:adj[cur]){
                // update answer
                ans=min(ans,i.second);
                if(!vis[i.first]){
                    q.push(i.first);
                    vis[i.first]=1;
                }
            }
        }
        return ans;
    }
};
