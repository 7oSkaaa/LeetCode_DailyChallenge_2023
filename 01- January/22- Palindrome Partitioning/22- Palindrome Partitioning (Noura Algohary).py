# Author:Noura Algohary
class Solution:
    def isValid(self, s, st, end) -> bool:
        while st < end:
            if s[st] != s[end]:
                return False
            st += 1
            end -= 1
        return True

    def allPossiblePalindrome(self, palindrome, s, idx, branch):
        # solution is found 
        if len(s) == idx:
            palindrome.append(branch[:])    # add solution to other solutions
            return
        
        for i in range(idx, len(s)):
            if self.isValid(s, idx, i):
                branch.append(s[idx:i+1])
                self.allPossiblePalindrome(palindrome, s, i+1, branch)
                branch.pop(-1)

    def partition(self, s: str) -> List[List[str]]:
        palindrome = []
        branch = []
        self.allPossiblePalindrome(palindrome, s, 0, branch)
        return palindrome