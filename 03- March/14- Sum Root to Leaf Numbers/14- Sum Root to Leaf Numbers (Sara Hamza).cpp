//Author: Sara Hamza
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

    int solve(TreeNode* node, string s) {
        /*
            node : current node
            s    : concatenation of all values that we 've visited in this branch so far.
                in branching into the left node=> send s as concat (s,  leftValue)
                             and the right node=> send s as concat (s, rightValue)
        */

        // leaf node ? concatenate its value to s and convert it to int
        if(!node->left && !node->right)
            return stoi(s+to_string(node->val));

        // branching
        int leftSubtree = 0, rightSubtree = 0;
        // if the left node is null => there is no left branch, ignore it (num1 = 0)
        // else get the answer of the left subtree
        if(node->left)
            leftSubtree = solve(node->left, s+to_string(node->val));
        // if the right node is null => there is no right branch, ignore it (num2 = 0)
        // else get the answer of the right subtree
        if(node->right)
            rightSubtree = solve(node->right, s+to_string(node->val));

        // return the sum of the answers of both subtrees (left and right)
        return leftSubtree + rightSubtree;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, "");
    }
};
