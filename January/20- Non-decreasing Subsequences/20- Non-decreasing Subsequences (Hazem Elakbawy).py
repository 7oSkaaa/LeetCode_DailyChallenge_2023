# Author : Hazem Elakbawy
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:

        # create set to avoid duplicate sub_sequences
        res=set()
        # current sub_seq
        seq=[]

        def get_sub_seq(i):
            
            # if we reached end of nums and valid seq
            if i == len(nums) and len(seq)>=2:
                res.add(tuple(seq))
                return
            # if we reached end of nums with no valid seq
            elif i == len(nums):
                return
            # if next element > = end of prev seq
            if len(seq) == 0  or nums[i]>=seq[-1]:
                # add current element to seq
                # then continue with it
                seq.append(nums[i])
                get_sub_seq(i+1)
                # then remove it and recurse on prev seq
                seq.pop()
            # if we didnt find element recurse to next element
            get_sub_seq(i+1)

        get_sub_seq(0)
        return res



