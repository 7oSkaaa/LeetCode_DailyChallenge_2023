// Author: Ahmed Gamal

// for this problem, we will use inorder traversal to get the elements of the BST in sorted order
// but first, let's see how to get the answer from a sorted array
// let's say we have the following array: [1, 2, 3, 4, 5]
// the answer will be the minimum difference between each element and the next one (two consecutive elements)
// so the answer will be min(2 - 1, 3 - 2, 4 - 3, 5 - 4) = 1
// now, let's see how to get the answer from a BST
// since the elements of the BST are sorted, we can use inorder traversal to get the elements in sorted order
// so we can use the same approach as above: get the minimum difference between each element and the last accessed element
// to keep track of the last accessed element, we will use a variable called lst
// we will initialize it with a very large value (2e9) to make sure that the first element will be the minimum difference
// then, we will do the inorder traversal and update the answer and the last accessed element

class Solution {
    // lst: the last accessed element
    int lst;
public:

    // constructor
    Solution() {
        // initialize lst with a very large value
        lst = 2e9;
    }

    int getMinimumDifference(TreeNode* root) {
        // if the current node is null, return a very large value
        if(not root) {
            return 2e9;
        }

        // get the answer from the left subtree
        int ans = getMinimumDifference(root -> left);

        // update the answer and the last accessed element
        ans = min(ans, abs(lst - root->val));
        lst = root->val;

        // get the answer from the right subtree
        ans = min(ans, getMinimumDifference(root -> right));

        // return the answer
        return ans;
    }
};