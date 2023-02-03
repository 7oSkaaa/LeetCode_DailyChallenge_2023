// Author: Noura Algohary
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);  //adj list of pairs [neighbour, price]

        int steps = k;

        // min cost for each node
        vector<int> min_cost(n, INT_MAX);

        // queue of source node and cost
        queue<pair<int, int>> q;
        q.push({src, 0});

        for(auto flight: flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        while(!q.empty() && steps>=0)
        {
            int q_size = q.size();
            while(q_size --)
            {
                pair<int, int> node_cost = q.front();
                q.pop();

                for(auto neighbour : adj[node_cost.first])
                {
                    int cost = node_cost.second + neighbour.second;
                    if(cost < min_cost[neighbour.first])
                    {
                        min_cost[neighbour.first] = cost;
                        q.push({neighbour.first, cost});
                    }
                }
            }
            steps--;
        }
        if(min_cost[dst]==INT_MAX)
            return -1;

        return min_cost[dst];
    }
};