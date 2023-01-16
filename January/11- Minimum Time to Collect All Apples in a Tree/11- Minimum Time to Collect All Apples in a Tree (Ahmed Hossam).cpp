// Author: Ahmed Hossam

class Solution {
public:

    // global variables for all functions
    vector < vector < int > > adj;
    vector < bool > hasApple;
    vector < int > apples;

    int dfs(int u, int p){
        int time = 0;
        for(auto& v : adj[u]){
            // the child subtree is empty of apples will skip it
            if(v == p || !apples[v]) continue;
            
            // calculate the time of the children
            time += 1 + dfs(v, u);
        }

        // the time is required for this subtree
        return time;
    }

    // get the number of apples in each subtree
    void get_apples(int u, int p){
        apples[u] = hasApple[u];
        for(auto& v : adj[u]){
            // to avoid cycling
            if(v == p) continue;
            // update the current subtree with it's children
            get_apples(v, u);
            apples[u] += apples[v];
        }
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // assign and define the global variables
        this -> hasApple = hasApple;
        adj = vector < vector < int > > (n);
        apples = vector < int > (n);

        // make adjacency list of the tree
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // get number of apples in each subtree
        get_apples(0, -1);

        // the minimum time required
        return 2 * dfs(0, -1);
    }
};
