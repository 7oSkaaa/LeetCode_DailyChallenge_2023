# Author: Noura Algohary
# Use sliding window 

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowelsCnt = 0
        
        for i in range(k):
            if s[i] in ['a', 'e', 'i', 'o', 'u']:
                vowelsCnt += 1
        
        maxVowels = vowelsCnt

        for i in range(k, len(s)):
            if s[i] in ['a', 'e', 'i', 'o', 'u']:
                vowelsCnt += 1
            
            if s[i - k] in ['a', 'e', 'i', 'o', 'u']:
                vowelsCnt -= 1
            
            if vowelsCnt > maxVowels:
                maxVowels = vowelsCnt
        
        return maxVowels