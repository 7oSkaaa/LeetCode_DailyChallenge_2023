# Author: Eslam Ezzat

# Time Complexity: O(Nlog(N))

# Space Complexity: O(N)

class Solution:
    def minimumRounds(self, tasks: list[int]) -> int:
        dic = {}  # making dictionary to store key,value pairs.

        result = 0  # variable result used to store the result.

        # Iterate through the list
        for i in tasks:
            if i in dic:  # check if element exists in dictionary or not.
                dic[i] += 1  # if the element exits, it increases the value by 1.
            else:
                dic[i] = 1  # store key and value in dictionary

        # Iterate through the dictionary.
        for i in dic:
            if dic[i] == 1:  # if the value of key is one, it returns -1.
                return -1
            elif dic[i] % 3 == 0:  # if the value  divisible by 3,it divides by 3
                result += dic[i] // 3
            else:
                result += (dic[i] // 3) + 1  # it divides by 3 plus one.
        return result
