// Author : Mazen Alasas
class Solution {
public:
    vector <int> nodes;   // Vector to carry nodes
    void preorder(TreeNode*root){
        if (root == NULL)   // If node(root) is empty(null)
            return;
        nodes.push_back(root -> val);   // Push the value of node First
        // PreOreder Traversal  -->  ( root -> left -> right )  
        // Using Recursion
        preorder(root -> left);    // Thenn the left first
        preorder(root -> right);    // Then on the right
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);    // Call Preorder Function
        return nodes;    // return nodes vector 
    }
    
};
