// Author: Mina Magdy

// Define a class Solution
class Solution {
public:
    // Define a Disjoint Set Union (DSU) data structure
    struct DSU {
        int cc; // Number of connected components
        vector<int> p, s; // Parent array and size array

        // Constructor
        DSU(int n) {
            cc = n; // Initialize number of connected components to n
            p.resize(n); // Initialize parent array size to n
            iota(p.begin(), p.end(), 0); // Initialize parent array with values 0, 1, ..., n-1
            s.assign(n, 1); // Initialize size array with all 1s
        }

        // Find function with path compression optimization
        int find(int x) {
            if (p[x] == x) {
                return x;
            }
            return p[x] = find(p[x]);
        }

        // Merge two sets, returns true if they are already in the same set
        bool merge(int u, int v) {
            int r1 = find(u), r2 = find(v); // Find roots of sets containing u and v
            if (r1 == r2) { // If already in the same set, return true
                return true;
            }
            if (s[r2] > s[r1]) { // Union by rank optimization
                swap(r1, r2);
            }
            p[r2] = r1; // Set root of smaller set to be the child of the root of larger set
            s[r1] += s[r2]; // Update size of the new larger set
            cc--; // Decrement number of connected components
            return false; // Return false since sets were merged
        }
    };

    // Function to make all computers connected
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n); // Initialize DSU with n elements
        int rem = 0; // Initialize number of remaining edges to be 0

        // Loop over all connections
        for (auto& vec : connections) {
            // Merge sets containing u and v, and increment remaining edges if necessary
            rem += dsu.merge(vec[0], vec[1]);
        }

        // If the number of connected components can be reduced to 1 or less using remaining edges, return that number of edges
        // Otherwise, return -1 indicating that it is impossible to make all computers connected
        return (dsu.cc - 1 <= rem ? dsu.cc - 1 : -1);
    }
};
