/*
    Author: Mohamed AboElnasr
*/

/*
    I calculate the depth of the left branch 
    and the depth of the right branch 
    and the maxDepth of the tree will be the maximum between them + 1
    this (+1) because of the root itself 
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
      if(root==nullptr) return 0;

      int left_depth=maxDepth(root->left);
      int righ_depth=maxDepth(root->right);

      return 1+max(left_depth,righ_depth);  
    }
};