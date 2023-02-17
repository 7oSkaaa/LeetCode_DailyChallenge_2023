/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

# 

class Solution {
    #define inf 2000'000'000
    set<int> st;
public:
    
    int minDiffInBST(TreeNode* root) {
        if(not root)
            return inf;
        
        int mn = inf;
        auto pos = st.lower_bound(root -> val);
        if(pos != st.end() and *pos == root -> val){
            mn = 0;
        }else{
            if(pos != st.end())
                mn = min(mn, abs(*pos - root -> val));
            if(pos != st.begin())
                mn = min(mn, abs(*prev(pos) - root -> val));
        }

        st.insert(root -> val);
        return min({mn, minDiffInBST(root -> left), minDiffInBST(root -> right)});
    }
};