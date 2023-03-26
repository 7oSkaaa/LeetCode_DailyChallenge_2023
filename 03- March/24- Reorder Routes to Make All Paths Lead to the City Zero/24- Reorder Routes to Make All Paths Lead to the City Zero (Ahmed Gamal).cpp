// Author: Ahmed Gamal

// for this problem, we want to change directions of some edges in order to make all the paths lead to the city zero
// to find this, we can think of the problem in reverse
// we can start from the city zero and find the right direction of each edge and then count the number of edges that are not in the right direction
// to do this, we can use dfs, and for each edge, we can store its id in the edges vector
// and because we are doing our traversal in reverse, the direction of the edge should be from the next node to its parent

class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections) {
        // adj: adjacency list of the graph (the first element of the pair is the neighbor and the second element is the id of the edge)
        // edges: the edges of the graph (the first element of the pair is the source and the second element is the destination)
        vector<vector<pair<int, int>>> adj(n);
        vector<pair<int, int>> edges(connections.size());

        // create the graph
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }

        auto dfs = [&](auto dfs, int src, int par) -> void {
            // iterate over the neighbors of the current node
            for(auto& [nxt, id] : adj[src]) {
                // if the neighbor is the parent, then skip it
                if(nxt == par)
                    continue;
                // store the edge in the edges vector with the right direction and visit the neighbor
                edges[id] = {nxt, src};
                dfs(dfs, nxt, src);
            }
        };

        // start dfs from the city zero
        dfs(dfs, 0, -1);

        // cnt: the number of edges that are not in the right direction
        int cnt = 0;
        for(int i = 0; i < connections.size(); i++) {
            // if the edge is not in the right direction, then increase the number of edges that are not in the right direction
            int u = connections[i][0], v = connections[i][1];
            if(make_pair(u, v) == edges[i])
                continue;
            cnt++;
        }

        return cnt;
    }
};