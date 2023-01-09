// Author: Anwar Rizk

class Solution {
public:

    // vector to store the answer globally
    vector < int > ans;
    vector<int> preorderTraversal(TreeNode* root) {
        // base case
        if(root == NULL) return ans;
        // read
        ans.push_back(root->val);
        // go left
        preorderTraversal(root->left);
        // go right
        preorderTraversal(root->right);
        return ans;
    }
};

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