// Author: Mahmoud Aboelsoud

// we need to find the number of edges that we need to reverse to make all paths lead to the city zero
// so we will build an undirected graph and then we will start dfs from the city zero 
// ans count the number of edges that we need to reverse to make the path lead to the city zero
// if the edge is in the connections array then we need to reverse it
// as if we have edge from 0 to x and then from x to y then we need to reverse both edges to make the path lead to the city zero
// but if we have edge from 0 to x and then from y to x then we need to reverse only the edge from 0 to x to make the path lead to the city zero

class Solution {
public:
    // set to store the edges in the connections array
    set<pair<int,int>> cons;
    
    // adjacency list to store the graph
    vector<vector<int>> adj;
    
    // dfs function to find the number of edges that we need to reverse to make all paths lead to the city zero
    int dfs(int u, int par){
        // ans to store the number of edges that we need to reverse to make the path lead to the city zero
        int ans = 0;

        // loop on the adjacency list of the current node
        for(auto&i: adj[u]){
            // if the current node is the parent of the current node then continue
            if(i == par) continue;
            // if the edge is in the connections array then we need to reverse it
            // and then we will call dfs on the current node 
            ans += cons.count({u, i}) + dfs(i, u);
        }

        // return the number of edges to reverse to make the path lead to the city zero from the current node
        return ans;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // build the graph
        adj.assign(n, vector<int> ());
        for(auto&i: connections){
            // get the current edge
            int u = i[0], v = i[1];
            // add undirected edge to the graph
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
            // add the edge to the set
            cons.emplace(u, v);
        }

        // call dfs from the city zero
        return dfs(0, -1);
    }
};
