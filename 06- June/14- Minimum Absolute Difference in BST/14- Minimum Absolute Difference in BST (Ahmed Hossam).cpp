// Author: Ahmed Hossam

class Solution {
public:

    // This code defines a vector to store integer values
    vector < int > values;

    // This function recursively traverses a binary tree and adds its node values to the 'values' vector sorted increasing
    void get_values(TreeNode* root){
        // Base case: if the root is null, return
        if(!root) return;
        
        // Recursive calls: traverse the left subtree, add the root value, then traverse the right subtree (Sorted)
        get_values(root -> left);
        values.emplace_back(root -> val);
        get_values(root -> right);
    }

    int getMinimumDifference(TreeNode* root) {
        // Populate the 'values' vector by calling the 'get_values' function
        get_values(root);
        
        // Initialize the minimum difference variable with the maximum possible value
        int minDiff = INT_MAX;
        
        // Iterate through the 'values' vector to find the minimum difference between adjacent values
        for(int i = 1; i < values.size(); i++)
            minDiff = min(minDiff, values[i] - values[i - 1]);
        
        // Return the minimum difference
        return minDiff;
    }
};
