// Author: Ahmed Hossam

class Solution {
public:
    
    // Function to find the length of the longest zigzag path in a binary tree
    int longestZigZag(TreeNode* root) {
        // If root is the only node or if the root has no left or right child, return 0
        if(!root -> left && !root -> right)
            return 0;
        
        // Call the depth-first search function with the root, length 0, and shouldGoLeft flag set to false
        return dfs(root, 0, false);
    }

    // Function to perform depth-first search
    int dfs(TreeNode* root, int length, bool shouldGoLeft) {
        // If the current node is null, return the current length
        if(!root) return length;
        
        // Declare variables for left and right paths and the current length
        int left = 0, right = 0, currLen = 0;
        
        // If shouldGoLeft flag is set and there is no left child for the current node, set currLen to length and reset length to 0
        if(shouldGoLeft && !root -> left)
            currLen = length, length = 0;
        // If shouldGoLeft flag is not set and there is no right child for the current node, set currLen to length and reset length to 0
        else if(!shouldGoLeft && !root -> right)
            currLen = length, length = 0;
        
        // Recursively call dfs function for the right and left nodes and update their lengths accordingly
        right = dfs(root -> right, shouldGoLeft ? 1 : length + 1, true);
        left = dfs(root -> left, shouldGoLeft ? length + 1 : 1, false);
        
        // Return the maximum of left, right, length and currLen
        return max({left, right, length, currLen});
    }

};
