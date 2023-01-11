//Author: Mohamed Ibrahim

class Solution {
    public:
    //Define a DFS function to find the minimum time required to collect all apples
    int dfs(vector<vector<int>>&adj, vector<bool>&apple, int start, int parent)
    {
        int time=0;
        // Iterate over each child of the current node
        for(auto x:adj[start])
        {
            // Check if the child is not the parent (to avoid backtracking)
            if(x!=parent)
            // Add the time spent on this child and its descendants to the total time
            time= time+dfs(adj, apple, x, start);
        }
        //if we're at the root node, return the total time
        if(start==0)
        return time;
        // If we haven't found any apples and the current node doesn't have one, return 0
        if(time==0 && apple[start]==false)
        return 0;
        // Otherwise, add 2 seconds for the time spent on this node (going down and coming back)
        else
        return time+2;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Build an adjacency list representation of the tree
        vector<vector<int>>adj(n+1);
        for(auto x:edges)
        {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }
        // Call the DFS function starting from the root node (0), and with -1 as the parent
        return dfs(adj, hasApple, 0, -1);
    }
};
