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
 // author : Ahmed Zedan
class Solution {
public:
    vector<int>v ; 
    // inorder traversal for sorted value (left , root , right)
    void rec(TreeNode* root){
        if(!root) return ;
        rec(root->left) ; 
        v.push_back(root->val) ; 
        rec(root->right) ; 
    }
    int minDiffInBST(TreeNode* root) {
        rec(root) ; 
        int ans = INT_MAX ;
        // check all adjacency element 
        for(int i=0 ; i<v.size()-1 ; i++){
            ans = min(ans,abs(v[i]-v[i+1])) ; 
        } 
        return ans ; 
    }
};