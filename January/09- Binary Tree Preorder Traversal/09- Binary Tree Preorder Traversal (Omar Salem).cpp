//Author: Omar Salem
class Solution {
public:
    void solve(vector<int> &ans , TreeNode* root){
       // Check if the current node is empty or Null. 
        if(root == NULL)
            return;
        //Display the data part of the root (or current node)
        ans.push_back(root->val);
        //Traverse the left subtree by recursively calling the preorder function
        solve(ans, root->left);
        //Traverse the right subtree by recursively calling the preorder function
        solve(ans, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
            vector < int > ans ;
            // calling function 
            solve(ans, root);
            return ans ;
    }
};

 
