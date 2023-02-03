// author: Esraa Syam
class Solution {
public:
    vector < int > v;
    void rec(TreeNode* root){
        // base case
        if(root == NULL) return; // if root is null, return 
        v.push_back(root -> val); // push the value of root into the vector
        // recursive case
        rec(root -> left); // call the function on the left subtree
        rec(root -> right); // call the function on the right subtree
    }
    vector<int> preorderTraversal(TreeNode* root) {
        // preorder traversal is root, left, right
        rec(root); // call the recursive function
        return v;
        
    }
};