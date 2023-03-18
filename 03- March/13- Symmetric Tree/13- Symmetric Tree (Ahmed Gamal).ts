// Author: Ahmed Gamal

// for this problem we can simply check if the left subtree is symmetric to the right subtree recursively
// we can do this by checking if the left subtree is symmetric to the right subtree
// and call the function recursively on the left subtree and the right subtree of each node
// we need all of the nodes to be symmetric to each other for the tree to be symmetric

/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */


// this function checks if the left subtree is symmetric to the right subtree
function checkSymmetry(first: TreeNode | null, second: TreeNode | null) {
    // if both are null then they are symmetric, if one is null and the other is not then they are not symmetric
    if(!first || !second)
        return first === second;

    // if the values are not equal then they are not symmetric
    if(first.val !== second.val)
        return false;
    
    // check if the left subtree of the left node is symmetric to the right subtree of the right node
    // and check if the right subtree of the left node is symmetric to the left subtree of the right node
    let symmetric: boolean = true;
    symmetric = symmetric && checkSymmetry(first.left, second.right);
    symmetric = symmetric && checkSymmetry(first.right, second.left);

    // return the result of the check
    return symmetric;
}

function isSymmetric(root: TreeNode | null): boolean {
    return checkSymmetry(root.left, root.right);
};