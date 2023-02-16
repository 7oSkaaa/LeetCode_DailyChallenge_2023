// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

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
class Solution {
public:
    int ans=0;
    int maxDepth(TreeNode* root) {
        rec(root,0);
        return ans;
    }
    void rec(TreeNode* root,int cnt){
        // check if cuurent node not equal null (not leaf node)
        if(root){
            // go depth using left node
            rec(root->left,cnt+1);
            // go depth using right node
            rec(root->right,cnt+1);
        }else{
            // update answer
            ans=max(ans,cnt);
        }
    }
};
