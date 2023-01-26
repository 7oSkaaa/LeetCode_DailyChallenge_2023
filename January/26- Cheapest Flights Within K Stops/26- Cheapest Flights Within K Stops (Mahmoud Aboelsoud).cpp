// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the shortest path from src to dst with at most k stops
    // so our approach is to use dfs to traverse the graph and keep track of the number of stops and 
    // dp to memoize the results of the dfs at each node and number of stops that we reached it with 
    // we memoize the minimum cost of reaching the destination node from the current node with the current number of stops
    // so we can avoid re-computing the same sub-problems
    // the base case is when we reach the destination node, we return 0
    // if we reached the maximum number of stops, we return 1e9


    // adjaceny list to represent the graph with the cost of each edge
    vector<vector<pair<int,int>>> adj;
    // number of stops and destination node
    int k, dst;

    // dp[node][cnt] = minimum cost of reaching the destination node from the current node with the current number of stops
    int dp[101][101];


    // dfs to traverse the graph and keep track of the number of stops
    int dfs(int node, int cnt){
        // base case
        // if we reached the destination node, we return 0
        if(node == dst) return 0;

        // if we exceeded the maximum number of stops, we return 1e9
        if(cnt > k) return 1e9;

        // if we already computed the result of the current sub-problem, we return it
        if(dp[node][cnt] != -1) return dp[node][cnt];

        // we will return the minimum cost of reaching the destination node from the current node with the current number of stops
        // so we initialize it with 1e9
        int ans = 1e9;


        // we traverse the neighbors of the current node
        for(auto&[x,y]: adj[node])
            // we update the minimum cost of reaching the destination node from the current node with the current number of stops
            // with the minimum cost of reaching the destination node from the neighbor node with the current number of stops + the cost of the edge 
            ans = min(ans, y + dfs(x, cnt + 1));

        // we memoize the result of the current sub-problem
        return dp[node][cnt] = ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        this -> k = k;
        this -> dst = dst;

        // we initialize the dp with -1
        memset(dp, -1, sizeof(dp));
        
        // we initialize the adjaceny list
        adj.assign(n, vector<pair<int,int>> ());

        // we add the edges to the adjaceny list
        for(auto&i: flights)
            adj[i[0]].push_back({i[1], i[2]});

        // we call the dfs to traverse the graph and keep track of the number of stops
        int ans = dfs(src, 0); 
        
        // if we didn't reach the destination node, we return -1 else we return the ans
        return (ans == 1e9 ? -1 : ans);
    }
};
