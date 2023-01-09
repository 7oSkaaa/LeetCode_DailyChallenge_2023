/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Intuition
 *      Preorder Traversal means we visit root then left node then right node
 * 
 * Approach
 *      so we push root of every subtree first then push all left nodes then push all right nodes
 * 
 * 
 * Complexity
 *      Time complexity:
 *          O(N) where N is number of nodes
 *      
 *      Space complexity:
 *          O(1) without considering stack calls otherwise it will be O(h) where h is the height of tree
*/
class Solution {
private:
    vector<int> nodes;
    void dfs(TreeNode* root) {
        if (!root)      return;

        nodes.emplace_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return nodes;
    }
};
