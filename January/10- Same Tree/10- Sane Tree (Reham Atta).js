// Author: Reham Atta


/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {

    // is both are null return true
    if (p == null && q == null) return true;

    // if roots are equal in both trees check left and right subtree for each tree , are equal or not
    else if(p && q) {
        return p.val == q.val && isSameTree(p.left,q.left) && isSameTree(p.right,q.right);
    }

    // if the above condition not satisfied then return false
    else return false;
};
