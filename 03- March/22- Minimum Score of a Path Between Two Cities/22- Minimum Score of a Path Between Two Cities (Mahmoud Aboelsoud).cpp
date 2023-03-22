// Author: Mahmoud Aboelsoud

class Solution {
public:
    // in this problem we need to find the minimum weighted edge in the path from node 1 to node n
    // so we can use dijkstra to find the minimum weighted edge path from node 1 to node n


    // adj list
    vector<vector<pair<int,int>>> adj;

    // dijkstra
    void dijkstra(int src, vector<int>&dist){
        // intialize dist array and the number of nodes in the graph
        int n = adj.size();
        dist.assign(n + 1, 1e9);

        // intialize the priority queue and push the source node
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({1e9, src});

        // dijkstra
        while(!pq.empty()){
            // get the node that reached with the minimum weighted edge
            int u = pq.top().second;
            // get the minimum weighted edge
            int d = pq.top().first;
            // pop the node
            pq.pop();

            // if the node is visited before, continue to the next node
            if(d != dist[u]) continue;

            // loop on the node's neighbors
            for(auto&[v, len]: adj[u]){
                // if the minimum weighted edge from the source node to the current node or the current node to the neighbor node is less than the minimum weighted edge from the source node to the neighbor node
                // update the minimum weighted edge from the source node to the neighbor node
                if(min(dist[u], len) < dist[v]){
                    // update the minimum weighted edge from the source node to the neighbor node to be the minimum weighted edge from the source node to the current node or the current node to the neighbor node
                    dist[v] = min(dist[u], len);
                    // push the neighbor node to the priority queue
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        // intialize the adj list
        adj.assign(n + 1, vector<pair<int, int>> ());
        
        // fill the adj list 
        for(auto&i: roads){
            adj[i[0]].emplace_back(i[1], i[2]);
            adj[i[1]].emplace_back(i[0], i[2]);
        }

        // intialize the dist array
        vector<int> dist;
        // call dijkstra
        dijkstra(1, dist);

        // return the minimum weighted edge from the source node to the destination node
        return dist[n];
    }
};
