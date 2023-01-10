// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if boot nodes equal NULL that means we left the both trees at the same node which means that both trees are equal
        if(p == NULL && q == NULL) return true;
        // if one node is not found in one of the trees but it existed in the other tree then there are not the same
        if(p == NULL || q == NULL) return false;
        // if the values of the two nodes at the same position in the both trees not equal then there are not the same 
        if(p -> val != q -> val) return false;


        // go check the left and the right subtrees
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q-> right);
    }
};
