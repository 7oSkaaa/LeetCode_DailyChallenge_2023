// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
    Recursive Solution: check if the left and right subtrees of the nodes are the same
    Iterative Solution: get the level order traversal of each level and check if the level is a palandrom or not
*/
class SolutionRecursive
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        else
            return is_same(root->left, root->right);
    }
    bool is_same(TreeNode *node1, TreeNode *node2)
    {
        if (!node1 || !node2)
            return node2 == node1;

        return node1->val == node2->val ? (is_same(node1->left, node2->right) && is_same(node1->right, node2->left)) : false;
    }
};
class SolutionIterative
{
public:
    bool isSymmetric(TreeNode *root)
    {
        deque<TreeNode *> q;
        q.push_front(root);
        while (q.size())
        {
            int tempSize = q.size();
            while (tempSize--)
            {
                auto node = q.back();
                q.pop_back();
                if (node)
                    q.push_front(node->left), q.push_front(node->right);
            }
            int l = 0;
            int r = q.size() - 1;
            while (l <= r)
            {
                auto left = q[l];
                auto right = q[r];
                if ((!left && right) || (!right && left))
                    return false;
                if ((!left && !right) || (left->val == right->val))
                    l++, r--;
                else
                    return false;
            }
        }

        return true;
    }
};