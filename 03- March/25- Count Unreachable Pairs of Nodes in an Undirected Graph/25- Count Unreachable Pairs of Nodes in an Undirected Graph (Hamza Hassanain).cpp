// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;

/*
       Approach:
            Assume all nodes are not connected then we have nC2 or ( n*(n-1)/2 ) of unreachable nodes
            then run a dfs and calcualte the number of connected nodes in each connected component
            then subtract the number of reachable pairs form our assumed value
*/
class Solution
{
public:
    vector<long long> nodesInEachComponent;
    vector<vector<int>> adj;
    static const int N = 1e5;
    bool vis[N]{};
    void dfs(int node, int &curNodesCount)
    {
        if (vis[node])
            return;

        vis[node] = true, curNodesCount++;
        for (auto child : adj[node])
            dfs(child, curNodesCount);
    }
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        adj = vector<vector<int>>(n);
        for (auto edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        for (int node = 0; node < n; node++)
        {
            if (vis[node])
                continue;
            int curNodesCount = 0;
            dfs(node, curNodesCount);
            nodesInEachComponent.push_back(curNodesCount);
        }
        long long og_n = n;
        long long res = og_n * (og_n - 1) / 2;
        for (long long num : nodesInEachComponent)
            res -= num * (num - 1) / 2;

        return res;
    }
};