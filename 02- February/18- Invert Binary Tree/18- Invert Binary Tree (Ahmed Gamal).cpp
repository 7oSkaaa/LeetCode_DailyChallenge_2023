// Author: Ahmed Gamal

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

// for this problem, we can use recursion to solve it
// we need to swap the left and right subtrees of each node
// we can do this by creating a new node with the same value as the current node and the left and right subtrees swapped (recursively)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case is when we reach a leaf node
        if(not root)
            return root;
        
        // return a new node with the same value as the current node and the left and right subtrees swapped
        return new TreeNode(root -> val, invertTree(root -> right), invertTree(root -> left));
    }
};