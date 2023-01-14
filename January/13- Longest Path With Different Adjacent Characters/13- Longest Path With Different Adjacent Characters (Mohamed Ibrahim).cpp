//Author: Mohamed Ibrahim

class Solution {
public:
    int mx; // variable to keep track of the longest path that alternates between two different characters
    int dfs(vector<vector<int>>& tree, int node, string& s, int p) {
        int mxpath1 = 0, mxpath2 = 0; // variables to keep track of the two longest paths
        for(int val : tree[node]) { // iterate through the children of the current node
            
            if(val != p) { // if the child is not the parent of the current node
                
                int child = dfs(tree, val, s, node); 
                // recursively call the function with the child as the new node and the current node as the new parent
               
                if(s[node] != s[val]) { // compare the characters at the current node's and child's index in the string
                    
                    if(child > mxpath2) { // if the path returned by the recursive call is longer than mxpath2
                        mxpath1 = mxpath2; // update mxpath1
                        mxpath2 = child; // update mxpath2
                    } else if(child > mxpath1) {
                        mxpath1 = child; // if the path returned by the recursive call is longer than mxpath1 but shorter than mxpath2, update mxpath1
                    }
                }
            }
        }
     
        mxpath2 += 1; // add 1 to mxpath2 to account for the current node
        mx = max(mx, mxpath2 + mxpath1); // update the mx variable with the maximum of the current value and the sum of mxpath1 and mxpath2
        
        return mxpath2; // return mxpath2 to the parent node
    }

    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>> tree(parent.size());
        
        for(int i = 1; i < parent.size(); i++) {
            tree[i].push_back(parent[i]); // create a tree-like structure from the parent vector
            tree[parent[i]].push_back(i);
        }
        mx = 0; // initialize mx to 0
        dfs(tree, 0, s, -1); // start the recursion at the root node
        return mx; // return the final value of mx
    }
};
