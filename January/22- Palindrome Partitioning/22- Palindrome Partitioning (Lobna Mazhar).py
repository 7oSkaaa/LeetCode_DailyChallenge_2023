# Author: Lobna Mazhar

class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = set()
        # Start by making possible palindromes from index 0 with empty values and empty current data
        self.make(s, 0, [], [], res)
        return res
    
    def make(self, s, index, values, current, res):
        # If we reached the end of the string
        if index == len(s):
            # If all the values were used and no remaining current items and all the values list is palindrome, add it to the final result
            if not current and self.checkPalindrome(values):
                res.add(tuple(values))
            return

        # Make 2 calls for making the possible palindrome, 
        # First one is to use the current character along with the current values from previous iterations and sending a new empty current array
        self.make(s, index + 1, values + [''.join(current + [s[index]])], [], res)
        # Second one is to save the current character for the next itiration and send the values as it is
        self.make(s, index + 1, values, current + [s[index]], res)

    # Check if given list's values are all palindrome
    def checkPalindrome(self, values):
        for value in values:
            if not self.isPalindrome(value):
                return False
        return True

    # Check if given string is palindrome
    def isPalindrome(self, s):
        middle = (len(s) + 1) // 2
        for i in range(middle):
            if s[i] != s[len(s) - 1 - i]: return False
        return True

