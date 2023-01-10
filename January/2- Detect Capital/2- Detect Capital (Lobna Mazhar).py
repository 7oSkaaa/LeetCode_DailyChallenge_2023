# Author: Lobna Mazhar

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        # Add a flag to check if the current character can be capital or not, default is true as the first character is allowed to be capital
        can_be_capital = True
        #  Loop on each character in the given word
        for i in range(len(word)):
            # First check if the current character is capital and it is allowed to be capital, then continue to the next one
            if word[i].isupper() and can_be_capital: continue
            # If not, check if it is a lower case character
            elif word[i].islower():
                # If the current character is lower case and it's either the first or the second character or it's already can't be capital, then it's valid and we can continue to the next one after changing our flag that all the next characters shouldn't be capital
                if i <= 1 or not can_be_capital: can_be_capital = False
                # Else if it's lower but it can't be lower as it's already a third or higher indexed character with all previous capital characters, then it is an invalid word, return False
                else: return False
            # Else if the character is capital but it can't be capital then it is an invalid word, return False
            else: return False
        # If all of the characters passed the checks with no errors, then it is a valid word, return True
        return True