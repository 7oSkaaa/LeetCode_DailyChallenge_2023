// Author: Mina Magdy

class Solution {
public:
    int sumNumbers(TreeNode* root, int curr = 0) {
        // if the current node is NULL pointer return 0
        if (!root) return 0;
        // if the current node is a leaf node
        if (!root->left && !root->right) return curr * 10 + root->val;
        // go to the left node and the right node
        return sumNumbers(root->left, curr * 10 + root->val) + sumNumbers(root->right, curr * 10 + root->val);
    }
};

/*
===========================================
EXAMPLE: [1, 2, 3]
===========================================
REPRESENTATION:
           (1)
           / \
         (2) (3)
===========================================
TRACING:

NOTE: here [X] means that the following will happend

1st Frame: {
    root -> (1), curr = 0
    [ ] root is a null pointer 
    [ ] root is a leaf node
    [X] go Left && go Right with new value of curr,
        curr = curr * 10 + root->val = 0 * 10 + 1 = 1
},
2nd Frame: { // left of (1) is (2)
    root -> (2), curr = 1
    [ ] root is a null pointer 
    [X] root is a leaf node
        DO: return (curr * 10 + root->val) = (1 * 10 + 2) = 12
    [ ] go Left && go Right with new value of curr
}, NOTE: this top stack frame is deleted from stack memory after the return statement
3rd Frame: { // right of (1) is (3)
    root -> (3), curr = 1
    [ ] root is a null pointer 
    [X] root is a leaf node
        DO: return (curr * 10 + root->val) = (1 * 10 + 3) = 13
    [ ] go Left && go Right with new value of curr
}, NOTE: this top stack frame is deleted from stack memory after the return statement
===========================================
Stack Memory:

0- step: [main]
1- step: [main, 1st Frame] // first call for our function
2- step: [main, 1st Frame, 2nd Frame] // recursion to left node
3- step: [main, 1st Frame] // return of left node
4- step: [main, 1st Frame, 3rd Frame] // recursion to right node
5- step: [main, 1st Frame] // return of right node
6- step: [main] // return to main
===========================================
*/
