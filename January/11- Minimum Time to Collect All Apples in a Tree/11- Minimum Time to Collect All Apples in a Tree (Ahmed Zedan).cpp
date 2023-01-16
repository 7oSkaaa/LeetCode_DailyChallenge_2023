// author : Ahmed Zedan
class Solution {
public:
    vector<int>vis ;      // visited vertex 
    vector<bool> has ;    //check vertex have apple or not 
    vector<vector<int>>adj ; // adjency matrix 
    int dfs(int i=0 , int cost=0){
        int ans = 0 ;  
        vis[i] = 1 ; // mark vertex is visited
        for(auto j : adj[i]){
            if(!vis[j]){  
                ans+= dfs(j,2) ; // go to childern vertex 
            }
        }
        if(!ans&&!has[i]) return 0 ;  // if path not have apple return 0
        return ans + cost ;  // if path have apple return number of path + 2 
    } 
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vis = vector<int>(n,0) ; 
        adj = vector<vector<int>>(n) ;
        has = hasApple ; 
        for(auto a : edges){
            int u = a[0] ;
            int v = a[1] ; 
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;  
        }
        return dfs() ; 
    }
};