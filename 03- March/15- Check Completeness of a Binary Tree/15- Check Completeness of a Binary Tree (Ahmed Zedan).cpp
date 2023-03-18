// author : Ahmed Zedan 
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
    /*
    * bfs approach 
    * if find null before node return false otherwise return true 
    */
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>bfs; 
        bfs.push(root) ; 
        bool isNull = false ; 
        while(!bfs.empty()){
            auto curr = bfs.front() ; 
            bfs.pop() ; 
            if(curr == nullptr){ // if find nullptr
                isNull = true ; 
                continue ; 
            }
            if(isNull) return false ;  // if find node after nullptr
            bfs.push(curr->left) ; 
            bfs.push(curr->right) ; 
        }
        return true ; 
    }
};