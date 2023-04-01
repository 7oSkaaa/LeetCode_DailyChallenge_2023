// Author: Ahmed Gamal

// for this problem, we want to count the number of pairs of nodes that are not connected in the graph
// two nodes are not connected if there is no path between them, and since the graph is undirected, all the nodes in the same connected component are connected
// so, any pair of nodes that are not in the same connected component are not connected
// if we have two connected components with sizes x and y, then the number of pairs of nodes that are not connected is x * y
// why? because we can choose any node from the first connected component and any node from the second connected component and there is no path between them
// so, if we have three connected components with sizes x, y and z, then the number of pairs of nodes that are not connected is x * y + x * z + y * z
// and so on
// we can refomat this equation to get the number of pairs of nodes that are not connected in the graph
// we can say the above equation is equal to x * (y + z + ...) + y * (z + ...) + ...
// to find the connected components, we can use dsu and modify the join function to count the size of each connected component

struct dsu {
    vector<int> p, rank, group_size;

    explicit dsu(int size) {
        p.resize(size + 1);
        rank.resize(size + 1);
        group_size.assign(size + 1, 1);

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

        if(rank[u] > rank[v]) { 
            // if u is the parent of v, then the size of the connected component that contains u will increase by the size of the connected component that contains v
            p[v] = u;
            group_size[u] += group_size[v];
        } else {
            // if v is the parent of u, then the size of the connected component that contains v will increase by the size of the connected component that contains u
            p[u] = v;
            group_size[v] += group_size[u];
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // d: the dsu data structure
        dsu d(n);
        // leads: the leaders of the connected components (to avoid counting the same connected component twice)
        set<int> leads;

        // join the nodes in the same connected component
        for(auto& ed : edges) {
            d.join(ed[0], ed[1]);
        }

        // find the leaders of the connected components
        for(int i = 0; i < n; i++) {
            leads.emplace(d.get(i));
        }

        // ans: the number of pairs of nodes that are not connected
        // sum: the sum of the sizes of the connected components
        long long ans = 0, sum = 0;
        for(auto& i : leads) {
            // size: the size of the connected component
            long long size = d.group_size[i];

            // add the number of pairs of nodes that are not connected in the current connected component to the answer
            // the number of pairs of nodes that are not connected in the current connected component is size * (previous sum of the sizes of the connected components)
            ans += sum * size;
            
            // add the size of the current connected component to the sum
            sum += size;
        }

        return ans;
    }
};