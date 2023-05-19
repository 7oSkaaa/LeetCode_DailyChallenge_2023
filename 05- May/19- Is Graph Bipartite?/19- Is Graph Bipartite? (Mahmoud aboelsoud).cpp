// author: Mahmoud Aboelsoud

class Solution {
public:
    // we just need to check if the graph is bipartite or not
    // we can do that by coloring the nodes with 2 colors and check if there is a node with 2 colors
    // if there is a node with 2 colors then the graph is not bipartite
    // else the graph is bipartite


    // graph: the adjacency list of the graph
    vector<vector<int>> graph;
    // cols: the color of each node
    vector<int> cols;
    // n: the number of nodes in the graph
    int n;
    
    // a dfs function to color the nodes
    bool dfs(int node, int col){
        // color the node with col
        cols[node] = col;

        // iterate over the neighbours of the node
        for(auto&i: graph[node]){
            // if the neighbour is not colored then color it with the opposite color of the node
            if(cols[i] == -1)
                // if the coloring failed after coloring the neighbour then the graph is not bipartite
                if(!dfs(i, !col)) return false;
            // if the neighbour is colored then check if it has the same color of the node
            else
                // if the neighbour has the same color of the node then the graph is not bipartite
                if(cols[i] == col) return false;
        }
        // if we reached here then the graph is bipartite
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        // initialize the graph and the cols array and the number of nodes
        this -> graph = graph;
        n = graph.size();
        cols.assign(n, -1);

        // the graph may not be connected so we need to check each component
        for(int i = 0; i < n; i++){
            // if the node is not colored then color it with 0
            if(cols[i] == -1){
                // if the coloring failed then the graph is not bipartite
                if(!dfs(i, 0)) return false;
            }
        }

        // if we reached here then the graph is bipartite
        return true;
    }
};
