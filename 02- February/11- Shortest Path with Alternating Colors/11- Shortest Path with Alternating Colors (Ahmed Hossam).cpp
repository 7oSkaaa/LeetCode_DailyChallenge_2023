// Author: Ahmed Hossam

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector < vector < pair < int, int > > > adj(n);
        vector < vector < int > > path(n, vector < int > (2, -1));
        
        // make the adjacency list each adjacent pair will be the another node and the color of the edge
        for(auto& v : redEdges)
            adj[v[0]].push_back({v[1], 0});
        for(auto v:blueEdges)
            adj[v[0]].push_back({v[1], 1});
        
        // do bfs from 0 to each nodes
        queue < pair < int, int > > bfs;
        bfs.push({0,0});
        bfs.push({0,1});
        path[0] = {0,0};
        
        while(!bfs.empty()){
            // current node and current color
            auto [u, c] = bfs.front(); 
            bfs.pop();
            
            for(auto [v, new_c] : adj[u]){
                // if this edge is the new edge is same colour will the current edge or this state is appears before skip it
                if(path[v][new_c] != -1 || c == new_c) continue;

                // update the path to the new vertex and put it in the queue
                path[v][new_c] = 1 + path[u][c];
                bfs.push({v, new_c});
            }
        }

        // add the minimum path for each vertex
        vector < int > res;
        for(auto& v : path) {
            sort(v.begin(), v.end());
            res.push_back(v[0] != -1 ? v[0] : v[1]);
        }

        return res;
        
    }
};
