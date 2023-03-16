// Author: Ahmed Gamal

// for this problem we want to build the tree using the postorder and inorder traversals
// we can think of it as a divide and conquer problem where we divide the tree into two parts (left and right) and solve the problem for each part
// but the question is how to divide the tree into two parts? where to split the tree?
// we want to look at current problem (subtree) as finding the root of the tree and the left and right subtrees
// once we find the root we can use it to divide the tree into two parts (left and right) and solve the problem for each part to construct the left and right subtrees
// and while we are dividing the tree into two parts we can find that the resulting left and right intervals are also subtrees that we can solve the problem for them
// we keep doing this until we reach the base case (empty interval)
// while we are returning from the recursive calls we can construct the tree by connecting the left and right subtrees to the root

// a little observation: we can use the postorder traversal to find the root of the tree and the inorder traversal to divide the tree into two parts (left and right)
// another observation: the back of the postorder traversal is the root of the tree and if we pop it, the new back will be the root of the next right subtree of some tree
// that is because in the postorder traversal we visit the left subtree, then the right subtree, then the root
// so if we are visiting the postorder in reverse order, we will visit the root, then the right subtree, then the left subtree

// we can use a map to store the indices of the inorder traversal and use the current back of the postorder traversal as the root of the current tree
// after that, we divide the problem into two smaller problems: 1) from the current l to the index of the root in the inorder traversal - 1 (the left subtree) and 2) from the index of the root in the inorder traversal + 1 to the current r (the right subtree)
// we can use a default constructor to initialize the map with -1 for all values

// notice that we can't use the frequency array immediately because we can have negative values, so we can add 3000 to all values to make them non-negative (because the smallest value can be -3000 and the largest value can be 3000)
// so we are shifting the values to the right by 3000 to start from zero to 6000

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
class Solution {
    // idx[i] = index of i in the inorder traversal
    vector<int> idx;
public:

    Solution() {
        // initialize the map with -1 for all values
        // we need only 6001 values, but I used some extra space
        idx.assign(7000, -1);
    }

    TreeNode* build(int l, int r, vector<int>& postorder, vector<int>& inorder) {
        // base case: empty interval
        if(r < l) {
            return nullptr;
        }
        // val: the current root of the tree
        // val_idx: the index of the current root in the inorder traversal
        int val = postorder.back(), val_idx = idx[val + 3000];

        // create the current root
        auto curr = new TreeNode(val);
        
        // pop the current root from the postorder traversal
        postorder.pop_back();

        // divide the problem into two smaller problems (start from the right subtree because we are thinking of the postorder traversal in reverse order (as a stack)))
        // that means that the right subtree will be the next subtree to be visited and it will use the back of the postorder traversal as the root of the subtree first
        curr -> right = build(val_idx + 1, r, postorder, inorder);
        curr -> left = build(l, val_idx - 1, postorder, inorder);

        return curr;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // n: the size of the inorder traversal (the number of nodes in the tree)
        const int n = int(inorder.size());

        // store the indices of the inorder traversal
        for(int i = 0; i < n; i++) {
            idx[inorder[i] + 3000] = i;
        }

        // build the tree starting from the whole interval
        return build(0, n - 1, postorder, inorder);
    }
};