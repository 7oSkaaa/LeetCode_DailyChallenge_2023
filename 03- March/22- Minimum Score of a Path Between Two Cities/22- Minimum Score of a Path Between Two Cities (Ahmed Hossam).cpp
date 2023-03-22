// Author: Ahmed Hossam

template < typename T = int, int Base = 1 > struct DSU {
    
    vector < T > parent, Gsize, Min;

    // Constructor: initializes parent and Gsize vectors to store the nodes and their sizes, 
    // and initializes Min vector with very large values.
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        Min = vector < T > (MaxNodes + 5, 1e9);
        // Initializes each node to be its own parent and its size to be 1.
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    // Finds the leader (or root) of the set that the node belongs to, 
    // and compresses the path to the leader for optimization.
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Checks if two nodes are in the same set.
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    // Merges two sets that contain nodes u and v, and updates the minimum weight 
    // of the edge that connects them.
    void union_sets(int u, int v, int w){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        // Update the minimum weight of the edge that connects the two sets.
        Min[leader_u] = Min[leader_v] = min({Min[leader_u], Min[leader_v], w});
        // If the two nodes are already in the same set, we don't need to merge them.
        if(leader_u == leader_v) return;
        // Merge the smaller set into the larger set to keep the tree balanced.
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Returns the size of the set that the node belongs to.
    int get_size(int u){
        return Gsize[find_leader(u)];
    }

    // Returns the minimum weight of the edge that connects the set that the node belongs to with any other set.
    int get_min(int u){
        return Min[find_leader(u)];
    }
};

class Solution {
public:

    // Solves the problem of finding the minimum score in a graph after removing a single edge.
    int minScore(int n, vector<vector<int>>& roads) {
        DSU < int > dsu(n);
        // Union all edges in the graph.
        for(auto& r : roads)
            dsu.union_sets(r[0], r[1], r[2]);
        // Return the minimum weight of the edge that connects the set that contains node n with any other set.
        return dsu.get_min(n);
    }
};
