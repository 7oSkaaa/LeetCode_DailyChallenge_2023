// Author: Ahmed Hossam

class Solution {
public:
    
    // adjacency list to store the graph
    vector < vector < int > > adj;
    
    // visited array to mark nodes as visited during dfs
    vector < bool > vis;

    // dfs function to traverse the graph and count the number of edges to reverse
    int dfs(int u){
        // convert negative nodes to positive
        u = abs(u);
        // count the number of edges to reverse
        int cnt = 0;
        // mark node as visited
        vis[u] = true;
        // iterate over all adjacent nodes
        for(auto& v :  adj[u]){
            // skip if node has already been visited
            if(vis[abs(v)]) continue;
            // recursively traverse the graph and count the number of edges to reverse
            cnt += dfs(v) + (v > 0);
        }
        // return the total number of edges to reverse
        return cnt;
    }

    // function to find the minimum number of edges to reverse
    int minReorder(int n, vector < vector < int > > &connections){
        // initialize the adjacency list and visited array
        adj = vector < vector < int > > (n);
        vis = vector < bool > (n);
        // add edges to the adjacency list with appropriate signs
        for(auto& vec : connections){
            // add forward edge
            adj[vec[0]].push_back(vec[1]);
            // add reverse edge
            adj[vec[1]].push_back(-vec[0]);
        }
        // perform dfs from vertex 0 and return the total number of edges to reverse
        return dfs(0);
    }
};
