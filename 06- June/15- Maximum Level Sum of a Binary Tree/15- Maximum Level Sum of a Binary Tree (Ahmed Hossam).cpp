// Author: Ahmed Hossam

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // Variables to store the level with the maximum sum, the minimum level sum, and the current level
        int minLevel = -1, minLevelSum = INT_MIN, currLevel = 1;

        // Queue for breadth-first search traversal
        queue < TreeNode* > bfs;

        // Add the root node to the queue
        bfs.emplace(root);

        // Perform breadth-first search
        while (!bfs.empty()) {
            // Get the number of nodes in the current level and initialize the sum of values in the current level
            int levelSz = bfs.size(), currSum = 0;

            // Process each node in the current level
            while (levelSz--) {
                // Get the front node from the queue and remove it
                TreeNode* currRoot = bfs.front();
                bfs.pop();

                // Add the value of the current node to the sum
                currSum += currRoot->val;

                // Enqueue the left and right children of the current node if they exist
                if (currRoot->left)
                    bfs.emplace(currRoot->left);
                if (currRoot->right)
                    bfs.emplace(currRoot->right);
            }

            // Check if the sum of the current level is greater than the minimum level sum
            // If so, update the minimum level sum and the level with the maximum sum
            if (minLevelSum < currSum)
                minLevelSum = currSum, minLevel = currLevel;

            // Move to the next level
            currLevel++;
        }

        // Return the level with the maximum sum
        return minLevel;
    }
};
