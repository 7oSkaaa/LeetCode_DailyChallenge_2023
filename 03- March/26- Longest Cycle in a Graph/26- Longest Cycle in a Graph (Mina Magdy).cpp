// Author: Mina Magdy

class Solution {
public:
    vector<int> dist; // vector to keep track of the distance from the starting node
    vector<int> edges; // vector to store the edges
    int n, ans; // n is the number of vertices, ans is the length of the longest cycle

    // Depth First Search function
    void dfs(int u, int &cnt) {
        if (~dist[u]) { // if we already visited this node
            ans = max(ans, cnt - dist[u]); // update the ans to be the max between the current ans and the distance from the current node to the starting node minus the distance from the current node to the node where we previously visited
            return;
        }
        dist[u] = cnt; // mark this node as visited and update the distance
        if (~edges[u]) // if the current node has a next node
        dfs(edges[u], ++cnt); // recursively call dfs on the next node and increment the count of the distance
        dist[u] = 1e9; // unmark this node as visited
    }

    int longestCycle(vector<int>& edges) {
        n = edges.size(); // get the number of vertices
        dist.assign(n, -1); // initialize the distance vector with -1 to indicate that no nodes have been visited yet
        this->edges = edges; // store the edges
        for (int i = 0; i < n; i++) { // iterate through all the nodes
            if (!~dist[i]) { // if this node hasn't been visited yet
                int cnt = 0; // initialize the distance count
                dfs(i, cnt); // call dfs on the current node and pass in the distance count
            }
        }
        return (ans ? : -1); // return the length of the longest cycle if it exists, otherwise return -1
    }
};
