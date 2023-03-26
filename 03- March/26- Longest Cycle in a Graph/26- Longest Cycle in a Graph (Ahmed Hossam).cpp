// Author: Ahmed Hossam

class Solution {
public:
    int LC, id;
    vector < int > path, edges, vis;

    // Helper function to perform DFS traversal
    void dfs(int u, int len) {
        // Set path length for current node
        path[u] = len;
        // Mark current node as visited in current DFS traversal
        vis[u] = id;

        // If current node has no outgoing edge, return
        if (edges[u] == -1)
            return;

        // Get next node in the cycle
        int v = edges[u];

        // If next node hasn't been visited yet, continue DFS traversal from next node
        if (path[v] == -1) 
            dfs(v, len + 1);
        // If next node has been visited in current traversal and is on a shorter path to the start node
        else if (path[v] < path[u] && vis[u] == vis[v])
            // Update longest cycle length
            LC = max(LC, len + 1 - path[v]);
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        // Initialize path lengths and visited nodes to -1
        path = vis = vector < int > (n, -1);
        this -> edges = edges;
        LC = -1, id = 0;

        // Iterate through all nodes in the graph
        for (int i = 0; i < n; i++) {
            // If node hasn't been visited yet, perform DFS traversal from that node and increment ID
            if (path[i] == -1)
                dfs(i, 0), id++;
        }

        // the longest Cycle in the graph
        return LC;
    }
};
