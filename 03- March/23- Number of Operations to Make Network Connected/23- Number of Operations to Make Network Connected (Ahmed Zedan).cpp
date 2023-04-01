//author : Ahmed Zedan
class Solution {
public:
    vector<vector<int>>adj ; // adjency list 
    vector<int> vis ;  // visited node 
    int components = 0 ; // number of conected components
    // dfs traversal to count conected components
    void dfs(int u){
        vis[u] = 1 ; 
        for(auto v : adj[u]){
            if(!vis[v]) dfs(v) ; 
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        adj = vector<vector<int>>(n);
        vis = vector<int> (n,0);

        for(auto a : connections){
            int u = a[0] , v = a[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                components++ ;
                dfs(i) ;
            }
        }
        // minimum number of edges in connected graph (n-1)
        // so if number of edges in graph less than n-1 return -1 
        // conect all conected components
        // so return (number of conected components - 1 )
        return (n-1>connections.size()?-1:components-1) ; 
    }
};