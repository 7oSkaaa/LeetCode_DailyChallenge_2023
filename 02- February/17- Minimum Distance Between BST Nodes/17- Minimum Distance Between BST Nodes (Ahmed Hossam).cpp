// Author: Ahmed Hossam

class Solution {
public:

    // get values of the tree
    vector < int > values;

    // Left -> Root -> Right
    void Inorder(TreeNode* root){
        if(!root) return;
        Inorder(root -> left);
        values.push_back(root -> val);
        Inorder(root -> right);
    }

    int minDiffInBST(TreeNode* root) {
        // lets make Inorder traverse to get the tree sorted in increasing order
        Inorder(root);

        // let get the min_diff between any two adjacent numbers
        int min_diff = 1e9;
        for(int i = 1; i < values.size(); i++)
            min_diff = min(min_diff, values[i] - values[i - 1]);

        return min_diff;
    }
};
