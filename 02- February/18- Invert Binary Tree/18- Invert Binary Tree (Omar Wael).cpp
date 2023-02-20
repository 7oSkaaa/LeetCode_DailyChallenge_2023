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
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            // go depth in the tree and then swap left and right nodes
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left,root->right);
        }
        return root;
    }
};
