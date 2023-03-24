// Author: Ahmed Gamal

// this problem is asking us to find the minimum score of a path between the first city and the last city
// and it guarantees that there is a path between the first city and the last city
// if the graph is connected, then we can find the minimum score of a path between the first city and the last city by finding the minimum weight in the vector of roads
// but the graph is not guaranteed to be connected, so we can't use the previous approach
// but we can use the same idea, how?
// if we are in a connected component (subgraph), the other connected components are not reachable from this connected component
// so we can remove all the edges that are not in the same connected component as the last city (or the first city as they are the same)
// then we can find the minimum weight in the roads that belong to the to the same connected component as the last city

// why is this approach correct? what guarantees that the minimum weight in the roads that belong to the to the same connected component as the last city is on the path between the first city and the last city?
// since the graph is undirected, we can go from any city to any other city in the same connected component
// and notice that the problem asks for a path and not a simple path, so we can go through the same edge more than once
// and this makes it possible to consider a path that goes through the minimum weight edge and then goes to the final city


// dsu: disjoint set union data structure to find the connected components
struct dsu {
    vector<int> p, rank;

    explicit dsu(int size) {
        p.resize(size + 1);
        rank.resize(size + 1);

        iota(p.begin(), p.end(), 0);
    }

    int get(int x) {
        return p[x] = x == p[x] ? x : get(p[x]);
    }

    void join(int u, int v) {
        u = get(u), v = get(v);

        if(u == v)
            return;

        if(rank[u] == rank[v])
            rank[u]++;

        if(rank[u] > rank[v])
            p[v] = u;
        else
            p[u] = v;
    }
};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // ans: the minimum score of a path between the first city and the last city
        int ans = INT_MAX;

        // create a dsu to find the connected components
        dsu d(n);

        // join the cities in the same connected component
        for(auto& ed : roads) {
            d.join(ed[0], ed[1]);
        }

        // find the minimum weight in the roads that belong to the to the same connected component as the last city
        for(auto& ed : roads) {
            if(d.get(ed[0]) == d.get(n)) {
                ans = min(ans, ed[2]);
            }
        }

        return ans;
    }
};