/*
    Author: Mohamed AboElnasr
*/
/*
    -the solution is to inorder traverse the BST 
    -the result will be a sorted list of numbers 
    -save the numbers in a vector 
    - iterate over the vector 
    - apply  check if the current difference is less than the ans  or not 
    and return the min difference 
*/
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
      vector<int>v;
      in_order(v,root);
      int size=v.size();
      int ans=100001;
      for(int i=1 ;i<size;i++)
        ans=min(ans,(v[i]-v[i-1]));
    return ans;
    }
    void in_order(vector<int>&v,TreeNode* root){
        if(root==nullptr)return ;
        in_order(v,root->left);
        v.push_back(root->val);
        in_order(v,root->right);
    }
};