// author : Omar Sanad

/* In this problem, simply they need to find the number of connected components  */

// DSU structure
template < typename T = int > struct DSU {
    vector < T > par, gr_sz;
    T groups;

    DSU(int numNodes) {
        groups = numNodes;
        gr_sz.assign(numNodes + 1, 1), par.resize(numNodes + 1);
        for(int i = 1; i <= numNodes; i++)  par[i] = i;
    }
    
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        // declare the number of elements
        int n = isConnected.size();
        
        // make a dsu with this number of elements
        DSU du(n);

        // iterate over the adj matrix, if there is a connection between two elements, then put them in the same component
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (isConnected[i][j])
                    du.combine(i + 1, j + 1); // one-based
        
        return du.groups; // number of connected component
    }
};
