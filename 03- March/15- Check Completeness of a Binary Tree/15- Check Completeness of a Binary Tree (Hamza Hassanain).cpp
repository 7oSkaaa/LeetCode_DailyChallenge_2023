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
    Approach:
        Run a bfs on the tree and if the current level is not full we mark this level and
        if this level is not the last one we return false.
        Inside the bfs if we find a nullptr followed by node we return false as this means
        the node is not left most
*/
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        int level = 0;
        deque<TreeNode *> q;
        q.push_back(root);
        int errorLevel = -1;

        while (q.size())
        {
            int tempSize = q.size();
            if (errorLevel == -1 && tempSize < pow(2, level))
            {
                errorLevel = level;
            }
            while (tempSize--)
            {
                auto node = q[0];
                q.pop_front();
                if (!node)
                {

                    if (tempSize && q[0])
                        return false;
                    continue;
                }
                q.push_back(node->left);
                q.push_back(node->right);
            }
            level++;
        }
        return errorLevel == -1 ? true : errorLevel == level - 1;
    }
};