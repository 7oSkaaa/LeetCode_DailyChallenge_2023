// Author: Ahmed Gamal

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var preorderTraversal = function(root) {
    // we will use the dfs for traversing the tree and printing the preorder traversal of its nodes' values
    // the preorder traversal is defined as: root -> left -> right
    // so we will print the root first, then the left subtree, then the right subtree
    // we will use recursion to implement the dfs
    // we will use an array to store the values of the nodes in the preorder traversal order
    // we will return this array at the end of the function
    // we will pass the root node to the dfs function
    // the dfs function will print the root node, then call itself for the left and right subtrees
    // the base case of the dfs function is when the root node is null, in this case, we will return
    // the time complexity of this solution is O(n) because we will visit each node once
    // the space complexity of this solution is O(n) because we will store the values of the nodes in an array


    let ans = []
    
    // this is the recursive implementation of dfs
    let dfs = (src) => {
        // if the root node is null, return
        if(!src)
            return;
        // print the root node
        ans.push(src.val);
        // call dfs for the left subtree
        dfs(src.left);
        // call dfs for the right subtree
        dfs(src.right);
    }

    // call dfs for the root node
    dfs(root);

    // return the array of the values of the nodes in the preorder traversal order
    return ans;
};