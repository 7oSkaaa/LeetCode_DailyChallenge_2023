// Author: Ahmed Gamal

class Solution {
public:

    // we need to find the cheapest path from src to dst with at most k stops
    // since the number of nodes is small we can use dp
    // dp[src][depth]: the cheapest path to dst from src with already depth stops (depth is the number of stops we already made)
    // dp[src][depth] = min(dp[nxt][depth + 1] + wt) for all nxt and wt such that there's an edge from src to nxt with weight wt
    // the answer is dp[src][0] (we need to start from src with 0 stops)


    // inf: a large number (2e9)
    #define inf 2000'000'000
    
    // pii: a pair of integers (for edges)
    using pii = pair<int, int>;
    
    // memo: the dp array
    vector<vector<int>> memo;

    // k: the maximum number of stops
    // dst: the destination node
    int k, dst;


    int dp(int src, int depth, vector<vector<pii>>& adj){
        // if we already made k stops or we reached the destination we need to return the distance to the destination
        if(depth > k or src == dst){
            // if we reached the destination we need to return 0
            return src == dst ? 0 : inf;
        }

        // if we already calculated the answer we need to return it
        int& ret = memo[src][depth];
        if(~ret)
            return ret;
        
        // the answer is the minimum of dp[nxt][depth + 1] + wt for all nxt and wt such that there's an edge from src to nxt with weight wt
        ret = inf;
        for(auto& [nxt, wt] : adj[src]){
            ret = min(ret, wt + dp(nxt, depth + 1, adj));
        }

        // return the answer
        return ret;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // initialize the dp array
        memo.assign(n, vector<int>(k + 2, -1));

        // initialize the maximum number of stops and the destination node to use them in the dp function
        this -> k = k;
        this -> dst = dst;

        // adj: the graph
        vector<vector<pii>> adj(n);

        // add the edges to the graph
        for(auto& flight : flights){
            int u = flight[0], v = flight[1], wt = flight[2];
            adj[u].emplace_back(v, wt);
        }

        // call the dp function
        int ans = dp(src, 0, adj);

        // if the answer is inf then there's no path from src to dst with at most k stops
        return ans == inf ? -1 : ans;
    }
};