// Author: Walaa AbdElhady

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // base case
        if (root == NULL)return NULL;
        // L and R is a temp to swap
        TreeNode* L = root->left;
        TreeNode* R = root->right;
        // swap two subtree
        root->left = R;
        root->right = L;
        // go to the left subtree
        invertTree(root->left);
        // got to right subtree
        invertTree(root->right);
        //return tree after invert
        return root;
    }
};