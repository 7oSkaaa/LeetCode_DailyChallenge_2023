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
 // author : Ahmed Zedan 
class Solution {
public:
    // solve by BFS 
    int maxDepth(TreeNode* root) {
        if(!root) return 0 ; 
        queue<TreeNode*>bfs ; 
        bfs.push(root) ; 
        int depth=0 ;
        while(bfs.size()){
            int sz = bfs.size() ;  // size of level 
            depth ++ ; 
            while(sz--){
                auto curr = bfs.front() ;
                bfs.pop() ;  
                // enter next level 
                if(curr->left) bfs.push(curr->left) ;
                if(curr->right) bfs.push(curr->right) ;  
            }
        }
        return depth ; 
    }
};