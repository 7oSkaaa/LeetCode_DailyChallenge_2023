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
    // use two pointer to check level symmetric or not 
    bool is_good(vector<TreeNode*>nodes){
        int l = 0 , r = nodes.size()-1 ; 
        while(l<r){
            if(!nodes[l]&&!nodes[r]) l++ , r-- ; 
            else if(!nodes[l]||!nodes[r]) return false ; 
            else if(nodes[l]->val!=nodes[r]->val) return false ; 
            else l++ , r-- ; 
        }
        return true ;
    }


    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*>bfs ; 
        bfs.push(root) ; 
        // bfs 
        while(!bfs.empty()){
            int sz = bfs.size() ; 
            vector<TreeNode*>tmp ; 
            while(sz--){
                auto curr = bfs.front() ; 
                bfs.pop() ; 
                tmp.push_back(curr->left) ; 
                tmp.push_back(curr->right) ;
                if(curr->left) bfs.push(curr->left) ; 
                if(curr->right) bfs.push(curr->right) ; 
            }
            if(!is_good(tmp)) return false ; // return false if current level not symmetric
        }      
        return true ;  
    }
};