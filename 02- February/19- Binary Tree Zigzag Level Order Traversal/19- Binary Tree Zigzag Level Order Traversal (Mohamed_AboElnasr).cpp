/*
    Author : Mohamed AboElnasr
*/

/*
    It is a normal breadth-first traversal problem with just 
    inverting the even levels so
    I used the flag variable to indicate when to reverse the current level

    =========================the logic=======================
    - first create a queue of TreeNode* to save the pointers
    - push the root to it
    - keep iterating while the queue has values 
    - every iteration we do is to get the current level
        -1) get the size of the queue.
        -2) iterate size time over the queue and do the following 
            -> get the front element of the queue in  temporary variable and pop it from the queue
            -> push its left and right elements if exist
            -> push the current value of the temporary variable to the current-level vector
        -3) push the current-level to the ans according to the flag value(if we will reverse or not)
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int flag=1;
        while(!q.empty()){
            vector<int>curr_level;
            int level_siz=q.size();
            for(int i=0;i<level_siz;i++){
                TreeNode* curr_node=q.front();
                q.pop();
                if(curr_node->left) q.push(curr_node->left);
                if(curr_node->right)q.push(curr_node->right);
                curr_level.push_back(curr_node->val);  
            }
            if(flag==-1){
                reverse(curr_level.begin(),curr_level.end());
            }       
            ans.push_back(curr_level); 
            flag*=-1;   
        }
        return ans; 
    }
};