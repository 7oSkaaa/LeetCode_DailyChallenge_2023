// Author: Walaa AbdElhady

// for this problem we need to traverse tree from left to right and from right to left so =>
// we need to traverse it level by level (bfs)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        // base case => when the tree is empty
        if (!root)return ans;
        int level = 0;
        queue<TreeNode*>q;
        // add the root to the queue
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int>tmp;
            while (sz--) {
                // get the current node and remove it from the queue
                TreeNode* parent = q.front();
                q.pop();
                // add the current node value 
                tmp.push_back(parent->val);
                // add the left child of node
                if (parent->left)q.push(parent->left);
                // add the right child of node
                if (parent->right)q.push(parent->right);
            }
            // when the level is odd we need to reverse nodes
            if (level & 1)reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            level++;
        }
        // root after zigzag level order traversal
        return ans;
    }

};