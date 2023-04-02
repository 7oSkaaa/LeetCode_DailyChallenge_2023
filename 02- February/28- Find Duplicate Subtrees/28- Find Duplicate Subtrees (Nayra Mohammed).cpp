//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
    /*
        - By traversing through our tree,Find all possible subtrees and their occurrence
        - If a subtree occurred more than once,then we store only one root having that subtree
        - We will store our subtrees as a vector of their values "parent values,all left childs,all right child" 
    */
public:
    
    map<vector<int>, int> mp; //to trace the occurrence of subtrees
    vector<TreeNode *> ans; // store our answer
    
    vector<int> AllSubtrees(TreeNode *st)
    {
        if (!st) //in case our current node is NULL then we return with any value that won't ever exists in our tree 
            return {201};
        
        vector<int> v, l, r;
        /*
         - v -> to store the whole subtree starting from current node
         - l -> to store the left subtree of current node
         - r -> to store the right subtree of current node
        */

        v.push_back(st->val);// push current node value "current parent node"
        
        l = AllSubtrees(st->left);// find left subtree
        r = AllSubtrees(st->right);// find right subtree
        
        for (auto it : l)// store l's value in v
            v.push_back(it);

        for (auto it : r)// store r's value in v
            v.push_back(it);

        if (mp[v] == 1)// if currrent subtree occurred before then we will store current node as it represents a duplicated subtree
            mp[v]++, ans.push_back(st);
        
        mp[v]++;// increment the occurrence of current subtree

        return v;// return subtree 
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        AllSubtrees(root);

        return ans;// return all nodes that represent dublicated subtrees
    }
};
