class Solution {
public:

    void preorder(TreeNode* Node, vector < int >& nodes){
        if(Node == nullptr) return;
        nodes.push_back(Node -> val);
        preorder(Node -> left, nodes);
        preorder(Node -> right, nodes);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector < int > nodes;
        preorder(root, nodes);
        return nodes;
    }
};
