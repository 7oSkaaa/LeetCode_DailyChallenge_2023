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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {} ; // if tree is empty
        // bfs
        queue<TreeNode*>bfs ; 
        vector<vector<int>>ans ;
        vector<int>tmp ;  
        bfs.push(root) ; 
         while(bfs.size()){
            int sz = bfs.size() ; 
            while(sz--){
                TreeNode* curr = bfs.front() ;
                tmp.push_back(curr->val) ;  
                bfs.pop() ; 
                if(curr->left) bfs.push(curr->left) ; 
                if(curr->right) bfs.push(curr->right) ; 
            }
            ans.push_back(tmp) ; 
            tmp.clear() ; 
        }
        int n = ans.size() ; 
        for(int i=1 ; i<n ; i+=2){
            reverse(ans[i].begin(),ans[i].end()) ; // Zigzag Level
        }
        return ans; 
    }
};