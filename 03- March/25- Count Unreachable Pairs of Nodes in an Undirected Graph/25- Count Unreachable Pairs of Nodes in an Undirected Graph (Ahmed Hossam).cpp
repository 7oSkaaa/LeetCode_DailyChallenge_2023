// Author: Ahmed Hossam

// Define a class for Disjoint Set Union (DSU)
template < typename T = int, int Base = 0 > struct DSU {
    // Declare a vector to store the parent and size of each node
    vector < T > parent, Gsize;

    // Constructor for DSU class
    DSU(int MaxNodes) {
        // Initialize the parent and Gsize vector with Base and 1 respectively
        parent = Gsize = vector < T > (MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Function to find the leader of the set to which a node belongs
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Function to check if two nodes belong to the same set or not
    bool is_same_sets(int u, int v) {
        // if the two nodes have the same leader so they are in the same set
        return find_leader(u) == find_leader(v);
    }

    // Function to union the sets of two nodes
    void union_sets(int u, int v) {
        // Find the leaders of the sets to which the two nodes belong
        int leader_u = find_leader(u), leader_v = find_leader(v);
        // If the two nodes belong to the same set so there is no need to union them
        if (leader_u == leader_v) return;
        // Union the two sets by attaching the smaller set to the larger set
        if (Gsize[leader_u] < Gsize[leader_v]) 
            swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Function to get the size of the set to which a node belongs
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    // Function to count the number of pairs of nodes such that they belong to different components
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Create an instance of the DSU class
        DSU < int > dsu(n);
        // Union the sets of all nodes in the given edges
        for (auto& edge : edges)
            dsu.union_sets(edge[0], edge[1]);
        // Create a map to store the number of nodes in each component
        unordered_map < int, int > components;
        for (int i = 0; i < n; i++)
            components[dsu.find_leader(i)]++;
        // Calculate the number of pairs of nodes such that they belong to different components
        long long ans = 0;
        for (auto& [leader, sz] : components)
            ans += 1ll * sz * (n - sz);

        // Return the number of pairs of nodes such that they belong to different components
        return ans / 2;
    }
};
