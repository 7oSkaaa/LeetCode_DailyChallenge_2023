// author: Esraa Syam
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // if root is null, return null
        if(root == NULL) return root;
        // invert left and right subtrees recursively
        // and store the results in left and right 
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        // swap left and right subtrees
        root->left = right;
        root->right = left;
        return root;
    }
};