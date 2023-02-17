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
    vector<int>orderedTree;
    void inOrder(TreeNode * root)
    {
        if(!root)
            return ;
        inOrder(root->left);
        orderedTree.push_back(root->val);
        inOrder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inOrder(root);
        int minn = INT_MAX;
        for(int i = 1 ; i < orderedTree.size();i++)
            minn = min(minn , orderedTree[i] - orderedTree[i-1]);
        return minn;
    }
};