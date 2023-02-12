// Author: Ahmed Hossam

class Solution {
public:
    
    #define ceil(n, m) (((n) + (m) - 1) / (m))

    vector < vector < int > > adj;
    vector < int > child;

    long long dfs(int u, int p, int seats){
        long long fuel = 0;
        for(auto& v : adj[u]){
            // to avoid cycling
            if(v == p) continue;

            // dfs on the child of u to get the size of each subtree of them and the answers also
            fuel += dfs(v, u, seats);
            
            // add the subtree size of v to subtree of u
            child[u] += child[v];
        }

        // the fuel used will be the sum of that used in my children and ceil the seats of current subtree
        if(u != 0)
            fuel += ceil(child[u], seats);
        
        return fuel;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        adj = vector < vector < int > > (n);
        child = vector < int > (n, 1);

        // make adjacency list for all nodes
        for(auto& v : roads)
            adj[v[0]].push_back(v[1]), adj[v[1]].push_back(v[0]);

        // dfs from root to get_answers;
        return dfs(0, -1, seats);
    }
};
