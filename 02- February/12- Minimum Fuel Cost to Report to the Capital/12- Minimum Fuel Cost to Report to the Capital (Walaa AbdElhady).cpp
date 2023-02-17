// Author: Walaa AbdElhady

class Solution {
private:
    // the minumum fuel cost 
    long long fuel;
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // make adj matrix
        vector<vector<int>> adj(roads.size() + 1);
        for (auto& node : roads) {
            adj[node[0]].push_back(node[1]);
            adj[node[1]].push_back(node[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
    // traverse the tree and find the number of representatives in each subtree
    long long dfs(int root, int par, vector<vector<int>>& adj, int& seats) {
        int people = 1;
        for (auto& ch : adj[root]) {
            if (ch != par) {
                people += dfs(ch, root, adj, seats);
            }
        }
        
        if (root > 0) {
            // the fuel used will be the sum of people and divide it by no.seats
            if (people % seats == 0)fuel += people / seats;
            else fuel += people / seats + 1;
        }
        return people;
    }
};