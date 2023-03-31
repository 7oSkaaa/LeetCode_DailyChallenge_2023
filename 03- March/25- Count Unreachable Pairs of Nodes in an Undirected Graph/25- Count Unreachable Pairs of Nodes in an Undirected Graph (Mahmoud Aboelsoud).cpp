// Author: Mahmoud Aboelsoud


// we need to find the number of pairs of nodes that are not connected by an edge
// this means that we need to find for each node the number of nodes that are not in the same connected component as it
// cause as we know all the nodes in the same connected component are connected to each other
// so can use DSU to find the number of nodes in each connected component
// and the number of pairs of nodes that are not connected by an edge is the number of nodes in the connected component * the number of nodes that are not in the same connected component


class Solution {
public:
    // DSU
    // vectors to store the parent of each node and the size of each connected component
    vector<long long>parent, set_size;

    // function to find the parent of a node
    int find_set(int x){
        if(x == parent[x]) return x;

        return parent[x] = find_set(parent[x]);
    }

    // function to union the sets of two nodes
    void union_sets(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(set_size[a] < set_size[b])
                swap(a, b);
            parent[b] = a;
            set_size[a] += set_size[b];
        }
    }


    long long countPairs(int n, vector<vector<int>>& edges) {
        // initialize the DSU
        parent.assign(n, 0);
        set_size.assign(n, 1);

        // initialize the parent of each node to be itself
        for(int i = 0; i < n; i++)
            parent[i] = i;

        // union the sets of each edge
        for(auto&i: edges)
            union_sets(i[0], i[1]);

        // get the leaders of each connected component
        unordered_set<int> leaders;
        for(int i = 0; i < n ; i++)
            leaders.emplace(find_set(i));


        // get the number of pairs of nodes that are not connected by an edge
        long long ans = 0;
        for(auto&i: leaders)
            // the number of pairs of nodes that are not connected by an edge is the number of nodes in the connected component * the number of nodes that are not in the same connected component
            ans += set_size[i] * (n - set_size[i]);
        
        
        // return the number of pairs of nodes that are not connected by an edge / 2 because each pair is counted twice
        return ans / 2;
    }
};
