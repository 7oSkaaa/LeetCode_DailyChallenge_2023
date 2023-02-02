# Author: Mohamed Aly Elsayed Matar

class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        # counter to count how many deletions
        counter = 0
        # len(strs[0]) gives me the number of columns
        for col in range(len(strs[0])):
            # len(strs) gives me the number of rows
            # minus 1 to avoid the array index error while comparing with the next char when adding 1
            for row in range(len(strs)-1):
                # comparing the current char with the next char
                if (strs[row][col])>(strs[row+1][col]):
                    # if greater than, then increment the counter
                    counter += 1
                     # and break from the loop and enter the next column since no need to continue
                    break
        return counter