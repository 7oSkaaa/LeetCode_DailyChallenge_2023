class Solution {
public:
    int mini=INT_MAX;
    int prev=-1;
    void inOrder(TreeNode*root){
       if(!root)return;
       inOrder(root->left);
       if(prev>=0)
       mini=min(mini,root->val-prev);
       prev=root->val;
       inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)return 0;
        inOrder(root);
        return mini;
    }
};