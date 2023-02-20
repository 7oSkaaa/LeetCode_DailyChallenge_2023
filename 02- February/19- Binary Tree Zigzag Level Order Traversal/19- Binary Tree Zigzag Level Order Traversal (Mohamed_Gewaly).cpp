// Author: Mohamed Gewaly


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
    
    /**
    Using Queue , placing the values at right indexes .

    **/
    vector<vector<int>>res; // result vector
    
    void print(TreeNode* root){
        int flag=1;
        if(!root) return; //if tree is empty
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){ //level order traversal
            
            int n= q.size();
            vector<int> arr(n);
            
            for(int i=0;i<n;i++){
               TreeNode* node = q.front();
              if(flag == 1) arr[i] = node->val;
              else arr[n-i-1] = node->val;      
                q.pop();
                // pushing next level into queue
            if (node->left != NULL)  q.push(node->left);
            if (node->right != NULL)  q.push(node->right);
           
    }
        res.push_back(arr);
        flag*=-1; // changing the order
        }
    }
        
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        print(root);  // level order binary tree traversal using Queue
        return res;  // result vector
        
        
    }
};