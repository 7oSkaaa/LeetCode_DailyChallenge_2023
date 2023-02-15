# Author: Ahmed Gamal

defmodule Solution do
  # for this problem we need to add two arrays of integers (one is a list already and the other is an integer)
  # so we need to convert the integer to a list of integers (using Integer.digits/1)
  # then we need to reverse both lists (because we need to add from the least significant digit)
  # then we need to add the two lists and we will use add/7 (which is a recursive function)
  # add/7 will take the two lists, the index of the current digit, the carry, the length of the first list, the length of the second list and the result list
  # if the index is greater than the length of both lists then we will return the result list (if there is a carry we will add it to the result list)
  # otherwise we will add the current digit to the result list and call add/7 with the next index and the carry (if there is one)
  # the current digit is the sum of the current digit of the first list (if the index is less than the length of the first list) and the current digit of the second list (if the index is less than the length of the second list) and the carry
  # the carry is the quotient of the current digit divided by 10
  # the current digit is the remainder of the current digit divided by 10

  # import the Enum module to use the at/2 function
  import Enum

  @spec add_to_array_form(num :: [integer], k :: integer) :: [integer]
  def add_to_array_form(num, k) do
      # convert the integer to a list of integers and reverse it
      dig = k |> Integer.digits() |> reverse()

      # reverse the first list and add the two lists
      add(reverse(num), dig, 0, 0, length(num), length(dig))
  end

  # function clause for default value of res
  defp add(_a, _b, _idx, _carry, _len_1, _len_2, res \\ [])

  # function clause for when the index is greater than the length of both lists (base case)
  defp add(_a, _b, idx, carry, len_1, len_2, res)
      when idx >= len_1 and idx >= len_2 do
          cond do
              carry > 0 -> [carry | res]
              true -> res
          end
  end

  # function clause for when the index is less than the length of either list
  defp add(a, b, idx, carry, len_1, len_2, res) do
    # the current digit is the sum of the current digit of the first list (if the index is less than the length of the first list) and the current digit of the second list (if the index is less than the length of the second list) and the carry
    d = (idx < len_1 && at(a, idx) || 0) + (idx < len_2 && at(b, idx) || 0) + carry

    # pass the carry to the next call as div(d, 10)
    # pass the current digit to the next call as rem(d, 10) and add it to the result list
    add(a, b, idx + 1, div(d, 10), len_1, len_2, [rem(d, 10) | res])
  end
end
