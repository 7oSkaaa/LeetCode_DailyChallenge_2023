// Author: Ahmed Hossam

template < typename T = int, int Base = 0 > struct DSU {
    
    vector < T > parent, Gsize;

    // every element will be equal it's parent and the group size equal 1
    DSU(int MaxNodes){
        parent = Gsize = vector < T > (MaxNodes + 5);
        for(int i = Base; i <= MaxNodes; i++)
          parent[i] = i, Gsize[i] = 1;
    }
    
    // get the leader of each group
    T find_leader(int node){
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // check if the two nodes in the same group
    bool is_same_sets(int u, int v){
        return find_leader(u) == find_leader(v);
    }

    // merge two groups together
    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if(leader_u == leader_v) return;
        if(leader_u < leader_v) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // get group size
    int get_size(int u){
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
        // number of nodes
        int n = vals.size();

        // adjacent list for each node
        vector < vector < int > > adj(n);

        // dsu structure
        DSU < int > dsu(n);

        // the nodes that equal each value
        map < int, vector < int > >  V_nodes;

        // make edge between the nodes with nodes have value greater than or equal it
        for(auto& edge : edges){
            if(vals[edge[0]] <= vals[edge[1]])
                adj[edge[1]].push_back(edge[0]);
            if(vals[edge[1]] <= vals[edge[0]])
                adj[edge[0]].push_back(edge[1]);
        }

        // add nodes of each value
        for(int i = 0; i < n; i++)
            V_nodes[vals[i]].push_back(i);
        
        // number of good paths equal to n because each node is good path
        int good_paths = n;

        // iterate for each value in ascending order
        for(auto& [val, nodes] : V_nodes){

            // iterate over the nodes with the value val and add the nodes with it's neighbours to merge the groups
            for(auto& u : nodes)
                for(auto& v : adj[u])
                    dsu.union_sets(u, v);

            // make frequency array for the leaders
            unordered_map < int, int >  same_component;
            for(auto& u : nodes)
                same_component[dsu.find_leader(u)]++;

            // add the good paths for each group leader
            for(auto& [leader, cnt] : same_component)
                good_paths += cnt * (cnt - 1) / 2;
        }

        // number of good paths
        return good_paths;
    }
};
