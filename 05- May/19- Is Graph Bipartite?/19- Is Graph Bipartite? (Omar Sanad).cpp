// author : Omar Sanad

class Solution {
public:
    // declare an array to store the color of each node
    int color[101];

    // an adjacency list, where each node points to its neighbours
    vector<vector<int>> adj;

    // a dfs function to check whether a graph is Bipartite or not...
    // it keeps track of the current node, and the color of the parent node
    bool isBi(int node, int prevColor) {

        // if this node already has a color
        if (color[node])
            // then if the color is the same as its parent (its neighbour), the graph is not Bipartite
            // else if the color of this node is different from its parent (its neighbour), till now graph not Bipartite 
            return color[node] != prevColor;
        
        // declare a variable that checks whether all the neighbours colors can be different from the current node
        bool ok = true;

        // assign a color for the current node, give it a color that's different from the previous color
        color[node] = 3 - prevColor;

        // iterate over all neighbours of the current node, and check if we can assign them a color different from the current node.
        for (auto &child : adj[node])
            ok &= isBi(child, color[node]);

        // return the status till now (is it Bipartite or not)?
        return ok;        
    }

    bool isBipartite(vector<vector<int>>& graph) {
        this->adj = graph;

        // declare a variable that checks for each component if it is Bipartite or not
        bool ok = true;

        // iterate over each non-visited node (in other words, each connected component), and check if the component is Bipartite or not
        for (int i = 0; i < graph.size(); i++)
            if (not color[i])
                ok &= isBi(i, 1);
        
        // return the answer to the problem
        return ok;
    }
};
