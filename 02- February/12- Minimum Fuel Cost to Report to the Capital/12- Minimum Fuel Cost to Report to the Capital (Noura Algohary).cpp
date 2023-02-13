// Author: Noura Algohary
// depth first search to traverse all nodes
// node 0 does not count
class Solution {
public:
    long long fuel = 0;
    int dfs(vector<vector<int>>& adj, int root, int node, int& seats)
    {
        int reps = 1;
        
        // apply dfs for all neighbors of the node except the root
        for(auto neighbor: adj[node])
        {
            if(neighbor == root)
                continue;
            
            reps += dfs(adj, node, neighbor, seats);  // add no. of representitives to reps of the parent node
        }
        if(node != 0)
            fuel += ceil((double)reps / seats);

        return reps;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adj(roads.size()+1);

        // make adjacency matrix
        for(auto i : roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        dfs(adj, -1, 0, seats);

        return fuel;
    }
};