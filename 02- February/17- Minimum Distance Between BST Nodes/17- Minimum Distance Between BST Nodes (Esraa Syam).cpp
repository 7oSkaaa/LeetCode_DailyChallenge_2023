// author: Esraa Syam
class Solution {
public:
   // create a vector to store the nodes 
   // use inorder traversal to fill the vector with the nodes
    vector < int > nodes;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root -> left);
        nodes.push_back(root -> val);
        inorder(root -> right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int ans = INT_MAX;
        // iterate over the vector and find the minimum difference
        // between two adjacent nodes
        for(int i = 1 ; i < nodes.size() ; i++){
            ans = min(ans , nodes[i] - nodes[i - 1]);
        }
        return ans;
        
    }
};