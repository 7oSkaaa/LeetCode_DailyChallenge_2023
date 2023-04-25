// Author: Mahmoud Aboelsoud

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
    // we need to find the longest zigzag path in the tree
    // we can do that by traversing the tree recursively
    // we need to keep track of the direction of the path
    // if the direction is 0, we are going left, if the direction is 1, we are going right
    // we need to keep track of the longest path we have found so far
    // we can do that by using a global variable

    // mx: the longest zigzag path we have found so far
    int mx;

    // dir: the direction of the path
    int get_long(TreeNode* root, int dir){
        // if we reached a leaf, return 0
        if(root == NULL) return 0;

        // get the longest path in the left subtree
        int left = get_long(root -> left, 0);
        // get the longest path in the right subtree
        int right = get_long(root -> right, 1);
        
        // update the longest path we have found so far
        mx = max({mx, left, right});

        // if the direction is 0, we are going left, so we need to return the longest path in the right subtree + 1
        if(dir == 0) return right + 1;
        // if the direction is 1, we are going right, so we need to return the longest path in the left subtree + 1
        return left + 1;
    }


    int longestZigZag(TreeNode* root) {
        // initialize the longest path we have found so far to 0
        mx = 0;
        // call the recursive function to get the longest path
        get_long(root, -1);

        // return the longest path we have found so far
        return mx;
    }
};
