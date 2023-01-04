# Author: Lobna Mazhar

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words, word = [], ''
        # Loop on each character on the long string and make a list of words that are separated by a backspace
        for i in range(len(s)):
            # If the current character is a backspace, add the current word to the list
            if(s[i] == ' '):
                words.append(word)
                word = ''
            else:
                word += s[i]
        # Make sure to add the last word to the list
        if word != '': words.append(word)

        # If the lengths of the pattern and the list of words don't match, then they can't match each other
        if len(pattern) != len(words): return False

        # Make 2 dictionaries to map each character to a word and vice versa
        words_dict, pattern_dict = {}, {}
        # Loop on the length of the pattern (or the list of words, they are the same)
        for i in range(len(pattern)):
            # If the current pattern's letter exists in the word dictionary and is mapped to another word than the one it's facing now or If the current word exists in the pattern dictionary and is mapped to another character than the one it's facing now, then return False as the pattern and the string doesn't match each other
            if (pattern[i] in words_dict and words_dict[pattern[i]] != words[i]) or (words[i] in pattern_dict and pattern_dict[words[i]] != pattern[i]): return False

            # If they match each other, update the dictionaries
            words_dict[pattern[i]] = words[i]
            pattern_dict[words[i]] = pattern[i]
        # If all the characters and words passed the checks correctly, return True as they match each other
        return True