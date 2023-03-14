// Author: Abdelrrahman Elhaddad

/*
- Intuition:
    To compare the left branch and the right branch we have to traverse both branches but in mirror way (like if we traversing the right branch entering the right node of each node first, then entering the left node we shall do the opposie while treversing left branch by entering the left node of each node first, then entering the right node) and store their elments, and compare branches values at the end.

- Approach:
    1- Initialize two vectors (rightBranch and leftBranch) to store branches values.
    2- Traverse right branch by entering the right node of each node first, then entering left node.
    3- Traverse left branch by entering the left node of each node first, then entering right node.
    4- Check if the size of rightBranch and leftBranch does not match, return false.
    5- If sizes match, compare each two values with the same index. If two elements does not match return false.
    6- If did not find any dismatchs in the loop then return true.

- Complexity:
    Time complexity: O(n)
    Space complexity: O(2∗n)
*/

class Solution
{
public:
    vector<int> right, left;

    // Function to traverse the right branch and store its values
    void storeValuesRight(TreeNode *node)
    {
        if (!node)
            return void(right.emplace_back(1000));

        right.emplace_back(node->val);
        storeValuesRight(node->left);
        storeValuesRight(node->right);
    }

    // Function to traverse the left branch and store its values
    void storeValuesLeft(TreeNode *node)
    {
        if (!node)
            return void(left.emplace_back(1000));

        left.emplace_back(node->val);
        storeValuesLeft(node->right);
        storeValuesLeft(node->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        storeValuesRight(root->right);
        storeValuesLeft(root->left);

        if (right.size() != left.size())
            return false;

        for (int i = 0; i < right.size(); i++)
            if (right[i] != left[i])
                return false;

        return true;
    }
};