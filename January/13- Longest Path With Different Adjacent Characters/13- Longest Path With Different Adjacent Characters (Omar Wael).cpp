// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int ans=1;
    // create adjacency list
    vector<vector<int>>adj;
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        adj.resize(n);
        // add edges to adjacency list
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        dfs(parent,s,0);
        return ans;
    }
    int dfs(vector<int>& parent, string& s,int cur){
        int ch1=0,ch2=0;
        for(int i=0;i<adj[cur].size();i++){
            // calculate path from this node
            int tmp=dfs(parent,s,adj[cur][i]);
            // check if the label of this node equal the label of the root node
            if(s[adj[cur][i]]==s[cur]){
                continue;
            }
            // if the new path is greater than one of the other two pathes then update the values 
            else if(tmp>ch1){
                ch2=ch1;
                ch1=tmp;
            }else if(tmp>ch2){
                ch2=tmp;
            }
        }
        // update ans
        ans=max(ans,ch1+ch2+1);
        return ch1+1;
    }
};