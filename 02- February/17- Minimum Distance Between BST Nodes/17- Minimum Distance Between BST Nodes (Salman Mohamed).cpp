// Author : Salman 
// Again bst main idea for me is to store all nodes and sort them and loop on them to 
// find out the smallest diffrence
class Solution {
	// making a global vector to store the nodes using recursive function to traverse the tree

    vector<int> node; 

    void tr(TreeNode* root){
        if(root==NULL) return;
         node.push_back(root->val);
        tr(root->left);
        tr(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        tr(root); 
        int miny=INT_MAX;
	// sort and find the miny and that it ;
        sort(node.begin(),node.end());
        for(int i=0; i<node.size()-1;i++){
            miny=min(miny,node[i+1]-node[i]);
        }
        return miny; 
    }
};