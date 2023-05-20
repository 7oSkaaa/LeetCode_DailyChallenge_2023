// Author: Ahmed Gamal

// for this problem, we will represent each variable as a node in a graph, and each equation as an edge between two nodes
// each equation will have a weight, which is the value of the equation (a / b = 2, a is the source node, b is the target node, and 2 is the weight)
// also, we will add the inverse of each equation (b / a = 1 / 2, b is the source node, a is the target node, and 1 / 2 is the weight)

// after that, we will use dfs to connect each node with its group to find if two nodes are connected or not
// if two nodes in the query are not connected, then the answer is -1.0 (because we can't substitute one variable with the other)
// if two nodes in the query are connected, then we will use dfs to find the value of the equation between them
// to find the value of the equation, we will multiply the weight of each edge between the two nodes along the path between them using dfs

class Solution {
    // adj: adjacency list to represent the graph
    // vis: array to keep track of the visited nodes
    map<string, vector<pair<string, double>>> adj;
    map<string, bool> vis;
    
    void dfs(string& src, string& target, double& ret, double curr) {
        // if we found the target, then return the current value
        if(src == target) {
            return void(ret = curr);
        }

        // mark the current node as visited
        vis[src] = true;
        for(auto& [nxt, wt] : adj[src]) {
            // if the node is already visited, then skip it
            if(vis[nxt]) {
                continue;
            }
            dfs(nxt, target, ret, curr * wt);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build the graph
        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            adj[u].emplace_back(v, values[i]);
            adj[v].emplace_back(u, 1 / values[i]);
        }

        // ans: vector to store the answer of each query
        vector<double> ans;
        
        for(auto& q : queries) {
            double ret = -1.0;

            // if one of the variables doesn't exist, then the answer is -1.0
            if(adj.find(q[0]) == adj.end()) {
                ans.emplace_back(ret);
                continue;
            }

            // find the value of the equation between the two variables
            vis.clear();
            dfs(q[0], q[1], ret, 1);
            ans.emplace_back(ret);
        }

        return ans;
    }
};