//Author : Ahamad abdelwhab
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(!root)
            return root;    
        invertTree(root->left);
        invertTree(root->right);
        //swap every two nodes
        swap(root->left , root->right);
        return root;

    }
};
