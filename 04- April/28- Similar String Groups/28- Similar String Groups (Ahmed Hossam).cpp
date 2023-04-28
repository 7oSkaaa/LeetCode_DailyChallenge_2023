// Author: Ahmed Hossam

// Template for disjoint set union (DSU) data structure with custom node type and base index
template <typename T = int, int Base = 0> 
struct DSU {
    // Store parent and group size for each node
    vector<T> parent, Gsize;

    // Constructor initializes parent and group size for all nodes
    DSU(int MaxNodes) {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++) {
            parent[i] = i;
            Gsize[i] = 1;
        }
    }

    // Find the leader of the group for the given node and perform path compression
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Check if two nodes are in the same group
    bool is_same_sets(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    // Merge the groups containing the given nodes
    void union_sets(int u, int v) {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v) return;
        if (Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v];
        parent[leader_v] = leader_u;
    }

    // Get the size of the group containing the given node
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

// Solution class for finding number of similar groups
class Solution {
public:
    // Function to check if two strings differ by at most 2 characters
    bool is_similar(const string& a, const string& b) {
        int diff = 0, n = a.size();

        // Iterate through each character of the two strings and count the number of differences
        for (int i = 0; i < n; i++)
            diff += (a[i] != b[i]);

        // Return true if the number of differences is less than or equal to 2
        return diff <= 2;
    }

    // Function to find the number of similar groups in a vector of strings
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // Create a disjoint-set data structure with n elements
        DSU<int> dsu(n);

        // Iterate through each pair of strings in the vector and union their sets if they are similar
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (is_similar(strs[i], strs[j]))
                    dsu.union_sets(i, j);

        int groups = 0;

        // Count the number of groups by counting the number of leaders in the disjoint-set data structure
        for (int i = 0; i < n; i++)
            groups += dsu.find_leader(i) == i;

        // Return the number of groups
        return groups;
    }

};
