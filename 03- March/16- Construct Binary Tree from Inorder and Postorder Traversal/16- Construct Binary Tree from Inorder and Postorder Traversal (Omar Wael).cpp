// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        // save the index of each node in inorder vector
        for(int i=0;i<n;i++){
            index[inorder[i]]=i;
        }
        return build(inorder,postorder,0,n-1,0,n-1);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder,int start_in,int end_in,int start_post ,int end_post){
        // check if you reach the end of the tree
        if(start_in>end_in || start_post>end_post){
            return NULL;
        }
        // root value will be at the end of post order
        int root_val=postorder[end_post];
        //create the root
        TreeNode* root=new TreeNode(root_val);
        // get the index of the root node in inorder vector
        int inorder_rootindex=index[root_val];
        // calculate the size of left sub tree 
        int left_tree=inorder_rootindex-start_in;
        // generate the left subtree
        root->left=build(inorder,postorder,start_in,inorder_rootindex-1,start_post,start_post+left_tree-1);
        // generate the right subtree
        root->right=build(inorder,postorder,inorder_rootindex+1,end_in,start_post+left_tree,end_post-1);
        return root;
    }
};
