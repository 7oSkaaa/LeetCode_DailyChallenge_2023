# Author: Mohamed Aly Elsayed Matar

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # check if the word is only one letter
        # and if it is, then return True since it doesn't matter if it is captial or no
        if len(word) == 1:
            return True
        # isupper() checks if the whole word is uppercase or not
        elif word.isupper():
            return True
        # islower() checks if the whole word is lowercase or not
        elif word.islower():
            return True
        # check if the first letter is uppercase and the rest is lowercase
        elif word[0].isupper() and word[1:].islower():
            return True
        # other than that return False
        else:
            return False
