# Author: Lobna Mazhar

class Solution:
    def partitionString(self, s: str) -> int:
        # Start with res representing the result initialized by 1 as the minimum subsets, and a found set to track the presence of the characters over subsets
        res, found = 1, set()

        # Loop on the characters of the string
        for c in s:
            # If the letter was found before, increment the result by 1 and clear the found set
            if c in found:
                res += 1
                found.clear()
                
            # Add the current character to the found set
            found.add(c)

        # return the result
        return res
