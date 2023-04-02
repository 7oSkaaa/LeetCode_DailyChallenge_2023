# Author: Ahmed Gamal

# this is the implementation of my solution in Elixir.
# for further explanation and other solutions' ideas, please refer to my solution in C++:
# https://github.com/AhmedGamal2212/LeetCode_DailyChallenge_2023/blob/main/02-%20February/21-%20Single%20Element%20in%20a%20Sorted%20Array/21-%20Single%20Element%20in%20a%20Sorted%20Array%20(Ahmed%20Gamal).cpp

defmodule Solution do
  @moduledoc """
  Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once.
  we can use binary search to find the index of the single element in the array
  """

  @spec single_non_duplicate(nums :: [integer]) :: integer
  def single_non_duplicate(nums) do
      n = length(nums)
      idx = nums |> List.to_tuple() |> upper_bound(-1, n, n) |> Kernel.+(1)
      Enum.at(nums, idx)
  end

  defp upper_bound(_tup, left, right, _size) when left == right - 1, do: left
  defp upper_bound(tup, left, right, size) do
      mid = left - div(left - right, 2)
      should_be = rem(mid, 2) !== 1

      if mid < size - 1 and (elem(tup, mid) === elem(tup, mid + 1)) === should_be do
          upper_bound(tup, mid, right, size)
      else
          upper_bound(tup, left, mid, size)
      end
  end
end
