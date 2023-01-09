//Author: Mohamed Ashraf

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
                
    vector<int>v;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != 0){
            //push the root into the vector 
            v.push_back(root->val);
            // go to the left subtree
            preorderTraversal(root->left);
            // go to the right subtree 
            preorderTraversal(root->right); 
        }
        return v;
    }
};