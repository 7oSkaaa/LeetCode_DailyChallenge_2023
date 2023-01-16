# Author: Lama Salah


class Solution:

    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() == True :
            return True
        elif word.islower() == True:
            return True 
        elif word[0].isupper() and word[1:].islower():
            return True 
        return False