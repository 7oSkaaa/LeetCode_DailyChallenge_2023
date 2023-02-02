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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Both nodes are NULL
        if(!p && !q) return true;

        // One of the nodes is NULL
        if (!p || !q) return false;
        
        // Both nodes exist but different numbers
        if(p->val != q->val) return false;
        
        // Apply the same function on all nodes from left to right
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};