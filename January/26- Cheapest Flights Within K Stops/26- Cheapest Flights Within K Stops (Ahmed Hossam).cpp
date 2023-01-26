// Author: Ahmed Hossam

class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector < vector < pair < int, int > > > adj(n);

        // make edge between u and v with weight w
        for(auto& flight : flights)
            adj[flight[0]].push_back({flight[1], flight[2]});

        // the minimum dist for each node
        vector < int > dist(n, 1e9);

        // create a queue for the bfs technique and add source to it
        queue < pair < int, int > > bfs;
        bfs.push({src, 0});
        dist[src] = 0;

        // loop over k stops and for iteration loop over the current level
        k++;
        while(k--){

            // iterate over the current level
            int sz = bfs.size();
            while(sz--){
                auto [u, cost] = bfs.front();
                bfs.pop();

                // check if the next node you can reach it with min cost and in the range of [0 to k] stop
                for(auto& [v, w] : adj[u]){
                    if(dist[v] > cost + w)
                        dist[v] = cost + w, bfs.push({v, cost + w});
                }
            }
        }

        // if the dst node can't be reached
        if(dist[dst] == int(1e9))
            dist[dst] = -1;

        // return the minimum distance 
        return dist[dst];
    }
};
