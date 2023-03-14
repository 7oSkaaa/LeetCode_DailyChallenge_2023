// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we just need to traverse the tree and keep track of the current value of concatenation of the nodes from the root to the current node
    // when we reach a leaf node, we add the current value to the answer
    

    // the answer variable
    int ans;

    // the dfs function to traverse the tree
    void dfs(TreeNode* root, int val){
        // if the current node is null, we return
        if(root == NULL) return;

        // we concatenate the current node value to the current value
        val = val * 10 + root -> val;

        // if we reach a leaf node, we add the current value to the answer
        if(!root -> left && !root -> right) ans += val;
        
        // we traverse the left and right subtrees
        dfs(root -> left, val);
        dfs(root -> right, val);
    }

    int sumNumbers(TreeNode* root) {
        // we initialize the answer to zero
        ans = 0;
        // we call the dfs function to traverse the tree and calculate the answer
        dfs(root, 0);
        
        // we return the answer
        return ans;
    }
};
