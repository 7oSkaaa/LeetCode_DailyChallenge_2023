// Author: Mina Magdy

// create a structure for disjoint set union data structure
struct DSU {
    int cc; // number of connected components
    vector<int> p, s; // vector for storing parent and size of connected components
    DSU(int n) { // constructor
        cc = n; // initially number of connected components are equal to the number of vertices
        p.resize(n + 1); // resize vector to hold parent of each vertex
        iota(p.begin(), p.end(), 0); // initialize the parent vector with indices
        s.assign(n + 1, 1); // initially all connected components have size 1
    }
    int find(int x) { // function to find the parent of a vertex and do path compression
        return (x == p[x] ? x : p[x] = find(p[x]));
    }
    bool same_group(int u, int v) { // function to check if two vertices are in the same group or not
        return find(u) == find(v);
    }
    void join(int u, int v) { // function to join two vertices into a single group
        int r1 = find(u), r2 = find(v);
        if (r1 == r2) // already in the same group
            return;
        if (s[r1] < s[r2]) // make smaller group as child of the larger group
            swap(r1, r2);
        p[r2] = r1; // make parent of r2 as r1
        s[r1] += s[r2]; // add size of r2 to size of r1
        cc--; // decrease the number of connected components
    }
};

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), greater<>()); // sort the edges in descending order of type
    DSU dsu1(n), dsu2(n); // create two instances of disjoint set union data structure
    int cnt = 0; // count of number of edges added to graph
    for (auto& v : edges) { // iterate through all edges
        int t = 0; // type of edge added to graph
        if (v[0] & 1) { // check if edge is of type 1 or 3
            if (dsu1.same_group(v[1], v[2])) // if vertices are already in the same group, skip
                continue;
            dsu1.join(v[1], v[2]); // join the vertices and decrease number of connected components
            t |= 1; // set the type of edge
        }
        if (v[0] & 2) { // check if edge is of type 2 or 3
            if (dsu2.same_group(v[1], v[2])) // if vertices are already in the same group, skip
                continue;
            dsu2.join(v[1], v[2]); // join the vertices and decrease number of connected components
            t |= 2; // set the type of edge
        }
        cnt += t > 0; // if an edge is added to the graph, increase the count
    }
    if (dsu1.cc != 1 || dsu2.cc != 1) // if the graph is not connected, return -1
        return -1;
    return edges.size() - cnt; // return the number of edges removed from the graph
}
