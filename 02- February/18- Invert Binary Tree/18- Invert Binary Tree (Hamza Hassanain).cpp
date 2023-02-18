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
class Solution
{
public:
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        auto temp = node->left;
        node->left = node->right;
        node->right = temp;
        dfs(node->right);
        dfs(node->left);
    }
    TreeNode *invertTree(TreeNode *root)
    {

        dfs(root);
        return root;
    }
};