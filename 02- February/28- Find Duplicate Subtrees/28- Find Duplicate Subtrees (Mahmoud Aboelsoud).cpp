// Author: Mahmoud Aboelsoud

class Solution {
public:
    // 1. DFS to get all subtrees
    // 2. Store subtrees in a map
    // 3. Return all subtrees that have more than one occurence


    // map to store subtrees and their occurences
    map<vector<int>, vector<TreeNode*>> ma; 
    
    // dfs to get all subtrees
    vector<int> dfs(TreeNode* root){
        // if root equal NULL we return a value that is not possible to be in the tree
        if(root == NULL) return {2001};
        // vector to store the subtree
        vector<int> v;
        // push the root value
        v.push_back(root -> val);

        // push the left subtree
        vector<int> left = dfs(root -> left);
        for(auto&i: left)
            v.push_back(i);

        // push the right subtree
        vector<int> right = dfs(root -> right);
        for(auto&i: right)
            v.push_back(i);

        // push the root to the map of subtrees
        ma[v].push_back(root);

        // return the subtree
        return v;
    }


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // call dfs to get all subtrees
        dfs(root);

        // vector to store the answer
        vector<TreeNode*> ans;

        for(auto&[x,y] : ma)
            // if the subtree has more than one occurence we push one of them to the answer
            if(y.size() > 1) ans.push_back(y[0]);
        
        // return the answer
        return ans;
    }   
};
