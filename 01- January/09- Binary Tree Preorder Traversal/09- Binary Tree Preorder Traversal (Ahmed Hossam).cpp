// Author: Ahmed Hossam

class Solution {
public:

    void preorder(TreeNode* Node, vector < int >& nodes){
        
        // if the current node is nul
        if(Node == nullptr) return;

        // Preorder is RLR -> (Root - Left - Right)
        nodes.push_back(Node -> val);
        preorder(Node -> left, nodes);
        preorder(Node -> right, nodes);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        // vector to store the values of the nodes
        vector < int > nodes;
        
        // taverse the tree in pre-order
        preorder(root, nodes);

        return nodes;
    }
};
