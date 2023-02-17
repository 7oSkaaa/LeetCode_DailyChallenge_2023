// Author: Ahmed Hossam

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if the root is null i will return 0
        // otherwise i will return 1 + max depth of my left and right children depth
        return (!root ? 0 : 1 + max(maxDepth(root -> right), maxDepth(root -> left)));
    }
};
