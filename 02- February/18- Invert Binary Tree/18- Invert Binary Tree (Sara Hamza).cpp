//Author: Sara Hamza
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

    void solve(TreeNode* root){
        if(!root) return;
        //inverting the left subtree with the right one
        swap(root->left, root->right);
        //repeat for the left subtree and for the right one
        solve(root->left);
        solve(root->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};
