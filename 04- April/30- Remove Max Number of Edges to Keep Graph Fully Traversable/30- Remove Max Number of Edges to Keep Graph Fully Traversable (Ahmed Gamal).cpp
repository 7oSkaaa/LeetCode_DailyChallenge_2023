// Author: Ahmed Gamal

// for this problem we will use DSU to check if the graph is connected or not
// and since there is 3 types of edges we will use 2 DSU one for Alice and one for Bob
// if we think about it, we will find that type 3 edges is always important as it will connect two nodes in both DSU, and if we removed it, we will need to add 2 edges to connect the same nodes in both graphs
// so we will start by adding all type 3 edges, and then we will try to use type 1 and type 2 edges to connect the nodes in both graphs
// if we have k components in Alice graph, we will need k - 1 edges to connect them, and the same for Bob
// the rest of edges will be useless and we will need to remove them


// DSU implementation
struct dsu {
    // n: number of connected components
    int n;

    // p: parent of each node
    // rank: rank of each node
    vector<int> p, rank;

    explicit dsu(int size) {
        // initially each node is parent of itself
        // and there is no edges
        // so number of connected components = size
        n = size;
        p.resize(size + 1);
        rank.assign(size + 1, 0);
        iota(p.begin(), p.end(), 0);
    }

    // get the parent of node x
    int get(int x) {
        return p[x] = x == p[x] ? x : get(p[x]);
    }

    // join two nodes u and v
    void join(int u, int v) {
        // get the parent of each node
        u = get(u), v = get(v);

        // if they are already in the same component, do nothing
        if(u == v)
            return;

        // decrease the number of connected components and merge between them
        n--;

        if(rank[u] == rank[v])
            rank[u]++;

        if(rank[u] > rank[v])
            p[v] = u;
        else
            p[u] = v;
    }

    // assign new size to the DSU (useful in some problems)
    void assign(int size) {
        p.resize(size + 1);
        rank.assign(size + 1, 0);
        iota(p.begin(), p.end(), 0);
        n = size;
    }

    // check if the graph is connected or not (number of connected components = 1)
    bool is_connected() {
        return n == 1;
    }

    // get the number of connected components
    int cc_count() {
        return n;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // two DSU one for Alice and one for Bob
        dsu a(n), b(n);

        // cnt[i] = number of edges of type i
        array<int, 4> cnt{};

        // add all edges to the graphs
        for(auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];

            // count the number of edges of each type
            cnt[type]++;

            // add type 3 edges to both graphs (they are always important)
            // and add type 1 and type 2 edges to the corresponding graph
            if(type == 1 or type == 3)
                a.join(u, v);
            if(type == 2 or type == 3)
                b.join(u, v);
        }

        // if one of the graphs is not connected, the answer is -1
        if(not(a.is_connected() and b.is_connected()))
            return -1;
        
        // reset the DSU to use it again
        a.assign(n);
        b.assign(n);

        // add type 3 edges to both graphs
        int ans = 0;
        for(auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];

            if(type == 3) {
                // if the two nodes are already connected in both graphs, this edge is useless
                if(a.get(u) == a.get(v)) {
                    ans++;
                    continue;
                }

                // connect the two nodes in both graphs
                a.join(u, v);
                b.join(u, v);
            }
        }

        // add the number of useless edges from both graphs
        ans += cnt[1] - a.cc_count() + 1;
        ans += cnt[2] - b.cc_count() + 1;

        return ans;
    }
};