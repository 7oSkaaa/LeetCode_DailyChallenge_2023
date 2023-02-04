// Author: Noura Algohary
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
    vector<int> pre;
    vector<int> preorderTraversal(TreeNode* root) {
    // Preorder binary tree traversal is root -> left -> right
            if(root)
            {
                // first, the root value must be added
                pre.push_back(root->val);
                // second, the left branch must be completed
                preorderTraversal(root->left);
                // finally, the right branch
                preorderTraversal(root->right);
            }
        // return the new order(preorder)
        return pre;
    }
};