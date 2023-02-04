# Author : Marwa Rabia 

class Solution(object):
    def minDeletionSize(self, strs):
        """
        This function takes in a list of strings and returns the minimum number of deletions needed 
        to make the list of strings sorted in lexicographic order.
        
        Parameters:
            strs (List[str]): The list of strings to be checked.
            
        Returns:
            int: The minimum number of deletions needed to make the list of strings sorted.
        """
        m=0
        s=''
        #check if the length of the first string in the list is less than or equal to 1
        if len(strs[0])<=1:
                if strs != sorted(strs):
                    return 1
                return m
        else:
                for i in range(len(strs[0])):               
                    for j in range(len(strs)):
                        s+=strs[j][i]
                    col=''.join(sorted(s))
                    # check if the concatenated string "s" is equal to "col"
                    # If it's not equal, it increments the "m" variable by 1. 
                    if s != col:
                        m+=1
                    s=''
        return m
        
              
            