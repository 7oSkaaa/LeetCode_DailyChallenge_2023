// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return ismirror(root->left,root->right);
    }
    bool ismirror(TreeNode* l,TreeNode* r){
        if(l==NULL || r==NULL){
            return (l==r);
        }
        // check if current valuse are equal 
        // go depth using left subtree for left node and right subtree for right node
        // to check if it equal
        // and then go depth using left subtree for right node and right subtree for left node
        return ((l->val==r->val) && ismirror(l->left,r->right) && ismirror(l->right,r->left));
    }
};
