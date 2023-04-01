// author : Ahmed Zedan
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
    // dfs
    int dfs(TreeNode* root , int x =0){
        if(!root) return 0 ; // out of tree 
        x = (x*10) + root->val ; 
        if(!root->left && !root->right) return x ; // end of path return number 
        return dfs(root->left,x) + dfs(root->right,x) ;   
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root) ; 
    }
};