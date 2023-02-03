# Author: Marwa Rabia 

class Solution(object):
    def detectCapitalUse(self, word):
        """
        Detects the capitalization of a given word.
        
        Parameters:
        word (str): The word to check the capitalization of.
        
        Returns:
        bool: True if the capitalization of the word is "Capitalized", "ALL_LOWERCASE" or "ALL_UPPERCASE"
            False otherwise.
        """
        # 1- check if the word is in Title case by capitalizing first letter of the word 
        # 2- check if the word is in lower case 
        # 3- check if the word is in upper case
        # and returns True if any of these conditions are met.
        return  word.capitalize()==word  or word.islower()  or  word.upper()==word 