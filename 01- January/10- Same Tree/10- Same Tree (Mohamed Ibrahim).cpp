//Author: Mohamed Ibrhaim
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty, return true
        if (!p && !q) return true;
        // If one of the trees is empty, return false
        if (!p || !q) return false;
        // If the values of the nodes are not the same, return false
        if (p->val != q->val) return false;
        // Check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};