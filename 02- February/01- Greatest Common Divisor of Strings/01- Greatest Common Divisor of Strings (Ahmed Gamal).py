# Author: Ahmed Gamal

# for this problem we will just use brute force to find the answer (the longest common prefix that is a divisor of both strings)
# because the constraints are small
# actually, I'm using python because it's easier to implement the brute force solution in python (easier to check if a string is a multiple of another string and easier to slice a string)

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # n: length of str1
        # m: length of str2
        n, m = len(str1), len(str2)

        # ans: the answer (the longest common prefix that is a divisor of both strings)
        ans = ''

        # i: the index of the current character in the common prefix
        # curr: the current common prefix
        # size: the length of the current common prefix

        # we will iterate over the length of the shortest string (because the longest common prefix can't be longer than the shortest string)
        # we will check if the current character is the same in both strings
        # if it's not, we will break the loop
        for i in range(min(n, m)):
            if str1[i] != str2[i]:
                break
            # if the current character is the same in both strings, we can get the current common prefix by slicing the first string from the beginning to the current index
            curr = str1[:i + 1]
            size = len(curr)
            
            # if the current common prefix's length is not a divisor of both strings' lengths, it can't be the answer
            if n % size != 0 or m % size != 0:
                continue

            # we can check if the current common prefix is a divisor of both strings by checking if constructs the strings by repeating it (str's length // prefix's length) times
            # if it does, it can be the answer
            if curr * (n // size) == str1 and curr * (m // size) == str2:
                ans = curr
                
        return ans