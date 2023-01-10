// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

// here you can see pre order video : https://www.youtube.com/watch?v=1WxLM2hwL-U
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        // check if this node not equal null
        if(root){
            // save this value
            ans.push_back(root->val);
            // visit left sub tree
            preorderTraversal(root->left);
            // visit right sub tree
            preorderTraversal(root->right);
        }
        return ans;
    }
};