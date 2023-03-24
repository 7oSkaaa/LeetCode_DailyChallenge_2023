// Author: Ahmed Hossam

class Solution {
public:
    
    // adjacency list to store the graph
    vector < vector < int > > adj;
    
    // visited array to mark nodes as visited during dfs
    vector < bool > vis;

    // dfs function to traverse the graph and count the number of edges to reverse
    int dfs(int u){
        u = abs(u); // convert negative nodes to positive
        int cnt = 0; // count the number of edges to reverse
        vis[u] = true; // mark node as visited
        for(auto& v :  adj[u]){ // iterate over all adjacent nodes
            if(vis[abs(v)]) continue; // skip if node has already been visited
            cnt += dfs(v) + (v > 0); // recursively traverse the graph and count the number of edges to reverse
        }
        return cnt; // return the total number of edges to reverse
    }

    // function to find the minimum number of edges to reverse
    int minReorder(int n, vector < vector < int > > &connections){
        
        // initialize the adjacency list and visited array
        adj = vector < vector < int > > (n);
        vis = vector < bool > (n);
        
        // add edges to the adjacency list with appropriate signs
        for(auto& vec : connections){
            adj[vec[0]].push_back(vec[1]); // add forward edge
            adj[vec[1]].push_back(-vec[0]); // add reverse edge
        }
        
        // perform dfs from vertex 0 and return the total number of edges to reverse
        return dfs(0);
    }
};
