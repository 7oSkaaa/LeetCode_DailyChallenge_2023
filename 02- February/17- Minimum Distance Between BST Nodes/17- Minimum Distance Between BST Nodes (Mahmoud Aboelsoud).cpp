// Author: Mahmoud Aboelsoud

class Solution {
public:
    // store all values in a vector and sort it
    // then find the minimum difference between any two adjacent values

    // vector to store all values
    vector<int> v;
    // function to build the vector
    void build(TreeNode* root){
        if(root == NULL) return;
        v.push_back(root -> val);
        build(root -> left);
        build(root -> right);
    }


    int minDiffInBST(TreeNode* root) {
        // build the vector
        build(root);
        // sort the vector
        sort(v.begin(), v.end());
        
        // find the minimum difference between any two adjacent values
        int ans = INT_MAX;
        for(int i = 1; i < v.size(); i++)
            ans = min(ans, v[i] - v[i - 1]);
        return ans;
    }
};
