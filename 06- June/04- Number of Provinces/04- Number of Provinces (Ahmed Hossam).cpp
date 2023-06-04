// Author: Ahmed Hossam

class Solution {
public:

    vector < int > parent, Gsize;

    // Initialize the parent and size vectors with the given maximum number of nodes
    void init(int MaxNodes){
        parent.resize(MaxNodes + 5);
        Gsize.resize(MaxNodes + 5);
        for(int i = 1; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Find the leader/representative of the set that the given node belongs to
    int find_leader(int node){
        // If the parent of the node is the node itself, it is the leader
        // Otherwise, recursively find the leader of the parent node
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Union two sets represented by the given nodes
    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        
        // If the leaders are the same, the nodes are already in the same set, so no action is needed
        if(leader_u == leader_v) return;
        
        // Merge the smaller set into the larger set
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v];
        parent[leader_v] = leader_u;
    }
    
    // Find the number of connected components in the given graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Initialize the parent and size vectors
        init(n);
        
        // Traverse the graph and union the connected nodes
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j] == 1)
                    union_sets(i, j);
        
        int connected = 0;
        
        // Count the number of unique leaders to determine the number of connected components
        for(int i = 0; i < n; i++)
            if(find_leader(i) == i) connected++;
        
        // Return the number of connected components
        return connected;
    }
};
