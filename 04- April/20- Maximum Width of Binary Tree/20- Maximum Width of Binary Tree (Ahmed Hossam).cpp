// Author: Ahmed Hossam

class Solution {
public:
    
    // Function to calculate the maximum width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {

        // Return 0 if the tree is empty
        if(!root) return 0;

        // Create a queue to store the nodes of the binary tree
        // A pair is used to store the node and its index
        queue < pair < TreeNode*, int > > bfs;

        // Push the root node and its index to the queue
        bfs.push({root, 1});

        // Set the initial result to 1
        int res = 1;

        // Loop until the queue is empty
        while(!bfs.empty()){
            
            // Get the number of nodes in the current level
            int sz = bfs.size();
            
            // Get the index of the first node in the current level
            int prev = bfs.front().second;
            
            // Update the result by finding the difference between the index of the first and last nodes in the current level
            res = max(res, bfs.back().second - bfs.front().second + 1);
            
            // Process all the nodes in the current level
            while(sz--){
                
                // Get the current node and its index from the queue
                auto [node, curr] = bfs.front();
                
                // If the current node has a left child, push it to the queue with the appropriate index
                if(node -> left) 
                    bfs.push({node -> left, 2ll * (curr - prev) + 1});
                
                // If the current node has a right child, push it to the queue with the appropriate index
                if(node -> right) 
                    bfs.push({node -> right, 2ll * (curr - prev) + 2});
                
                // Remove the current node from the queue
                bfs.pop();
            }
        }
        
        // Return the result
        return res;
    }

};
