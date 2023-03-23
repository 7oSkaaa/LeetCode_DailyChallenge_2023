// Author: Mahmoud Aboelsoud


// in this problem you need to find the number of operations to make the network connected
// the operation is to remove an edge from the network and reconnect it again between any other two nodes
// so you need to find if you have enough edges to connect all the nodes in the network
// if you have enough edges you can connect all the nodes in the network and the number of operations is the number of components - 1
// if you don't have enough edges you can't connect all the nodes in the network and the answer is -1

// we can use DSU to find the number of components in the network and count the number of edges in each component
// to connect all the nodes in a component you need at least the number of nodes in the component - 1 edges
// so the number of extra edges (that can be taken to connect any other two nodes) is the number of edges in each component - the number of nodes in each component + 1
// if the number of extra edges is greater than or equal to the number of components - 1 then you can connect all the nodes in the network
// and the number of operations is the number of components - 1
// otherwise you can't connect all the nodes in the network and the answer is -1

class Solution {
public:
    // DSU code
    vector<int> parent, set_size, edges;

    // find the leader of the set that the node v belongs to
    int find_set(int v){
        if(v == parent[v]) return v;

        return parent[v] = find_set(parent[v]);
    }

    // union the sets that the nodes a and b belong to
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;
            set_size[a] += set_size[b];
            // add the number of edges in the set b to the set a
            edges[a] += edges[b];
        }
        // add 1 to the number of edges in the set a
        edges[a]++;
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        // assign the size of the parent, set_size and edges vectors to n
        parent.assign(n, 0);
        set_size.assign(n, 1);
        edges.assign(n, 0);

        // initialize the parent vector with the index of each node
        for(int i = 0; i < n; i++)
            parent[i] = i;

        // loop on the connections vector and union the sets that the nodes in each connection belong to
        for(auto&i: connections)
            union_sets(i[0], i[1]);

        // find the number of components in the network and find the leaders of each component
        unordered_set<int> leaders;
        for(int i = 0; i < n; i++)
            leaders.insert(find_set(i));

        // find the number of extra edges
        int extra_edges = 0, comps = leaders.size();

        for(auto&i: leaders)
            // the extra edges in each component is the number of edges in the component - the number of nodes in the component + 1
            extra_edges += edges[i] - set_size[i] + 1;

        // if the number of extra edges is greater than or equal to the number of components - 1 then you can connect all the nodes in the network
        // and the number of operations is the number of components - 1
        // otherwise you can't connect all the nodes in the network and the answer is -1
        return (extra_edges >= comps - 1 ? comps - 1 : -1);
    }
};
