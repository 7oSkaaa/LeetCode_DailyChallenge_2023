// Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root) // if our tree is empty , contains no nodes then, the answer = 0
            return 0;

        // We gonna use BFS to traverse through the binary tree
        int mx = 0; // to store the maximum depth in the tree

        queue<pair<TreeNode *, int>> q; // queue to implement BFS. pair -> to store current node and in which level it is

        q.push({root, 1}); // push our first level

        while (sz(q))
        {
            pair<TreeNode *, int> st = q.front();
            q.pop();

            mx = max(mx, st.second); // update our answer with current reached depth

            // if there exists childs for our current node, then we push them as our upcoming level "depth" in the tree

            if (st.first->left)
                q.push({st.first->left, 1 + st.second});

            if (st.first->right)
                q.push({st.first->right, 1 + st.second});
        }

        return mx; // return maximum depth in the binary tree
    }
};
