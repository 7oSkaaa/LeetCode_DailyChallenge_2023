// Author: Noura Algohary
class Solution {
public:
    // A Deep First Search function which visits all children of a node before going back 
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& ans)
    {
        vector<int> child_cnt;  // to store the child counts
        vector<int> node_cnt(26); // to store the freq(counts) of alphabets of the subtree
        

        // this is a frequency array where the index is the order of the letter in English and the value is the no. of occurrence 
        node_cnt[labels[node] - 'a'] = 1;   

        for(auto child: adj[node])
        {
            if(parent == child)
                continue;

            child_cnt = dfs(child, node, adj, labels, ans);

            for(int i=0;i<26;i++)
                node_cnt[i] += child_cnt[i]; // add child counts to parent counts
        }
        
        ans[node] = node_cnt[labels[node] - 'a'];

        return node_cnt;  // an array with the counts for each node in the subtree 
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);  // adjacency list to store the node with its neighbors 

        // an array of size n where ans[i] is the number of nodes in the subtree of the ith node which have the same label as node i
        vector<int> ans(n, 0); 
        
        for(auto edge: edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1, adj, labels, ans);

        return ans;
    }
};