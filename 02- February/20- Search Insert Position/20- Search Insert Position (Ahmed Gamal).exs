# Author: Ahmed Gamal

defmodule Solution do
  @moduledoc """
  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
  we can use binary search to find the index of the target in the array if it exists, and if it doesn't we can return the index of the first element that is greater than the target (upper bound)
  """

  @spec search_insert(nums :: [integer], target :: integer) :: integer
  def search_insert(nums, target) do
      # first, we will convert the list to a tuple to make it more efficient to access its elements (O(1) instead of O(n) for lists)
      # then do a binary search to find the index of the target (left: -1, right: length(nums))
      idx = nums |> List.to_tuple() |> binary_search(-1, length(nums), target)

      # if the target is found, return its index, otherwise return the index of the first element that is greater than the target (upper bound)
      # this expression is equivalent to: if Enum.at(nums, idx) === target, do: idx, else: idx + 1
      Enum.at(nums, idx) === target && idx || idx + 1
  end

  # basic binary search algorithm
  defp binary_search(_tup, left, right, _target) when left === right - 1, do: left
  defp binary_search(tup, left, right, target) do
      mid = left - div(left - right, 2)
      x = elem(tup, mid)

      cond do
          x <= target -> binary_search(tup, mid, right, target)
          true -> binary_search(tup, left, mid, target)
      end
  end
end
