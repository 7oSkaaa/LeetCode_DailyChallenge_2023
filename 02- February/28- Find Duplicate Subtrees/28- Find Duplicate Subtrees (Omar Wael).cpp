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
    vector<TreeNode*>ans;
    map<string,int>mp;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL){
            return ans;
        }
        dfs(root);
        return ans;
    }
    string dfs(TreeNode* root){
        if(root==NULL){
            return "_";
        }
        // get the structure of current node
        string cur=to_string(root->val)+"_"+dfs(root->left)+"_"+dfs(root->right);
        // if mp[cur]>0 this means that current node have the same structure with some another node
        // so you should save current node
        // if mp[cur]>1 this means that current node already have been saved
        if(mp[cur]==1){
            ans.push_back(root);
        }
        mp[cur]++;
        return cur;
    }
};
