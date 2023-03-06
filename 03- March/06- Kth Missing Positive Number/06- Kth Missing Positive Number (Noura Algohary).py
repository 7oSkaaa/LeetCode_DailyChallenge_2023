# Author: Noura Algohary
class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        num = 1  # the must be number
        toK = i = 0 3 # toK is how many of k occurred 

        while i != len(arr):

            if num != arr[i]:
                i -= 1  # stay at the same position not to skip a number [4, 8] must return [5, 6, 7]
                toK += 1

                if toK == k:
                    return num
                
            num += 1
            i += 1
        
        # if the missing numbers are limited with a last number 
        # return the k position after the last element in the array
        return num + k -1 - toK