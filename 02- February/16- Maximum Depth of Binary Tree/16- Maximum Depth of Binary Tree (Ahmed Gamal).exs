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

# for this problem we need to find the maximum depth of a binary tree
# so we will use a recursive function to traverse the tree
# the maximum depth of the tree is the maximum depth of the left subtree and the maximum depth of the right subtree plus 1
# if the root is nil then the maximum depth is 0

defmodule Solution do
  @spec max_depth(root :: TreeNode.t | nil) :: integer

  def max_depth(root) do
      # this simulates the ternary operator in elixir (condition && true_value || false_value)
      # boolean operators in elixir behave like in javascript (&& and || are short-circuit operators and return the last value evaluated)

      root !== nil && 1 + max(max_depth(root.left), max_depth(root.right)) || 0
  end
end
