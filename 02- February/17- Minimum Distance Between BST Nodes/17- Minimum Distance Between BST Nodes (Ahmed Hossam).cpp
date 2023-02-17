// Author: Ahmed Hossam

class Solution {
public:

    // get values of the tree in increasing order using Inorder traverse
    vector < int > values;

    // Left -> Root -> Right (Inorder traverse)
    void Inorder(TreeNode* root){
        if(!root) return;
        // go to the left subtree
        Inorder(root -> left);
        
        // get the value of the root
        values.push_back(root -> val);

        // go to the right subtree
        Inorder(root -> right);
    }

    int minDiffInBST(TreeNode* root) {
        // get values of the tree in increasing order using Inorder traverse
        Inorder(root);

        // get the minimum difference between two adjacent values
        int min_diff = 1e9;

        // values[i] - values[i - 1] is the difference between two adjacent values
        for(int i = 1; i < values.size(); i++)
            min_diff = min(min_diff, values[i] - values[i - 1]);

        // return the minimum difference
        return min_diff;
    }
};
