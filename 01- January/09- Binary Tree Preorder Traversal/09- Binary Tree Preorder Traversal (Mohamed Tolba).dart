// Author: Mohamed Tolba

class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;

  TreeNode([this.val = 0, this.left, this.right]);
}

class Solution {
  List<int?> preorderTraversal(TreeNode? root) {
    // add the value to the list and if tree-node is empty will return empty list
    List<int?> val = root != null ? [root.val] : [];

    // adding the value from left side
    List<int?> left = root?.left != null ? preorderTraversal(root?.left) : [];

    // adding the value from right side
    List<int?> right = root?.right != null ? preorderTraversal(root?.right) : [];

    return val + left + right;
  }
}

/*
=> Algorithm Preorder(tree)
1. Visit the root
2. Traverse the left subtree, i.e., call Preorder(left->subtree)
3. Traverse the right subtree, i.e., call Preorder(right->subtree)
 */
