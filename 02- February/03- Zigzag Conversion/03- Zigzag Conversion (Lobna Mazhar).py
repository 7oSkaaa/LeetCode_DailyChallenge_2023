# Author: Lobna Mazhar

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        
        # Set incremental amount inc that will be used to increment the current index to the next expected index for a full column case
        inc = numRows - 1 + numRows - 2 + 1
        res = []
        # Append the chars row by row
        for i in range(numRows):
            index = i
            # Loop on the whole string with incrementing the current index by inc amount to jump to the next char as a full column
            while index < len(s):
                res.append(s[index])
                index += inc
                # If the current row is not the first or the last row, check if there is extra character existing for the middle rows
                if (i != 0 and i != (numRows-1)) and index - 2*i in range(0, len(s)):
                    res.append(s[index - 2*i])
        return ''.join(res)
                
            
        