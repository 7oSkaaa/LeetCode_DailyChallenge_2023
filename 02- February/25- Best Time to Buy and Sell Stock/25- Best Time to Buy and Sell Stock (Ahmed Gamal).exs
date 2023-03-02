# Author: Ahmed Gamal

defmodule Solution do
  @moduledoc """
  Say you have an array for which the ith element is the price of a given stock on day i.
  if you want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock
  then you need to find the maximum difference between two prices in a sorted order in the array
  by thinking greedily, the element that would maximize the profit for the current day is the smallest element I have seen so far (if it is smaller than the current element)
  """

  @spec max_profit(prices :: [integer]) :: integer

  def max_profit([head | tail]) do
      get_ans(tail, head)
  end

  # base case (the maximum differece in an empty list is 0)
  defp get_ans([], _mn), do: 0

  defp get_ans([head | tail], mn) do
      # the maximum difference is the maximum of the current difference and the maximum difference in the rest of the list
      # if the minimum element is smaller than the current element, then maximize the difference by buying in it and selling in the current day
      # otherwise, try to maximize the difference by buying in the new minimum element and selling in the future
      max(head >= mn && head - mn || 0, get_ans(tail, min(mn, head)))
  end
end
