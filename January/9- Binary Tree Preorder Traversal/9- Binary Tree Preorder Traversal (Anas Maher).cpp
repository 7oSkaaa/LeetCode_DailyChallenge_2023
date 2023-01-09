//Author: Anas Maher

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

    vector<int> res; // storing the values.
    vector<int> preorderTraversal(TreeNode* root) {
        if(root!=NULL) // if current node not empty.
        {
            res.push_back(root->val);// add the current value
        
            preorderTraversal(root->left);// check left childs,
            preorderTraversal(root->right); // then right ones.
        }
        return res;
    }
};
