# Author: Noura Algohary
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        # corner case
        if n==1:
            return 1
        
        trusts = [0] * (n+1)    # if the person [i] trusts anybody
        trusted = [0] * (n+1)   # count how many the person [i] is trusted 

        for i in range(len(trust)):
            trusts[trust[i][0]] += 1
            trusted[trust[i][1]] += 1

        max_count = max(trusted)    # find the most trusted count
        person = trusted.index(max_count)   # find the most trusted person (index of the most trusted count)

        # the number of trusted count is equal to n-1 and the same person doesn't trust anyone
        if(max_count == n-1 and trusts[person] == 0):   
            return person
        
        return -1