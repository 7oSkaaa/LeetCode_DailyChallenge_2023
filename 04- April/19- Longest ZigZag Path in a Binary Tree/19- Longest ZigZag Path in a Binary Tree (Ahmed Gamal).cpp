// Author: Ahmed Gamal

// for each node, we can have two paths, one from left to right, and one from right to left
// we can use dp to solve this problem, we can use a map to store the answer for each node
// we can use a pair to store the node and the direction, if the direction is true, then we are going from left to right, otherwise we are going from right to left
// using dp, we can solve this problem by calling the function recursively, and storing the answer in the map

class Solution {
    // longest path from root to leaf with last direction
    map<pair<TreeNode*, bool>, int> memo;
public:
    
    int dp(TreeNode* root, bool last) {
        // base case
        if(not root) {
            return 0;
        }

        // if we have already calculated the answer, then return it
        if(memo.find({root, last}) !=  memo.end()) {
            return memo[{root, last}];
        }

        // if we are going from left to right, then we can only go from right to left
        int& ret = memo[{root, last}];
        ret = 0;
        if(last) {
            ret = 1 + dp(root -> left, false);
        } else {
            // if we are going from right to left, then we can only go from left to right
            ret = 1 + dp(root -> right, true);
        }

        return ret;
    }

    // to call the function recursively
    int dfs(TreeNode* root) {
        // base case
        if(not root) {
            return 0;
        }
        // we can have four paths, one from left to right, one from right to left, one from root to left, and one from root to right
        return max({dp(root, true), dp(root, false), dfs(root -> left), dfs(root -> right)});
    }

    int longestZigZag(TreeNode* root) {
        return dfs(root) - 1;
    }
};