// Author: Mina Magdy

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
    // Declare a map 'dp' to store the results of subproblems (memoization)
    map<int, vector<TreeNode*>> dp;
    
    // Function to generate all possible full binary trees with 'n' nodes
    vector<TreeNode*> allPossibleFBT(int n) {
        // If 'n' is even, it is not possible to create a full binary tree with 'n' nodes, return an empty vector
        if (n % 2 == 0)
            return {};
        
        // If 'n' is 1, there is only one possible full binary tree with a single node, return a vector containing that node
        if (n == 1)
            return {new TreeNode()};
        
        // If the result for 'n' is already computed, return it from the map 'dp'
        if (dp.count(n))
            return dp[n];
        
        // Initialize an empty vector for 'n' in 'dp'
        dp[n] = {};
        
        // Loop through all possible left subtree sizes (odd numbers from 1 to n-1)
        for (int l = 1; l < n; l += 2) {
            // Calculate the size of the right subtree
            int r = n - l - 1;
            
            // Recursively generate all possible full binary trees for left and right subtrees
            vector<TreeNode*> left = allPossibleFBT(l);
            vector<TreeNode*> right = allPossibleFBT(r);
            
            // Combine the left and right subtrees to form the full binary trees with 'n' nodes
            for (TreeNode* L : left) {
                for (TreeNode* R : right) {
                    // Create a new full binary tree with root having value 0 and left and right subtrees as 'L' and 'R'
                    dp[n].push_back(new TreeNode(0, L, R));
                }
            }
        }
        
        // Return the vector of all possible full binary trees with 'n' nodes
        return dp[n];
    }
};
