// Author: Mahmoud Aboelsoud


class Solution {
public:
    // just bfs on the tree to get the nodes at each level
    // and reverse the odd levels
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // if the tree is empty return empty vector
        if(root == NULL) return {};

        // the answer vector
        vector<vector<int>> ans;
        // the queue to do bfs
        queue<TreeNode*> q;

        // push the root to the queue
        q.push(root);
        // the turn variable to know if we should reverse the current level or not
        int turn = 0;
        // bfs
        while(q.size()){
            // traverse the current level
            int k = q.size();
            // the vector to store the values of the nodes at the current level
            vector<int> v;
            while(k--){
                auto x = q.front();
                q.pop();
                // push the value of the node to the vector
                v.push_back(x -> val);
                // push the children of the node to the queue
                if(x -> left != NULL) q.push(x -> left);
                if(x -> right != NULL) q.push(x -> right);
            }
            // reverse the vector if the turn is odd
            if(turn) reverse(v.begin(), v.end());
            // push the vector to the answer vector
            ans.push_back(v);
            // change the turn variable to be the opposite
            turn ^= 1;
        }
        return ans;
    }
};
