// Author: Ahmed Hossam

class Solution {
public:
    vector < TreeNode* > generateTrees(int E, int S = 1) {
        // If the end of the range is smaller than the start, return a vector with a single nullptr
        if (E < S) return {nullptr};

        // Create a vector to store the generated tree nodes
        vector < TreeNode* > nodes;

        // Iterate through each value from S to E
        for (int i = S; i <= E; ++i) {
            // Generate all possible left subtrees from the range [S, i-1]
            vector < TreeNode* > left = generateTrees(i - 1, S);

            // Generate all possible right subtrees from the range [i+1, E]
            vector < TreeNode* > right = generateTrees(E, i + 1);

            // Combine each left subtree with each right subtree and create a new tree node with value 'i'
            // Then, add the newly created tree node to the 'nodes' vector
            for (auto tl : left)
                for (auto tr : right)
                    nodes.push_back(new TreeNode(i, tl, tr));
        }

        // Return the vector containing all possible binary search trees
        return nodes;
    }
};
