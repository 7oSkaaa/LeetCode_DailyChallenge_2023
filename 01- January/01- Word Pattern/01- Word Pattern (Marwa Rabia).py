# Author: Marwa Rabia 

class Solution(object):
    def wordPattern(self, pattern, s):
        """
        Given a pattern and a string s, determine if s follows the same pattern.
        A pattern is a sequence of characters, where each character in the pattern
        corresponds to a word in s.
        
        Parameters:
            pattern (str): a sequence of characters.
            s (str): a string.
            
        Returns:
            bool: True if s follows the same pattern as pattern, False otherwise.
            
        Example:
            wordPattern("abba", "dog cat cat dog") -> True
            wordPattern("abba", "dog cat cat fish") -> False
            wordPattern("aaaa", "dog cat cat dog") -> False
            wordPattern("abba", "dog dog dog dog") -> False
        """


        s = s.split()
        n = len(pattern)
        m = len(s)
        if n!=m:
            return False
        dic = {}
        for i,j in zip(pattern,s):
            # check if the character in the pattern is already a key in the dictionary and
            # check if the corresponding value in the dictionary is equal to the current word in s.
            if (i in dic and j!=dic[i]):
                return False
            dic[i] = j
            # check if the number of unique values in the dictionary is equal to the number of unique keys
            if len(set(dic.values()))!=len(set(dic.keys())):
                return False
        return True
       
