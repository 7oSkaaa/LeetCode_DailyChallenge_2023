//Author: Nayra Mohammed

//preorder traverse means visit all left childs of current node then go right
class Solution {
public:
  
    vector<int>ans;//here we store the tree's values
  
    vector<int> preorderTraversal(TreeNode* root) {
        
        if(root != NULL){ //check if current node have a value.
            ans.push_back(root->val);//push current value to ans
          
            preorderTraversal(root->left);//go to the next left childs
            //after the first call done , we go to the right childs
            preorderTraversal(root->right);
        }

        return ans; //when we are done with traversing over all nodes we return to the base_state where we started our journy. here our answer is completed
    }
};
