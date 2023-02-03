// Author: Noura Algohary
class Solution {
public:
// A Deep First Search function which visits all children of a node before going back 
    int dfs(int node, vector<vector<int>>& edges, vector<bool>& hasApple, vector<bool>& visited)
    {
        int total_time = 0, subtree_time = 0;

        for (auto edge : edges[node])
        {
            if(!visited[edge])
            {
                visited[edge] = true;
                subtree_time = dfs(edge, edges, hasApple, visited);

                // if the node has apples or its subtree, visit child and add the subtree_time to total_time
                if(subtree_time || hasApple[edge])
                {
                    total_time += subtree_time + 2;
                }
            }
        }

        return total_time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);  //adjecency matrix 
        vector<bool> visited(n, false);
        
        for(auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        visited[0] = true;
        return dfs(0, adj, hasApple, visited);
    }
};