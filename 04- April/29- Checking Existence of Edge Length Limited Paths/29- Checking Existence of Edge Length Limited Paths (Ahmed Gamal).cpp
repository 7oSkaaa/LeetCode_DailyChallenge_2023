// Author: Ahmed Gamal

// for this problem we will use DSU to check if the graph is connected or not
// we want to answer a lot of queries, each query is to check if there is a path between two nodes with weights less than a limit
// and since the queries can be answered offline, we will sort the queries by their limit and for each query we will add all edges with weight less than the limit
// and then we will check if the two nodes are in the same component or not using DSU
// and since we will add edges in sorted order, we will use two pointers to add the edges


// DSU implementation
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
    // query class to sort the queries by their limit and to store the index of each query
    struct query {
        int limit, u, v, idx;
        query(int limit = 0, int u = 0, int v = 0, int idx = 0) {
            this -> limit = limit;
            this -> u = u;
            this -> v = v;
            this -> idx = idx;
        }
        bool operator<(const query& other) {
            return limit < other.limit;
        }
    };
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // sorted: sorted queries
        vector<query> sorted;

        // add the index of each query to sort them later
        for(int i = 0; i < queries.size(); i++) {
            sorted.emplace_back(queries[i][2], queries[i][0], queries[i][1], i);
        }

        // sort the queries by their limit
        sort(sorted.begin(), sorted.end());

        // sort the edges by their weight
        sort(edgeList.begin(), edgeList.end(), [&](vector<int>& a, vector<int>& b) -> bool {
            return a[2] < b[2];
        });

        // j: pointer to the current edge
        // d: DSU for the current graph
        // ans: answer for each query
        int j = 0;
        dsu d(n);
        vector<bool> ans(sorted.size());

        // iterate over the queries
        for(auto& q : sorted) {
            // add all edges with weight less than the current limit
            while(j < edgeList.size() and edgeList[j][2] < q.limit) {
                d.join(edgeList[j][0], edgeList[j][1]);
                j++;
            }

            // the answer for the current query is true if the two nodes are in the same component and false otherwise
            ans[q.idx] = d.get(q.u) == d.get(q.v);
        }

        return ans;
    }
};