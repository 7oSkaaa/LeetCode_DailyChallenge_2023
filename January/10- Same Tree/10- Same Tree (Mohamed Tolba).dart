// Author: Mohamed Tolba

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;

  TreeNode([this.val = 0, this.left, this.right]);
}

class Solution {
  bool isSameTree(TreeNode? p, TreeNode? q) {
    // p & q are both null
    if (p == null && q == null) {
      return p == q;
    }
    // one of p and q is null
    if (p == null || q == null) return false;

    if (p.val == q.val) return isSameTree(p.right, q.right) && isSameTree(p.left, q.left);

    return false;
  }
}
