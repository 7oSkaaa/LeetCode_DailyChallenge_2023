// Author: Ahmed Gamal

// for this problem, we want to return all the duplicate subtrees in the tree (one of each)
// to compare subtrees, we can use the inorder traversal of the tree, and compare the result of each subtree
// to do that, we can use a set to store the result of each subtree, and if we find a duplicate, we add it to the answer
// but we need to make sure that we don't add the same subtree twice, so we can use another set to store the used subtrees
// and if we find a duplicate, we check if it's already used, if not, we add it to the answer
// but we will face a problem, if we have a tree like this:
//       0
//      / \
//1 -> 0   0 <- 2
//    /   / \
//   0   0   0
//  /
// 0

// the 2 subtrees with value 0 will be the same, but they are not the same subtree, so we need to add a null value to the result of each subtree
// so instead of returning [0, 0, 0] for both of them, we will return [n, n, n, n, 0, n, 0, n, 0, n] and [n, n, n, 0, n, 0, n, n, 0, n] which are different
// notice that the null values are added before each subtree, even if it's a null subtree
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
 * @return {TreeNode[]}
 */
var findDuplicateSubtrees = function(root) {
    // found: set of all the subtrees
    // used: set of all the used subtrees (added to the answer)
    // ans: the answer
    let found = new Set(), used = new Set();
    let ans = [];

    // dfs function to get the inorder traversal of the tree
    let dfs = (src) => {
        // subTree: the result of the subtree (inorder traversal with null values added)
        let subTree = ['n'];
        
        // if the subtree is null, return the subTree (with the null value)
        if(!src){
            return subTree;
        }

        // get the result of the left subtree, the value of the current node, and the result of the right subtree
        subTree = subTree.concat(dfs(src.left), [src.val], dfs(src.right));
        
        // join the result of the subtree to a string, and check if it's already in the found set
        let subTreeKey = subTree.join(' ');

        // if it's already in the found set, check if it's already used, if not, add it to the answer
        if(found.has(subTreeKey)){
            if(!used.has(subTreeKey))
                ans.push(src);
            
            // add it to the used set
            used.add(subTreeKey)
        }

        // add it to the found set
        found.add(subTreeKey);

        // return the result of the subtree
        return subTree;
    }

    // call the dfs function
    dfs(root);

    // return the answer
    return ans;
};