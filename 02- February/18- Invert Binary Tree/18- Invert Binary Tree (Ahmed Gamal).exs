# Author: Ahmed Gamal

# Definition for a binary tree node.
#
# defmodule TreeNode do
#   @type t :: %__MODULE__{
#           val: integer,
#           left: TreeNode.t() | nil,
#           right: TreeNode.t() | nil
#         }
#   defstruct val: 0, left: nil, right: nil
# end

defmodule Solution do
  @moduledoc """
  Given the root of a binary tree, invert the tree, and return its root.
  to invert a binary tree means to swap every left node in the tree for its corresponding right node.
  we can do this recursively by swapping the left and right subtrees of a node and then calling the function recursively on the left and right subtrees.
  the base case is when we reach a leaf node, which we can just return nil in this case.
  the recursive case will be excuted before the swap, so it'll swap the subtrees from the bottom up.
  """

  @spec invert_tree(root :: TreeNode.t | nil) :: TreeNode.t | nil

    def invert_tree(nil), do: nil
    def invert_tree(root) do
        # return the root node with the left and right subtrees swapped after calling the function recursively on them
        %TreeNode{
            val: root.val,
            left: invert_tree(root.right),
            right: invert_tree(root.left)
        }
    end
end
