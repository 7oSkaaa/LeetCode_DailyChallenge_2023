// Author: Ahmed Hossam

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // if the root is empty
        if(!root) return {};

        // to store the nodes in each level in zigzag order
        vector < vector < int > > nodes;
        
        // make bfs on the tree
        queue < TreeNode* > bfs;
    
        // add root to start from it
        bfs.push(root);

        // add the two children
        auto add_children = [&](TreeNode* node){
            // if the child is available so add it
            if(node -> left)
                bfs.push(node -> left);
            if(node -> right)
                bfs.push(node -> right);
        };

        // to know the current level
        int level = 0;

        while(!bfs.empty()){
            int sz = bfs.size();
            
            // store the nodes of the current level
            vector < int > current_level_nodes;

            // iterate on the current level nodes
            while(sz--){
                auto node = bfs.front();
                bfs.pop();
                
                // add the current node val to the vector
                current_level_nodes.push_back(node -> val);

                // add the childrens of node
                add_children(node);
            }

            // zigzag order will be if the current level is odd and order will be normal
            // otherwise the order will be reversed
            if(level & 1)
                reverse(current_level_nodes.begin(), current_level_nodes.end());

            nodes.push_back(current_level_nodes);        

            // move to the current level
            level++;
        }

        return nodes;
    }
};
