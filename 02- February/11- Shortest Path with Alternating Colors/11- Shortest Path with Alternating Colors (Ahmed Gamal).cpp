// Author: Ahmed Gamal


class Solution {
public:

    // for this problem we want for each node to find the shortest path to reach it from node 0 with red color and blue color (with no to two consecutive edges with the same color)
    // for each node during bfs we will have two states (red and blue) which shows that the last edge we used to reach this node is red or blue
    // so we will have two distances for each node (one for red and one for blue)
    // we will use a 2d array to store the distances (dist[node][color])
    // but for node 0 (the source) we don't need to use the color because we can reach it from node 0 with any color
    // And because at each step we only add to the queue the nodes that we haven't visited before if it has an edge with the opposite color of the last edge we used to reach it
    // we need to add the source twice to the queue (assuming that the first edge we used to reach it is red and the second is blue) to make sure that we will reach all the nodes    
    

    // state: is the state of the current node (the last edge we used to reach it) at each step
    struct state {
        int node, color;

        state(){
            node = color = 0;
        }

        state(int node, int color){
            this -> node = node;
            this -> color = color;
        }
    };

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // adj: is the adjacency list of the graph
        vector<state> adj[101];

        // q: is the queue that will be used in bfs
        queue<state> q;

        // dist: is the distance array
        vector<vector<int>> dist(n, vector<int>(2, -1));

        // add_edge: is a lambda function to add an edge to the graph with the given color
        auto add_edge = [&](vector<int>& edge, int color){
            int u = edge.front(), v = edge.back();
            adj[u].emplace_back(v, color);
        };

        // add all the edges to the graph
        for(auto& edge : redEdges){
            add_edge(edge,  1);
        }
        for(auto& edge : blueEdges){
            add_edge(edge, 0);
        }


        // add the source to the queue twice (assuming that the first edge we used to reach it is red and the second is blue)
        q.emplace(0, 0);
        q.emplace(0, 1);

        // dist[0][0] = dist[0][1] = 0; // we don't need this because we will reach the source with any color
        dist[0] = {0, 0};
        
        // bfs
        while(not q.empty()){
            int size = int(q.size());
            while(size--){
                auto [node, color] = q.front();
                q.pop();

                for(auto& [nxt, nxt_color] : adj[node]){

                    // if the next node has an edge with the opposite color of the last edge we used to reach it and we haven't visited it before
                    if(nxt_color != color and dist[nxt][nxt_color] == -1){
                        dist[nxt][nxt_color] = dist[node][color] + 1;
                        q.emplace(nxt, nxt_color);
                    }
                }
            }
        }

        // for each node, we want to return one number which is the minimum between the shortest path to reach it with red color and the shortest path to reach it with blue color
        // if the node is not reachable with any color we will return -1
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++){
            // a: the shortest path to reach node i with the last edge blue
            // b: the shortest path to reach node i with the last edge red
            int a = dist[i][0], b = dist[i][1];

            // if the node is reachable with any color
            if(a != -1 or b != -1){
                // we will take the minimum between a and b, so if one of them is -1 we will take the other one (which is not -1)
                // to do this without if statements we will replace -1 with INT_MAX and then take the minimum

                if(a == -1)
                    a = INT_MAX;
                if(b == -1)
                    b = INT_MAX;
                    
                ans[i] = min(a, b);
            }
        }

        return ans;
    }
};