// Author: Ahmed Hossam

// Define a generic disjoint-set union data structure with an optional base node
// parameter for 1-based indexing, and a template parameter for data type T.
template <typename T = int, int Base = 1>
struct DSU {
    // The parent vector stores the parent of each node, and the Gsize vector
    // stores the size of each disjoint set.
    vector<T> parent, Gsize;

    // Constructor initializes the parent and Gsize vectors for all nodes.
    DSU(int MaxNodes) {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Recursive function to find the leader of the disjoint set that the node
    // belongs to, and updates the parent of all visited nodes to the leader.
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Returns true if the two nodes belong to the same disjoint set.
    bool is_same_sets(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    // Merges the disjoint sets containing the two nodes u and v.
    void union_sets(int u, int v) {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v) return;
        if (Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Returns the size of the disjoint set that the node belongs to.
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Variable to store the number of edges removed.
        int removed_edges = 0;
        // Create two disjoint-set union objects, one for Alice and one for Bob.
        DSU<int> alice(n), bob(n);
        // Sort edges in decreasing order of type so that type 3 edges are
        // processed last.
        sort(edges.rbegin(), edges.rend());
        // Loop through each edge in the sorted list.
        for (auto& edge : edges) {
            int t = edge[0], u = edge[1], v = edge[2];
            // Process the edge based on its type.
            if (t == 1) {
                if (alice.is_same_sets(u, v)) removed_edges++;
                else alice.union_sets(u, v);
            } else if (t == 2) {
                if (bob.is_same_sets(u, v)) removed_edges++;
                else bob.union_sets(u, v);
            } else {
                if (alice.is_same_sets(u, v) && bob.is_same_sets(u, v)) removed_edges++;
                else alice.union_sets(u, v), bob.union_sets(u, v);
            }
        }
        // Check if all nodes belong to the same disjoint set for both Alice and
        // Bob. If not, return -1 as it is impossible to remove enough edges to
        // create a spanning tree for both players.
        if (alice.get_size(1) != n || bob.get_size(1) != n)
            return -1;
        // Return the number of edges removed.
        return removed_edges;
    }
};
