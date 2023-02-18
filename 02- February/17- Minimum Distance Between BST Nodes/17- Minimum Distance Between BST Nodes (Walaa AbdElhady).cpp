//Author: Walaa AbdElhady

class Solution {
private:
    // store min diff
    int mn = INT_MAX;
    TreeNode* prev;
public:
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        return mn;
    }
    void inOrder(TreeNode* root) {
        // base case
        if (root == NULL)return;
        // go to the left subtree
        inOrder(root->left);
        if (prev != NULL) {
            // if prev node not NULL get difference between the values of nodes
            mn = min(mn, abs((prev->val) - (root->val)));
        }
        // store prev node
        prev = root;
        // go to the right subtree
        inOrder(root->right);
    }
};