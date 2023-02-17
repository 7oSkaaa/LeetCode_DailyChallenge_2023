// Author: Mahmoud Aboelsoud

class Solution {
public:
    // bfs solution to count the number of levels in the tree (the depth)

    int maxDepth(TreeNode* root) {
        // if the root is null, the depth is 0
        if(root == NULL) return 0;
        int lvl = 0;
        // we use a queue to store the nodes in the current level
        queue<TreeNode*> q;
        
        // we push the root to the queue
        q.push(root);

        // bfs to count the number of levels 
        while(q.size()){
            int k = q.size();
            lvl++;
            while(k--){
                TreeNode* x = q.front();
                q.pop();
                if(x -> left != NULL) q.push(x -> left);
                if(x -> right != NULL) q.push(x -> right);  
            }
        }
        // return the number of levels
        return lvl;
    }
};
