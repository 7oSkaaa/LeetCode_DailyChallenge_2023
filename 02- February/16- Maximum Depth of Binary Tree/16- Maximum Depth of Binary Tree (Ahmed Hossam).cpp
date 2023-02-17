// Author: Ahmed Hossam

class Solution {
public:

    /*
        get the maximum depth of the tree using DFS (Depth First Search)
        the maximum depth is the maximum depth of the left subtree and the right subtree plus 1 (the root)
        depth of the tree = 1 + max(depth of the left subtree, depth of the right subtree)
    */
   
    int maxDepth(TreeNode* root) {
        return (!root ? 0 : 1 + max(maxDepth(root -> right), maxDepth(root -> left)));
    }
};
