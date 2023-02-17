// Author : Eileanora

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
    vector <int> ans; 

    void dfs(TreeNode* node)
    {

        if(node == nullptr)  // if the current node is null return
            return;

        ans.push_back(node->val);
        dfs(node->left); //otherwise iterate through left branch 
        dfs(node->right); // then right branch 
    }
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return ans; 
    }
    /*
    we iterate through the tree first we check left branches untill we hit a leaf
    then we go to the right branch and do the same thing
    we do the same for each head 
    every time we encounter a value push it to vector ans
    */
};
