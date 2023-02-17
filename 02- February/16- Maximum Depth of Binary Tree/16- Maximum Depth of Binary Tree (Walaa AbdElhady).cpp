//Author: Walaa AbdElhady

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if the root is NULL i will return 0
        if (root == NULL)return 0;
        //calculate the depth of the left child and the depth of the right child
        //and return maxDepth of them + 1
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};