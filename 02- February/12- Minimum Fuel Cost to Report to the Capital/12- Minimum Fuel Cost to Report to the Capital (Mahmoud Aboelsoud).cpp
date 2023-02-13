// Author: Mahmoud Aboelsoud

class Solution {
public:
    // the idea is to find the minimum number of cars we need from each node to it's parent
    // so at each node we redistribute the representatives in the cars 

    // the number of seats in each car
    int seats;
    // adj list
    vector<vector<int>> adj;
    // the minumum fuel cost 
    long long ans;

    // we traverse the tree and find the number of representatives in each subtree
    int dfs(int node, int par){
        // the number of representatives in the subtree
        int tot = 1;
        // we find the number of representatives in each subtree
        for(auto&i: adj[node]){
            // if the node is the parent we skip it
            if(i == par) continue;
            // we find the number of representatives in the subtree
            int x = dfs(i, node);

            // we add the number of cars we need to transport the representatives
            // to traverse from the child to parent you just need 1 liter of fuel
            // so you just need the number of cars to caculate the fuel cost from child to parent
            ans += ceil(double(x)/seats);

            // we add the number of representatives in the subtree
            tot += x;
        }

        // we return the number of representatives in the subtree
        return tot;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        // we set the number of seats in each car
        this -> seats = seats;
        // we set the number of nodes
        int n = roads.size() + 1;
        // we set the adj list
        adj.assign(n, vector<int> ());

        // we build the adj list
        for(auto&i: roads)
            adj[i[0]].push_back(i[1]), adj[i[1]].push_back(i[0]);

        // we set the minimum fuel cost to 0
        ans = 0;
        // we start traversing the tree from the capital
        dfs(0, -1);

        // we return the minimum fuel cost
        return ans;
    }
};
