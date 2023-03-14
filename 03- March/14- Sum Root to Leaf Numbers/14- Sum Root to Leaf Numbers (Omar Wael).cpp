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
    int ans=0;
    int sumNumbers(TreeNode* root) {
        RoottoLeaf(root,0);
        return ans;
    }
    void RoottoLeaf(TreeNode* root,int val){
        if(root==NULL){
            return ;
        }
        // check if current node if leaf node
        if(root->left==NULL && root->right==NULL){
            // update the answer
            ans+=(val*10)+root->val;
            return ;
        }
        // go depth with right subtree
        RoottoLeaf(root->right,(val*10)+root->val);
        // go depth with left subtree
        RoottoLeaf(root->left,(val*10)+root->val);
        return ;
    }
};
