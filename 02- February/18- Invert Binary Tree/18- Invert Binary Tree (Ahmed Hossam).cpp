// Author: Ahmed Hossam

class Solution {
public:
    
    void invert(TreeNode* root){
        // if the root is null so do nothing and return
        if(!root) return;
        
        // swap the left subtree with the right subtree
        swap(root -> right, root -> left);
        
        // swap each subtrees in the right subtree
        invert(root -> right);
        
        // swap eaxh subtrees in the left subtree
        invert(root -> left);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
