// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    int minDiffInBST(TreeNode* root) {
        // get all values 
        rec(root);
        // sort values
        sort(ans.begin(),ans.end());
        int mn=INT_MAX;
        //get minimum distance between all values
        for(int i=1;i<ans.size();i++){
            mn=min(mn,ans[i]-ans[i-1]);
        }
        return mn;
    }
    void rec(TreeNode* root){
        // check if cuurent node not equal null (not leaf node)
        if(root){
            // save current value
            ans.push_back(root->val);
            // go depth using left node
            rec(root->left);
            // go depth using right node
            rec(root->right);
        }
    }
};
