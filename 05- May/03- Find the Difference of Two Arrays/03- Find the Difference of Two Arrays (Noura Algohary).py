# Author: Noura Algohary
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        differences = [[], []] 

        for num in nums1:
            # num exists in nums1 and not in nums2
            # num is not present in the list 
            if num not in nums2 and num not in differences[0]:
                differences[0].append(num)


        for num in nums2:
            # num exists in nums2 and not in nums1
            # num is not present in the list 
            if num not in nums1 and num not in differences[1]:
                differences[1].append(num)   

        return differences  