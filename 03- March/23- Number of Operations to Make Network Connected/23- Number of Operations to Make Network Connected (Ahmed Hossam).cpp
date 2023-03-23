// Author: Ahmed Hossam

// A template class for Disjoint Set Union (DSU) data structure
template < typename T = int, int Base = 0 > struct DSU {
    vector < T > parent, Gsize; // Parent and size vectors to store the parent of each node and the size of each set

    // Constructor to initialize the parent and Gsize vectors
    DSU(int MaxNodes) {
        // Allocate memory for parent and Gsize vectors
        parent = Gsize = vector < T >(MaxNodes + 5); 

        // Initially, set the parent of each node to itself and the size of each set to 1
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Function to find the leader (root) of the set that the given node belongs to
    T find_leader(int node) {
        // Path compression optimization
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Function to check if two nodes are in the same set
    bool is_same_sets(int u, int v) {
        // Check if both nodes have the same leader (root)
        return find_leader(u) == find_leader(v);
    }

    // Function to merge two sets containing the given nodes
    void union_sets(int u, int v) {
        // Find the leaders of the sets containing u and v
        int leader_u = find_leader(u), leader_v = find_leader(v);

        // If they are already in the same set, nothing to do
        if (leader_u == leader_v) return;

        // Merge the smaller set into the larger set
        if (Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);

        // Update the size of the merged set
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU < int > dsu(n);

        // Merge the sets containing each pair of connected nodes
        for (auto& vec : connections)
            dsu.union_sets(vec[0], vec[1]);

        int connected = 0;

        // Count the number of connected components
        for (int i = 0; i < n; i++)
            if (dsu.find_leader(i) == i)
                connected++;

        // If there are not enough edges to connect all nodes, return -1
        if (connections.size() < n - 1)
            return -1;

        // Return the number of redundant edges needed to connect all nodes
        return connected - 1;
    }
};
