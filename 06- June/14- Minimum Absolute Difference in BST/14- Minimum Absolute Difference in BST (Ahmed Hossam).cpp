// Author: Ahmed Hossam

class Solution {
public:
    // Declaration of class variables.
    int minDiff, lastRootVal;

    // Constructor of the class.
    Solution(){
        // Initializing the minimum difference to maximum possible value and lastRootVal to -1.
        minDiff = INT_MAX;
        lastRootVal = -1;
    }

    int getMinimumDifference(TreeNode* root) {
        // If there is a left child node, recursively call the function for the left subtree.
        if(root -> left)
            getMinimumDifference(root -> left);
        
        // If lastRootVal is not -1, calculate the absolute difference between lastRootVal and the current node's value
        // and update the minimum difference if necessary.
        if(~lastRootVal)
            minDiff = min(minDiff, abs(lastRootVal - (root -> val)));
        
        // Update lastRootVal to the current node's value.
        lastRootVal = root -> val;
        
        // If there is a right child node, recursively call the function for the right subtree.
        if(root -> right)
            getMinimumDifference(root -> right);
        
        // Return the minimum difference.
        return minDiff;
    }
};
