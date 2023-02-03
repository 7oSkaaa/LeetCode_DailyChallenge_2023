// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    // create adjacency list
    vector<vector<int>> adj;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        // add edges to adjacency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>ans(n,0);
        dfs(labels,0,-1,ans);
        return ans;
    }
    vector<int> dfs(string& labels, int cur,int prev,vector<int>& ans){
        // vreate two vectors 
        // count for count the frequency of each letter
        // tmp to save on it the returned values of the subtree
        vector<int>count(26,0),tmp;
        for(int i=0;i<adj[cur].size();i++){
            // if this node not equal the last one (to avoid cycles)
            if(adj[cur][i]!=prev){
                // search on subtree
                tmp=dfs(labels,adj[cur][i],cur,ans);
                // update frequency
                for(int i=0;i<26;i++){
                    count[i]+=tmp[i];
                }
            }
        }
        // increment this label by one
        count[labels[cur]-'a']++;
        ans[cur]=count[labels[cur]-'a'];
        return count;
    }
};