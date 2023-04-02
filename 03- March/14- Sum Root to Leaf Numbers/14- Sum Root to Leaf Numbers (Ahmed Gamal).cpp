// Author: Ahmed Gamal

// for this problem we will use dfs to traverse the tree and add the current number to the sum if we reach a leaf node
// we can use an attribute to store the sum
// we can use a default constructor to initialize the sum to 0
// we can use a default parameter to pass the current number to the next recursive call (to add one digit to the number just multiply the current number by 10 and add the current node value to it)

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
    // we can use an attribute to store the sum
    int sum;
public:

    // we can use a default constructor to initialize the sum to 0
    Solution() {
        sum = 0;
    }

    int sumNumbers(TreeNode* root, int num = 0) {
        // leaf: if the current node is a leaf node
        bool leaf = true;

        // loop over the children of the current node
        for(auto& nxt : {root -> left, root -> right}) {
            if(nxt) {
                // if the current node is not a leaf node (has at least one child)
                leaf = false;

                // dfs to the next node
                sumNumbers(nxt, num * 10 + root -> val);
            }
        }

        // if the current node is a leaf node (we had not entered the loop)
        if(leaf) {
            // add the current value to the number and add it to the sum
            sum += num * 10 + root -> val;
        }

        // return the sum
        return sum;
    }
};