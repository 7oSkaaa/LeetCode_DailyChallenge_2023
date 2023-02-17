// author: Esraa Syam
class Solution {
public:
    int rec(TreeNode* root){
        // base case
        if(root == NULL) return 0;
        // recursive case
        // return the max depth of the left subtree and the right subtree 
        return max(rec(root -> right)  , rec(root -> left)) + 1;
    }
    int maxDepth(TreeNode* root) {
        return rec(root);        
    }
};