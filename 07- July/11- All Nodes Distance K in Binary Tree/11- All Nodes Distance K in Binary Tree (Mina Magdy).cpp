// Author: Mina Magdy

class Solution {
public:
    // Vector to store the directions taken to reach the target node
    vector<int> dirs;
    // Temporary vector to track the directions during traversal
    vector<int> tmp;
    // Vector to store the nodes at distance k from the target
    vector<int> ans;

    // Function to perform DFS to find the directions to reach the target node
    void dfsDir(TreeNode* &root, TreeNode* &target) {
        if (!root)
            return;
        // If the current node is the target node, store the directions and return
        if (root == target) {
            dirs = tmp;
            return;
        }
        // Traverse left child and mark direction as 0
        tmp.push_back(0);
        dfsDir(root->left, target);
        tmp.pop_back();
        // Traverse right child and mark direction as 1
        tmp.push_back(1);
        dfsDir(root->right, target);
        tmp.pop_back();
    }

    // Function to perform DFS to find nodes at distance k from the target
    void dfs(TreeNode* &root, int k, int level = 0, bool sameSide = true, int lca = 0) {
        if (!root)
            return;
        int dist = 1e9;
        // Calculate the distance from the current node to the target node
        if (sameSide) {
            dist = abs(int(dirs.size()) - level);
        }
        else {
            dist = dirs.size() - lca + level - lca;
        }
        // If the distance is equal to k, add the current node to the answer vector
        if (dist == k)
            ans.push_back(root->val);
        // Check if the left child is on the same side as the target node
        bool flag1 = sameSide && (level < dirs.size() ? dirs[level] == 0 : 1);
        // Traverse left child with updated level and sameSide flag
        dfs(root->left, k, level + 1, flag1, (flag1 ? level + 1 : lca));
        // Check if the right child is on the same side as the target node
        bool flag2 = sameSide && (level < dirs.size() ? dirs[level] == 1 : 1);
        // Traverse right child with updated level and sameSide flag
        dfs(root->right, k, level + 1, flag2, (flag2 ? level + 1 : lca));
    }

    // Function to find nodes at distance k from the target
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Find the directions to reach the target node
        dfsDir(root, target);
        // Perform DFS to find nodes at distance k
        dfs(root, k);
        // Return the answer vector
        return ans;
    }
};
