// author : Omar Sanad

// DSU Structure
template < typename T = int > struct DSU {
    vector < T > par, gr_sz;
    T groups;

    // DSU constructor
    DSU(int numNodes) {
        groups = numNodes;
        gr_sz.assign(numNodes + 1, 1), par.resize(numNodes + 1);
        for(int i = 1; i <= numNodes; i++)  par[i] = i;
    }
    
    // operator = , to assign one dsu to another
    DSU operator = (DSU& other) {
        par = other.par;
        gr_sz = other.gr_sz;
        groups = other.groups;
        return *this;
    }

    T getRoot(int node) {return par[node] = (par[node] == node ? node : getRoot(par[node]));}
    T get_size(int node) {return gr_sz[getRoot(node)];}
    bool SameGr(int u, int v){return getRoot(u) == getRoot(v);}

    void combine(int a, int b) {
        int root_of_a = getRoot(a), root_of_b = getRoot(b);
        if(root_of_a == root_of_b) return;  // They are already in the same group
        if(gr_sz[root_of_a] < gr_sz[root_of_b]) swap(root_of_a, root_of_b);
        gr_sz[root_of_a] += gr_sz[root_of_b], par[root_of_b] = root_of_a;
        groups--;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {

        // Declare the dsu that has the paths that both Alice and Bob can use
        DSU du(n);

        // The number of used edges
        int ans = 0;

        // use all edges of type 3 (both Alice and Bob can use), (the ones you need only)
        for (auto &e : edges)
            if (e.front() == 3 and not du.SameGr(e[1], e[2]))
                ans++, du.combine(e[1], e[2]);
        

        // Declare another two DSUs, one for Alice and the other one for Bob.
        DSU Alice = du, Bob = du;
        
        // use the edges you need in the other two types
        for (auto &e : edges)
            if (e[0] == 1) { // Alice
                if (not Alice.SameGr(e[1], e[2]))
                    ans++, Alice.combine(e[1], e[2]);
            }
            else if (e[0] == 2) { // Bob
                if (not Bob.SameGr(e[1], e[2]))
                    ans++, Bob.combine(e[1], e[2]);
            }

        // if Both Alice and Bob can fully traverse the graph
        // return the number of deleted edges.
        return Alice.groups == 1 and Bob.groups == 1 ? edges.size() - ans : -1;
    }
};
