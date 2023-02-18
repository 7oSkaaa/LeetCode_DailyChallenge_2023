//Author: Mohamed Gewaly

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
    /**
    Post Order Treversal in which first we go in Left subtree and 
    then in Right subtree then we return back to Parent node.
   When we come back to the parent node we swap it's Left subtree and Right subtree.
    **/
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;             // Base Case

        invertTree(root->left);         //Call the left substree
        
        invertTree(root->right);       //Call the left substree  

        swap(root-> right, root->left);  // Swap the nodes
        
        return root;  // Return the root
    }
};