// Author: Ahmed Hossam

class Solution {
public:
    bool isCompleteTree(TreeNode* root, bool isHaveRight = false) {
        // try to bfs about the tree to get all levels
        queue < TreeNode* > bfs;

        // add the root to start the bfs from it
        bfs.push(root);

        // if the previous node have missed one right sub-tree
        bool isNodeMissed = false;

        while(!bfs.empty()){
            // get the current size of the queue
            int sz = bfs.size();

            // add node and check the state
            auto add_node = [&](TreeNode* node){
                // if the current node is nullptr so there is a missed node right now
                if(!node)
                    return isNodeMissed = true;

                // if we have to add a node and there is a node missed before so it's not completed tree
                if(isNodeMissed)
                    return false;

                // add the current node because it's valid to add
                return bfs.push(node), true;
            };

            while(sz--){
                TreeNode* curr = bfs.front();
                bfs.pop();

                // to check the current root is valid or not
                bool valid_root = true;

                valid_root &= add_node(curr -> left);
                valid_root &= add_node(curr -> right);

                // if the current root not valid so it's not completed tree
                if(!valid_root)
                    return false;
            }
        }

        // ok, it's a completed tree right now.
        return true;
    }
};
