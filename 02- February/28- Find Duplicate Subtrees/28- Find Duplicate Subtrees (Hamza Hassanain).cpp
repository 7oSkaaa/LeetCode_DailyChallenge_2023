// Author: Hamza Hassanain
#include <bits/stdc++.h>
using namespace std;
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
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<TreeNode *> res; // our result
    map<string, int> cnts;  // store the string representaion of each node and its count
    // if the strings count is more than one we know that we have found a doubliacte
    map<string, TreeNode *> nodes; // sotre the string with the node it repersents
    string serilizes(TreeNode *node)
    {
        if (!node)
            return "N";
        string left = serilizes(node->left);
        string right = serilizes(node->right);
        string serilized = to_string(node->val) + "->" + left + "->" + right;

        nodes[serilized] = node;
        cnts[serilized]++;

        return serilized;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        serilizes(root);

        for (auto [str, cnt] : cnts)
        {
            if (cnt >= 2)
                res.push_back(nodes[str]);
        }
        return res;
    }
};