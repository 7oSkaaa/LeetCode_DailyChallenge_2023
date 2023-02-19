//Author: Sara Hamza
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
        //BFS
        //in each level:
        //construct a vector of the nodes of this level

        //reverse direction of this vector or not?
        //keep track of this so you can alternatly change the reversal state of the current vector to get the zigzag shape
        //no change -> reverse -> no change -> ..

        //then append it to your final answer

        queue <TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        bool rev = 1; //reverse?

        while(!q.empty()){

            vector<int>level; //get all nodes in this level
            int sz = q.size();
            rev = !rev; //changing reversal state of "level" vector

            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                //null?
                if(!node) continue;

                level.push_back(node->val);

                //constructing queue's next level
                q.push(node->left);
                q.push(node->right);

            }
        // empty vector -> ignore
        if(level.size() == 0)
            continue;

        //reverse vector "level" before appending to the final answer to get the zigzag shape?
        if(rev)
            reverse(level.begin(), level.end());

        ans.push_back(level);


        }
        return ans;

    }
};
