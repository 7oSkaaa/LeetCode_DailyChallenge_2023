// Author: Anas Maher

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
        
        if(!p && !q) return 1; // reached both = null ? then they are same.
        if(!p || !q || (p->val != q->val)) return 0; // if one is null the other is not or different values then they are not the same.
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // check similarity for left and right childs, if they are same left and right then they are same, if one side differs then returns 0 ( not the same ).
    }
};
