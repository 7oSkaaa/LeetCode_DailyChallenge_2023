//author : Ahmed Zedan
class Solution {
public:
    vector<vector<int>>adj; // adjency matrix 
    vector<int>ans ;   //answer matrix
    vector<int>cnt ;   //frequance character in graph
    string L ;         // labels string 
    void dfs(int i=0){
        int prev = cnt[L[i]-'a'] ; //number of character before sub tree
        ans[i] = 1 ;               // mark the node is visited 
        for(auto j : adj[i]){
            if(!ans[j]){   
                dfs(j) ; 
            }
        }
        int curr = ++cnt[L[i]-'a'] ; 
        ans[i] = curr-prev ;  // number of the same label in sub tree 
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj = vector<vector<int>>(n) ; 
        for(auto a : edges){  // make adjency matrix
            int u=a[0] ; 
            int v=a[1] ;
            adj[u].push_back(v) ;
            adj[v].push_back(u) ; 
        }
        ans = vector<int>(n,0) ;
        cnt = vector<int>(26,0) ;
        L=labels ;
        dfs() ;  
        return ans ;  
    }
};