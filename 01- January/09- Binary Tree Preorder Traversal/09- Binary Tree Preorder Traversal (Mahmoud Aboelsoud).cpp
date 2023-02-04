// Author: Mahmoud Aboelsoud

class Solution {
public:
    // create a vector to store the preorder traversal
    vector<int> ans;
    
    // function to get the tree preorder
    void preorder(TreeNode* root){
        // if the root is null we return and don't continue
        if(root == NULL) return;
         
        // add the value of the current node
        ans.push_back(root -> val);
        // check the current node's all left children 
        preorder(root -> left);
        // then check it's all right children
        preorder(root -> right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        // initialize our empty array
        ans.assign(0, 0);
        
        // call the preorder function with our current root
        preorder(root);
      
        // return the answer
        return ans;      
    }
};
