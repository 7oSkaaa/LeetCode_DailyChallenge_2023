// Author: Ahmed Gamal

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

// for each node, find the closest node in the set (itself or the next or the previous)
// and update the minimum distance
// then insert the current node in the set
// and return the minimum distance


class Solution {
    // infinity value to return if the tree is empty
    #define inf 2000'000'000

    // set to store the nodes and find the closest node
    set<int> st;
public:
    
    int minDiffInBST(TreeNode* root) {
        // if the current node is null, return infinity
        if(not root)
            return inf;
        
        // find the closest node (initially infinity)
        int mn = inf;
        auto pos = st.lower_bound(root -> val);

        // if the current node is in the set, the minimum distance is 0
        if(pos != st.end() and *pos == root -> val){
            mn = 0;
        }else{
            // otherwise, find the closest node
            if(pos != st.end())
                mn = min(mn, abs(*pos - root -> val));
            if(pos != st.begin())
                mn = min(mn, abs(*prev(pos) - root -> val));
        }

        // insert the current node in the set
        st.insert(root -> val);

        // return the minimum distance between the current node and its closest node
        return min({mn, minDiffInBST(root -> left), minDiffInBST(root -> right)});
    }
};