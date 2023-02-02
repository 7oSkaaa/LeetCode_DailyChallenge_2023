/**
 * Author: Mahmoud Gadallah
 * LeetCode Account: https://leetcode.com/m7moudGadallah/
*/
#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
# Intuition
how we know two trees is same?
- if they have the same nodes with same values

# Approach
so we will traverse 2 trees and check if they already have the same number of nodes and the same values then they are the same otherwise they are not same

# Complexity
- Time complexity: O(N)

- Space complexity:
    O(1) without considering stack calls otherwise it will be O(h) where h is the height of tree
*/

class Solution {
private:
    bool same;
    void dfs(TreeNode *p, TreeNode *q) {
        if (!p and !q)      return;

        if (!p or !q or p->val != q->val) {
            same = false;
            return;
        }

        dfs(p->left, q->left);
        dfs(p->right, q->right);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        same = true;
        dfs(p, q);
        return same;
    }
};