// Author: Mina Magdy

class Solution {
public:
    // Define a struct for Disjoint Set Union (DSU) data structure
    struct DSU {
        vector<int> p, s;
        // Constructor to initialize the parent array and size array for each set
        DSU(int n) {
            p.resize(n);
            iota(p.begin(), p.end(), 0); // Set each node as its own parent initially
            s.assign(n, 1); // Initialize the size of each set as 1 initially
        }
        // Function to find the root parent of a node
        int find(int x) {
            return (x == p[x] ? x : p[x] = find(p[x])); // Path compression optimization is used here
        }
        // Function to merge two sets
        void merge(int u, int v) {
            int r1 = find(u), r2 = find(v);
            if (r1 == r2) return; // If both nodes already belong to the same set, we don't need to merge
            if (s[r2] > s[r1]) swap(r1, r2); // Union by rank optimization is used here
            p[r2] = r1; // Set the parent of smaller set to be the root of the larger set
            s[r1] += s[r2]; // Add the size of the smaller set to the size of the larger set
        }
    };
    // Function to count the number of pairs of nodes that are not connected by an edge
    long long countPairs(int n, vector<vector<int>>& edges) {
        // Initialize the DSU data structure
        DSU dsu(n);
        for (auto& v : edges) {
            dsu.merge(v[0], v[1]); // Merge the two nodes in the same set
        }
        // Count the number of nodes in each set and sum the number of pairs of nodes that are not connected by an edge
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            int r = dsu.find(i); // Find the root parent of the node
            cnt += n - dsu.s[r]; // Add the number of nodes not in the same set as the current node to the count
        }
        return cnt / 2; // Divide the count by 2 since we have counted each pair twice
    }
};
