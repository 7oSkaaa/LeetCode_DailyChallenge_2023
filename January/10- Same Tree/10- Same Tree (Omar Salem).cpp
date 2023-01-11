//Author : Omar Salem
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both are NULL
        if(!p and !q)   
            return true;
        // If one is NULL and other is not NULL
        if(!p or !q)
            return false;
        // Comparing values and go to left and right subtree 
        return (p->val == q->val and isSameTree(p->right , q->right) and isSameTree(p->left, q->left));
    }
};