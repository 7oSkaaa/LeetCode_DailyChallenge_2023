// author : Ahmed Zedan

//bfs
class Solution {
public:
    /*
    * there is at least one path between 1 and n.
    * we can perform a BFS traversal starting from node 1 passing all the path from city 1 to city n.
    * get minimum distance from all path between node 1 and n 
    * use visit to mark nodes are already visited before .
    * undirected graph
    */
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1) ; //adjacency list
        vector<int>vis(n+1,0) ; // visited nodes
        for(auto &a : roads){
            int u = a[0] , v = a[1] , d=a[2] ; 
            adj[u].push_back({v,d}) ; 
            adj[v].push_back({u,d}) ; 
        }
        queue<int>bfs ; // bfs queue
        bfs.push(1) ; // start from node 1 
        vis[1] = 1 ; // mark node 1 is visit
        int ans = INT_MAX ; 
        while(!bfs.empty()){
            int sz = bfs.size() ;
            while(sz--){ 
                int u = bfs.front() ; 
                bfs.pop() ; 
                for(auto [v,d] : adj[u]){
                    ans = min(ans,d) ; //get minimum distance from all path between node 1 and n 
                    if(!vis[v]){
                        bfs.push(v) ; 
                        vis[v] = 1 ; // mark node is visited 
                    }
                }
            }
        }
        return ans ; 
    }
};
*******************************************************************************************************************************
//dfs
class Solution {
public:
    vector<vector<pair<int,int>>>adj ; 
    vector<int>vis ; 
    int ans = INT_MAX ; 
    void dfs(int u=1){
        vis[u] = 1 ; 
        for(auto [v,d] : adj[u]){
            ans = min(ans , d) ; 
            if(!vis[v]) dfs(v) ; 
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        adj = vector<vector<pair<int,int>>>(n+1) ; //adjacency list
        vis = vector<int>(n+1,0) ; // visited nodes
        for(auto &a : roads){
            int u = a[0] , v = a[1] , d=a[2] ; 
            adj[u].push_back({v,d}) ; 
            adj[v].push_back({u,d}) ; 
        }
        dfs() ; 
        return ans ; 
    }
};