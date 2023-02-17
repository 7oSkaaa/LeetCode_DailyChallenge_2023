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
  Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.
  we can use dfs to get all the values in the tree and then sort them and get the minimum difference between any two adjacent values
  1. get the pre-order traversal of the tree
  2. sort the array
  3. get the minimum difference between any two adjacent values
  """

  @spec min_diff_in_bst(root :: TreeNode.t | nil) :: integer
  def min_diff_in_bst(root) do
      # get the pre-order traversal of the tree and sort it
      # use list instead of tuple because it's faster to insert elements in the list than in the tuple
      tree = []
      tree = dfs(root, tree) |> Enum.sort()

      # convert the list to tuple (because it's faster to access tuple elements than list elements in elixir)
      # accessing the tuple elements is O(1) while accessing the list elements is O(n)
      tree |> List.to_tuple() |> get_diff(0, length(tree))
  end


  @spec dfs(root :: TreeNode.t | nil, tree :: list) :: list
  defp dfs(nil, tree), do: tree
  defp dfs(root, tree) do
      # insert the current node value in the tree
      tree = [root.val | tree]

      # traverse the left and right subtrees
      tree = dfs(root.left, tree)
      tree = dfs(root.right, tree)
  end

  @spec get_diff(tree :: tuple, i :: integer, n :: integer) :: integer
  # base case (if the current index is the last index in the tree, return infinity)
  defp get_diff(_tree, i, n) when i >= n - 1, do: :inf

  # recursive case (get the minimum difference between the current node and the next node)
  defp get_diff(tree, i, n) do
      x = elem(tree, i)
      y = elem(tree, i + 1)
      min(abs(x - y), get_diff(tree, i + 1, n))
  end
end
