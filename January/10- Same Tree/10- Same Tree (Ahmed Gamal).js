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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */

var isSameTree = function(p, q) {
    // if the two trees are the same, then they have the same preorder traversal
    // so we will use dfs to compare the two trees and check if there is a mismatch
    // we will use dfs to compare the two trees
    // a base case of the dfs function is when both trees are null, in this case, we will return true
    // another base case of the dfs function is when one of the trees is null and the other is not, in this case, we will return false
    // another base case of the dfs function is when the values of the two trees are not equal, in this case, we will return false
    // if we reach the point after base cases, we will call the dfs function for the left and right subtrees of the two trees to compare them recursively
    // we will return the result of the dfs function for the left and right subtrees of the two trees (the result will be true if there is no mismatch)
    
    // the time complexity of this solution is O(n) because we will visit each node once
    // the space complexity of this solution is O(n) because we will use the call stack to implement the dfs

    let dfs = (first, second) => {
        // base cases
        // if one of the trees is null and the other is not, return false
        if(!(first && second) && first !== second)
            return false;
        // if both trees are null, return true
        if(!first)
            return true;
        // if the values of the two trees are not equal, return false
        if(first.val !== second.val)
            return false;

        // call dfs for the left and right subtrees of the two trees
        // if there is a mismatch, return false, otherwise, return true
        let ok = true;
        ok &= dfs(first.left, second.left);
        ok &= dfs(first.right, second.right);

        // return the result of the dfs function for the left and right subtrees of the two trees
        return ok;
    }

    // call dfs for the two trees and return the result
    return dfs(p, q);    
};