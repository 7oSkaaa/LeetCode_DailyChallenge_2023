//Author: Sara Hamza
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges)  {

        //build adj list to be in the form of:
        // 0: {1, red}, {2, blue}] ,...
        // 1: {3, red},...

        //color with be represented as boolean: red = 0, blue = 1
        vector<vector<pair<int, bool>>>adj(n);

        for(auto edge : redEdges){
            adj[edge[0]].push_back({edge[1], 0});
        }
        for(auto edge : blueEdges){
            adj[edge[0]].push_back({edge[1], 1});
        }

        //BFS from one src (0) to get shortest paths to all nodes
        //note: despite the colors is being for the edges, it will be for the nodes instead
        //ex edge from 0 to 1 is red => then node 1 is red
        //try making alternating nodes!!
        //to make all possible outcomes => node "0" only will take a different num which is 2 (neither red nor blue)

        //answer vector
        vector<int>dist(n);

        //queue of {node , its color}
        queue <pair<int, int>> q;
        //memset it with OO to be able to minimize
        for(int i = 0; i<n; ++i)
            dist[i] = INT_MAX;

        //init of BFS with node 0 and its unknown color
        q.push({0, 2});
        dist[0] = 0;
        int distance = 0;
        int vis[101][3] = {0}; //to make sure each node is visted at most 2 times (one if its color is considered red and one for blue)

        //BFS
        while(!q.empty()){
            //for each level :
            int sz = q.size();
            distance++;
            while(sz--){
                //get the node and its color out of the queue
                auto [node, color] = q.front();
                q.pop();

                //to prevent cycles
                if(vis[node][color])
                    continue;
                vis[node][color] = 1;

                //loop all of its childern ( that the node is directed to)
                for(auto nextNode : adj[node]){
                    auto [child, child_color] = nextNode;
                    //check for color matching =>invalid path
                    if(child_color == color) continue;

                    //check if it is visited once? => don't update distance (shortest is kept)
                    //if not => update it
                    //(becasue each node is visited at most for 2 times)
                    if(dist[child] == INT_MAX)
                        dist[child] = distance;

                    //push it to try all possible paths and vis array will prevent cycles
                    q.push({child, child_color});
                }

            }
        }
        //mapping all paths that can't be made to be -1 instead of OO
        for(int i = 0; i < n; ++i){
            if(dist[i] == INT_MAX)
                dist[i] = -1;
        }
        return dist;

    }
};
