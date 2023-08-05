// Author: Mina Magdy

class Solution {
public:
    // Function to generate all possible unique binary search trees
    // with values ranging from 'l' to 'r'
    vector<TreeNode*> generateTrees(int r, int l = 1) {
        // Base case: if 'l' is greater than or equal to 'r', there is only one possible tree
        if (l >= r) {
            return { l == r ? new TreeNode(l) : NULL };
        }
        // Initialize a vector to store the resulting trees
        vector<TreeNode*> res;
        // Loop from 'l' to 'r', representing the root value of the current tree
        for (int i = l; i <= r; i++) {
            // Generate all possible left subtrees with values less than 'i'
            for (auto& leftSub : generateTrees(i - 1, l)) {
                // Generate all possible right subtrees with values greater than 'i'
                for (auto& rightSub : generateTrees(r, i + 1)) {
                    // Create a new tree with the current root 'i' and its left and right subtrees
                    res.push_back(new TreeNode(i, leftSub, rightSub));
                }
            }
        }
        // Return the vector of generated trees
        return res;
    }
};
