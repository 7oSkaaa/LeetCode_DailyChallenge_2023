// Author : Mazen Alasas
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
        // By comparing values ( p & q )
        if (p == NULL && q == NULL)   // If p and q are both NULL
            return true;
        if (q == NULL || p == NULL)   // If one of p and q is NULL
            return false;
        if (p -> val != q -> val)   // If the value of p and q are't the same
            return false;
        // Then passing each node recursively --> rigth --> left
        // And return true if both right and left are true Otherwise return false
        return isSameTree(p -> right, q -> right) && isSameTree(p -> left, q -> left);
    }
};

// Time O(n)
// space O(n) for recursion stack
