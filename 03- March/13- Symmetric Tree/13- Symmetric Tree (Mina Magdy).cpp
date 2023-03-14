// Author: Mina Magdy

class Solution {
public:
    // L is for the left subtree of the root, R is for the right subtree of the root
    bool sym(TreeNode* L, TreeNode* R) {
        // (!L && !R)  =>  if the current node of the left subtree is NULL AND the current node of the right subtree is NULL too THEN it will return because the OR operator is short circuited
        // otherwise check if both nodes are not NULL and their values are equal THEN:
        // compare the left sub-subtree of left subtree with the right sub-subtree of right subtree (Symmetric tree)
        // also, do this for opposite directions (right of left AND left of right)
        return (!L && !R) || (L && R && L->val == R->val && sym(L->left, R->right) && sym(L->right, R->left));
    }
    bool isSymmetric(TreeNode* root) {
        return sym(root->left, root->right);
    }
};
