// Author: Ahmed Gamal

// for this problem, we will represent each variable as a node in a graph, and each equation as an edge between two nodes
// each equation will have a weight, which is the value of the equation (a / b = 2, a is the source node, b is the target node, and 2 is the weight)
// also, we will add the inverse of each equation (b / a = 1 / 2, b is the source node, a is the target node, and 1 / 2 is the weight)

// after that, we will use union find to connect each node with its group to find if two nodes are connected or not
// if two nodes in the query are not connected, then the answer is -1.0 (because we can't substitute one variable with the other)
// if two nodes in the query are connected, then we will use dfs to find the value of the equation between them
// to find the value of the equation, we will multiply the weight of each edge between the two nodes along the path between them using dfs

class Solution {
    // p: parent of each node (union find)
    // rank: rank of each node (union find)
    // adj: adjacency list of the graph
    // vis: visited array for dfs
    map<string, string> p;
    map<string, int> rank;
    map<string, vector<pair<string, double>>> adj;
    map<string, bool> vis;

    // get: returns the parent of the node (union find)
    string get(string& s) {
        return p[s] == s ? s : get(p[s]);
    }

    // join: joins two nodes (union find)
    void join(string a, string b) {
        a = get(a), b = get(b);

        if(a == b) {
            return;
        }

        if(rank[a] == rank[b]) {
            rank[a]++;
        }

        if(rank[a] > rank[b]) {
            p[b] = a;
        } else {
            p[a] = b;
        }
    }

    // connected: returns true if two nodes are connected (union find)
    bool connected(string a, string b) {
        return get(a) == get(b);
    }
    
    // dfs: dfs to find the value of the equation between two nodes
    void dfs(string& src, string& target, double& ret, double curr) {
        if(src == target) {
            return void(ret = curr);
        }

        // mark the node as visited
        vis[src] = true;

        for(auto& [nxt, wt] : adj[src]) {
            // if the node is visited, then skip it
            if(vis[nxt]) {
                continue;
            }
            // if the node is not visited, then call dfs on it with the new value of the equation
            dfs(nxt, target, ret, curr * wt);
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // initialize the parent and rank of each node
        for(auto& eq : equations) {
            string u = eq[0], v = eq[1];
            rank[u] = rank[v] = 1;
            p[u] = u;
            p[v] = v;
        }

        // build the graph and connect the nodes
        for(int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            join(u, v);
            
            adj[u].emplace_back(v, values[i]);
            adj[v].emplace_back(u, 1 / values[i]);
        }

        // ans: answer array
        vector<double> ans;
        
        for(auto& q : queries) {
            // check if the answer for this query can be determined or not
            bool ok = true;

            // if one of the variables didn't appear in any equation, then the answer is -1.0
            ok &= p.find(q[0]) != p.end();
            ok &= p.find(q[1]) != p.end();

            // if both variables appeared in equations, then check if they are connected or not
            if(ok)
                ok &= connected(q[0], q[1]);

            // if any of the above conditions is false, then the answer is -1.0
            if(not ok) {
                ans.emplace_back(-1.0);
                continue;
            }

            // if both variables are connected, then call dfs to find the value of the equation between them
            double ret;
            vis.clear();
            dfs(q[0], q[1], ret, 1);
            ans.emplace_back(ret);
        }

        return ans;
    }
};