/*
    Author : Hamza Hassanain
*/
/*

    Approach:
        1- store the depth of each node with the node in the queue
        2- store the value of the node at the depth in the map
        3- go over the map and add the array to the ressult
*/
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        map<int, vector<int>> semiRes;
        vector<vector<int>> res;
        if (!root)
            return res;

        queue<pair<int, TreeNode *>> q;
        q.push({0, root});
        semiRes[0].push_back(root->val);
        while (q.size())
        {
            auto [depth, node] = q.front();
            q.pop();
            if (node->left)
            {
                q.push({depth + 1, node->left});
                semiRes[depth + 1].push_back(node->left->val);
            }
            if (node->right)
            {
                q.push({depth + 1, node->right});
                semiRes[depth + 1].push_back(node->right->val);
            }
        }
        bool alter = false;
        for (auto [i, vals] : semiRes)
        {
            if (alter)
                reverse(vals.begin(), vals.end());
            res.push_back(vals);
            alter = !alter;
        }

        return res;
    }
};