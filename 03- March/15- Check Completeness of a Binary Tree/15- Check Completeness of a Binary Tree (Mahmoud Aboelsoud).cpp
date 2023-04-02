// Author: Mahmoud Aboelsoud


class Solution {
public:
    // to check if a binary tree is complete or not
    // we will use level order traversal
    // we will check if there is a null node in the middle of the tree if so return false
    // we also check if there is a null node in the previous level and there is a node in the current level
    // if so return false
    // if we reach a null node and there is no node in the current level return true 


    bool isCompleteTree(TreeNode* root) {
        // bfs queue
        queue<TreeNode*> q;
        // push the root
        q.push(root);

        // level counter and fisrt null node level and last node with value level
        int lvl = 0, fis_null_lvl = -1, lst_node_lvl = -1; 

        // bfs
        while(q.size()){
            // get the size of the current level
            int k = q.size();
            
            // fisrt null node and last node positions with value in the current level
            int fis_null = -1, lst_node = -1;
            
            // increment the level
            lvl++;

            // loop on the current level
            for(int i = 0; i < k; i++){
                // get the front node
                auto x = q.front();
                q.pop();

                // if the node is null
                if(x == NULL){
                    // if this is the first null node in the tree set the fisrt null node level
                    if(fis_null_lvl == -1) fis_null_lvl = lvl;
                    // if this is the first null node in the current level set the fisrt null node position
                    if(fis_null == -1) fis_null = i;
                    // continue to the next node
                    continue;
                }
                // if the node is not null set the last node position with value in the current level and the last node level with value in the tree
                lst_node = i, lst_node_lvl = lvl;\
                // push the node children
                q.push(x -> left);
                q.push(x -> right);
            }

            // if there is a null node in the middle of the tree return false
            if(fis_null != -1 && fis_null < lst_node) return 0;
            // if there is a null node in the previous level and there is a node in the current level return false
            if(fis_null_lvl != -1 && fis_null_lvl < lst_node_lvl) return 0;
        }

        // return true after finishing the bfs which means the tree is complete
        return 1;
    }
};
