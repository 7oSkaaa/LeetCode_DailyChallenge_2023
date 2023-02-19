// Author: Mahmoud Aboelsoud

class Solution {
public:
    // traversing the tree and assign the left node to the right node and vice versa

    TreeNode* invertTree(TreeNode* root) {
        // base case
        if(root == NULL) return root;
        
        // get the right and left nodes
        TreeNode* right = invertTree(root -> right);
        TreeNode* left = invertTree(root -> left);
        
        // assign the left node to the right node and vice versa
        root -> left = right;
        root -> right = left;
        
        // return the root after the inversion
        return root;
    }
};
