// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    // create adjacency list
    vector<vector<int>> adj;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        // add edges to adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(hasApple,0,0,-1)*2;
    }
    int dfs(vector<bool>& hasApple, int cur,int d,int prev){
        int ans=0;
        for(int i=0;i<adj[cur].size();i++){
            // if this node not equal the last one (to avoid cycles)
            if(adj[cur][i]!=prev){
                int ch1=dfs(hasApple,adj[cur][i],d+1,cur);
                if(ch1){
                    // update the answer 
                    ans+=ch1-d;
                }
            }
        }
        return (ans || hasApple[cur]?ans+d:0);
    }
};