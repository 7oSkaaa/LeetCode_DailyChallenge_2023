//Author: Mohamed Ibrahim

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
    vector<int> preorderTraversal(TreeNode* root) {
        // Initialize an empty vector to store the traversal
        vector<int> res;
        // If the root node is null, return the empty vector
        if (!root) return res;
        // Push the root node value into the vector
        res.push_back(root->val);
        // Recursively get the preorder traversal of the left subtree and append it to the vector
        vector<int> left = preorderTraversal(root->left);
        res.insert(res.end(), left.begin(), left.end());
        // Recursively get the preorder traversal of the right subtree and append it to the vector
        vector<int> right = preorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());
        // Return the final vector
        return res;
    }
    
};