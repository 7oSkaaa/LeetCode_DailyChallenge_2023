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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        bool zigzag=true;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        // push current node to queue
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            // create vector for current level
            vector<int>current_level(sz);
            for(int i=0;i<sz;i++){
                // decide start this level from left of right
                if(zigzag){
                    current_level[i]=q.front()->val;
                }else{
                    current_level[sz-i-1]=q.front()->val;
                }
                // if there left node
                if(q.front()->left){
                    q.push(q.front()->left);
                }
                // if there right node
                if(q.front()->right){
                    q.push(q.front()->right);
                }
                q.pop();
            }
            zigzag=!zigzag;
            ans.push_back(current_level);
        }
        return ans;
    }
};
