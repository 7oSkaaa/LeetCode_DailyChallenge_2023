// Author: Mahmoud Aboelsoud

class Solution {
public:
    // to check if the tree is symmetric or not we will do inorder traversal and check if the tree is symmetric or not
    // we will use a vector of pairs to store the value and the direction of the node
    // if the direction is 'l' then it is left child and if it is 'r' then it is right child
    // we will do inorder traversal and store the value and the direction of the node in the vector
    // then we will check if the tree is symmetric or not by checking if the value of the first node is equal to the value of the last node
    // and if the direction of the first node is not equal to the direction of the last node
    // if the tree is symmetric then we will return true and if not then we will return false


    // vector to store the value and the direction of the node
    vector<pair<int,char>> inorder;

    // inorder traversal function
    void in_order(TreeNode* root, char c){
        // if the root is null then we will return
        if(root == NULL) return;

        // we will do inorder traversal
        in_order(root -> left, 'l');
        inorder.emplace_back(root -> val, c);
        in_order(root -> right, 'r');
    }


    bool isSymmetric(TreeNode* root) {
        // start the inorder traversal from the root and the direction is 'o' for the root
        in_order(root, 'o');

        for(int i = 0, j = inorder.size() - 1; i < j; i++, j--)
            // if the value of the first node is not equal to the value of the last node or the direction of the first node is equal to the direction of the last node
            // then the tree is not symmetric and we will return false
            if(inorder[i].first != inorder[j].first || inorder[i].second == inorder[j].second) return 0;

        // otherwise the tree is symmetric and we will return true
        return 1;
    }
};
