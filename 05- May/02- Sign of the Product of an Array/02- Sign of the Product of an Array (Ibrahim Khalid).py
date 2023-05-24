# Author : Ibrahim Khalid 
class Solution(object):
    def arraySign(self, nums):
        # to count negative numbers
        cnt_neg=0
        for x in nums:
            #  if equal 0 return 0;
            if(x==0):
                return 0
            if(x<0):
                cnt_neg+=1
        #if numbers of negative numbers is even then x is positive
        if( cnt_neg%2==0):
            return 1
        return -1
       
