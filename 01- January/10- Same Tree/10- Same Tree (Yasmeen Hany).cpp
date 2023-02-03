// Author: Eileanora

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //base case
        if(p == nullptr && q == nullptr)  //if both are leafs -> return true
            return true;

        if(p == nullptr || q == nullptr)  //if one is a leaf and the other one -> is not return false
            return false;

        if(p -> val != q -> val)  //if both node a != node b -> not same tree -> return false
            return false;
        
        //recursive case
        return (isSameTree(p -> left , q -> left) && isSameTree(p -> right , q -> right));
    }
    // Time Complexity: O(n)
    /*
    we recurse over both trees at the same time and compare values each time we recurse
    if one branch ends before the other, we return false
    if the values are different, we return false
    otherwise when we reach the end we return true
    */
};