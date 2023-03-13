// Author: Sherif Ibrahim
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
    map<void*,bool>mp,mp2;
    vector <int>l,r;
    void left(TreeNode* root){
        if(root==NULL){
            l.push_back(-1);    
            return;
        }
        if(!mp[&(root->val)])
        l.push_back(root->val),mp[&(root->val)]=1;
        else return;
        left(root->left);
        left(root->right);
    }
    void right(TreeNode* root){
        if(root==NULL){
            r.push_back(-1);    
            return;
        }
        if(!mp2[&(root->val)])
        r.push_back(root->val),mp2[&(root->val)]=1;
        else return;
        right(root->right);
        right(root->left);
    }
    bool isSymmetric(TreeNode* root) {
        left(root);
        right(root);
        if(l.size()!=r.size())return 0;
        for(int i=0;i<l.size();i++){
            if(l[i]!=r[i])return 0;
        }
        return 1;
    }
};
