// Author: Mina Magdy

class Solution {
public:
    // first: min depth ,   second: max depth
    pair<int, int> trave(TreeNode* root, bool& valid) {
        if (!root) return {0, 0};
        pair<int, int> p1 = trave(root->left, valid);
        pair<int, int> p2 = trave(root->right, valid);
        // all right depths must be less than or equal to left depths
        if (p2.second > p1.first) valid = false;
        pair<int, int> res = {1 + min(p1.first, p2.first), 1 + max(p1.second, p2.second)};
        // max depth dx, min depth dn this condition should be satisfied for complete binary tree.
        // 0 <= dx - dn <= 1
        if (res.second - res.first > 1) valid = false;
        return res;
    }
    bool isCompleteTree(TreeNode* root) {
        bool valid = true;
        trave(root, valid);
        return valid;
    }
};
