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
    bool isMirror(TreeNode* left_root, TreeNode* right_root)
    {
        if(!left_root && !right_root)
            return true;
        else if(!left_root || !right_root)
            return false;
        else
        {
            if(left_root->val == right_root->val)
                return true && isMirror(left_root->left, right_root->right) && isMirror(left_root->right, right_root->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }
};