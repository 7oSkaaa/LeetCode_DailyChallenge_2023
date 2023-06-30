// Author: Lama Salah

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 0;   // The level with the maximum sum.
        int maxSum = -1e6;  // The maximum sum (initialized with a very small value).
        int currentLevel = 1; // Current level (starting with the root level (level one)).
        
        // Queue to store tree nodes for level-order traversal.
        queue<TreeNode*> q; 

        // Add the root node to the queue.
        q.push(root); 
        
        while (!q.empty()) {
            // Get the number of nodes at the current level.
            int sz = q.size(); 

            // Variable to calculate the sum of values at the current level.
            int sum = 0; 

            while (sz--){
                // Get the front node from the queue.
                auto currentNode = q.front(); 
                q.pop(); // Dequeue the front node.
                
                // Add the value of the current node to the sum.
                sum += currentNode->val; 

                // Add the left child to the queue if it exists.
                if (currentNode->left) {
                    q.push(currentNode->left); 
                }
                
                // Add the right child to the queue if it exists.
                if (currentNode->right) {
                    q.push(currentNode->right); 
                }
            }
            
            if (sum > maxSum) {
                maxSum = sum; // Update the maximum sum.
                maxLevel = currentLevel; // Update the level with the maximum sum.
            }
            
            // Move to the next level.
            currentLevel++; 
        }
        
        // Return the level with the maximum sum.
        return maxLevel; 
    }
};