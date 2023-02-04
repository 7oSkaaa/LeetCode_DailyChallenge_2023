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
    bool dfs(TreeNode* root1, TreeNode* root2){
        if( !root1 and !root2) return 1;    // Check if both root is NULL 
        if( !root1 or !root2) return 0;     // Check if only one root is NULL 
        if(root1 -> val != root2 -> val) return 0;  // Check if the value Not same
        //         jamp to left subtree             then right subtree
        return dfs(root1->left, root2->left) and dfs(root1->right, root2->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q);
    }
};