// Author: Mohamed Khedr

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // check if the current subtrees are equal null
        if (p == nullptr && q == nullptr)
            return true;
        // check if one of them equal null
        if (p == nullptr || q == nullptr)
            return false;
        // so we guarantee that both of them contain values
        // check on the current values of nodes
        if (p->val != q->val)
            return false;
        // repeat the same operation on the left & right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};