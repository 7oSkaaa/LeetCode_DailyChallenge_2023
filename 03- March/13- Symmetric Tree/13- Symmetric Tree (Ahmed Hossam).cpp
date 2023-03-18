// Author: Ahmed Hossam

class Solution {
public:
    
    
    bool traverse(TreeNode* node1, TreeNode* node2){
        // if the two subtrees are empty so they are symmetric
        if(!node1 && !node2) return true;

        // if one of the two nodes empty so the subtree not symmetric
        if(!node1 || !node2) return false;

        // if the value of the two subtrees root different the subtrees aren't symmetric
        if(node1 -> val != node2 -> val) return false;

        // if the left tree and right tree are symmetric so the current subtree are symmetric also
        return traverse(node1 -> right, node2 -> left) && traverse(node1 -> left, node2 -> right);
    }
    
    bool isSymmetric(TreeNode* root) {
        // if the tree are empty 
        if(!root) return true;

        // check the symmetry of the tree
        return traverse(root -> left, root -> right);
    }
};
