// Author: Mahmoud Aboelsoud

// to find the longest cycle in a graph
// we use topological sort to find if there is a cycle
// and we can only use depth to find the depth of entering a node
// and we can only use vis to find if a node is visited or not
// so we use 3 states for vis
// 0: not visited
// 1: visited but not finished
// 2: visited and finished

// we use dfs to find the longest cycle
// if we traversed a node before and it is not finished that means there is a cycle
// and we can find the length of the cycle by subtracting the depth of the node we are in now from the depth of the node we traversed before + 1
// and we can only use depth to find the depth of entering a node

class Solution {
public:
    // initialize the depth and vis vectors and the input edges vector
    vector<int> vis, depth, edges;
    // initialize the number of nodes and the answer
    int n, ans;
    
    // dfs function
    void dfs(int u, int dep){
        // mark the node as visited but not finished and assign the depth of entering the node
        vis[u] = 1;
        depth[u] = dep;

        // get the next node
        int v = edges[u];
        // if the next node is not -1
        if(v != -1){
            // if the next node is visited but not finished that means there is a cycle
            if(vis[v] == 1)
                // find the length of the cycle by subtracting the depth of the node we are in now from the depth of the node we traversed before + 1
                ans = max(ans, depth[u] - depth[v] + 1);
            // if the next node is not visited
            else if(!vis[v])
                // traverse the next node
                dfs(v, dep + 1);
        }
        // mark the node as visited and finished
        vis[u] = 2;
    }


    int longestCycle(vector<int>& edges) {
        // assign the input edges vector to the edges vector
        this -> edges = edges;
        // initialize the answer to -1
        ans = -1;
        // assign the number of nodes to the size of the edges vector
        n = edges.size();
        // assign the vis and depth vectors to the number of nodes
        vis.assign(n, 0);
        depth.assign(n, 0);

        // traverse all the nodes if they are not visited
        for(int i = 0; i < n; i++)
            if(!vis[i]) dfs(i, 0);

        return ans;
    }
};
