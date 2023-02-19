// Author: Ahmed Gamal

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

// for this problem, we want to traverse the tree in a zigzag order (left to right, then right to left, then left to right, etc.)
// we can do this by just doing a simple level order traversal and reversing the order of the nodes in each level (add them to the queue in the normal order, but add them to the answer in the reversed order)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // ans: the answer (levels of the tree)
        vector<vector<int>> ans;

        // base case is when the tree is empty
        if(not root)
            return ans;

        // children: the children of the current level
        vector<TreeNode*> children;

        // q: the queue used for the level order traversal
        queue<TreeNode*> q;

        // add the root to the queue and the answer (the root is the first level)
        ans = {{root -> val}};

        // add the root to the queue
        q.push(root);

        // left: whether the current level is left to right or right to left
        bool left = false;

        // while the queue is not empty
        while(not q.empty()){
            // get the size of the current level
            int size = int(q.size());

            while(size--){
                // get the current node and remove it from the queue
                auto curr = q.front();
                q.pop();

                // add the children of the current node to the children vector (next level)
                if(curr -> left)
                    children.push_back(curr -> left);
                if(curr -> right)
                    children.push_back(curr -> right);
            }

            // level: the next level (the children of the current level)

            vector<int> level;
            for(int i = 0; i < children.size(); i++){
                // add the children to the queue in the normal order
                q.push(children[i]);

                // add the children to the answer in the order we want (left to right or right to left)
                int idx = left ? i : children.size() - i - 1;
                level.emplace_back(children[idx] -> val); 
            }
            
            // add the next level to the answer if it is not empty
            if(not level.empty())
                ans.emplace_back(level);
                
            // clear the children vector and change the direction of the next level
            children.clear();
            left = not left;
        }
        
        
        return ans;
    }
};