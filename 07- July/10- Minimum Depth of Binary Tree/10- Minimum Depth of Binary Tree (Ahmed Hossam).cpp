// Author: Ahmed Hossam

class Solution {
public:
    int minDepth(TreeNode* root, int depth = 0) {
        // return 0 if there are no nodes in the tree otherwise it's not a leaf node
        if(!root) return (!depth ? 0 : 1e9);
        
        // return 1 if it's a leaf node
        if(!root -> left && !root -> right) return 1;

        // get the minimum depth of leaf node from the left and right subtree
        return 1 + min(minDepth(root -> left, depth + 1), minDepth(root -> right, depth + 1));
    }
};
