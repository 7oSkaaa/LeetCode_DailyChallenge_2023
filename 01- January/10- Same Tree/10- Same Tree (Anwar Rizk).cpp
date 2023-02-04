// Author: Anwar Rizk

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both are null return true
        if(!p && !q) return true;
        // if one of them is null return false
        if(!p || !q) return false;
        // if the values are not equal return false
        if(p->val != q->val) return false;
        // if the values are equal, check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


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