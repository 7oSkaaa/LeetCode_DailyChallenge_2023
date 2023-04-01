// Author: Ahmed Gamal

// for this problem, we need to move the minimum number of edges in order to make all the computers connected
// if we have n computers, then we need n - 1 edges to connect all the computers
// so for each connected component, it needs size_of_connected_component - 1 edges to be connected
// any extra edge is not needed and we can use it to connect another connected component
// so we can the number of extra edges is the number of edges - (size_of_connected_component - 1)
// and in order to connect all the computers, we need to connect all the connected components 
// with a similar idea, to connect all the connected components, we need cnt_connected_components - 1 edges

// so if we have enough extra edges, we can connect all the connected components

class Solution {
    // adj: adjacency list of the graph
    // vis: visited array
    // edges: the edges that are in the same connected component

    vector<vector<pair<int, int>>> adj;
    vector<bool> vis;
    set<int> edges;
public:

    // dfs: dfs to find the connected components
    // src: the current node
    // cnt: the number of nodes in the current connected component
    void dfs(int src, int& cnt) {
        // mark the current node as visited
        vis[src] = true;

        // increase the number of nodes in the current connected component
        cnt++;

        // iterate over the neighbors of the current node
        // nxt: the neighbor
        // id: the id of the edge between the current node and the neighbor
        for(auto& [nxt, id] : adj[src]) {
            // add the edge to the edges that are in the same connected component
            edges.emplace(id);

            // if the neighbor is not visited, then visit it
            if(not vis[nxt]) {
                dfs(nxt, cnt);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        adj.assign(n, vector<pair<int, int>>());
        vis.resize(n);

        // create the graph
        for(int i = 0; i < connections.size(); i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].emplace_back(v, i);
            adj[v].emplace_back(u, i);
        }

        // cnt_comp: the number of connected components
        // cnt_rem: the number of extra edges
        int cnt_comp = 0, cnt_rem = 0;

        // iterate over the nodes
        for(int i = 0; i < n; i++) {
            // if the node is not visited, then visit it (it is the start of a new connected component)
            if(not vis[i]) {
                // increase the number of connected components
                cnt_comp++;

                // cnt_nodes: the number of nodes in the current connected component
                int cnt_nodes = 0;

                // clear the edges that are in the same connected component
                edges.clear();

                // visit the current connected component
                dfs(i, cnt_nodes);

                // add the number of extra edges to the total number of extra edges
                cnt_rem += edges.size() - (cnt_nodes - 1);
            }
        }

        // if we have enough extra edges, then we can connect all the connected components
        // otherwise, we can't connect all the computers
        return cnt_rem >= cnt_comp - 1 ? cnt_comp - 1 : -1;
    }
};