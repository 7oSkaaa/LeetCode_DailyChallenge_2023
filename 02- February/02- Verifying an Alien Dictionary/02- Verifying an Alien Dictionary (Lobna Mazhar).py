# Author: Lobna Mazhar

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        # Make a dictionary to easily access the letters indices
        alphabet = {order[i] : i for i in range(len(order))}

        # Check if each word is lexicographically sorted compared to the previous word
        for i in range(1, len(words)):
            if not self.isLexicographical(alphabet, words[i-1], words[i]): return False
        return True

    def isLexicographical(self, alphabet: dict, word1: str, word2: str) -> bool:
        # For each letter in the smallest of the 2 words, compare the 2 letters at the same index
        # If the first word is larger than the second one then return False, they are not sorted
        # If the second word is larger than the first one then return True, they are sorted
        # If the 2 letters are equal then check the next letter
        for i in range(min(len(word1), len(word2))):
            if alphabet[word1[i]] > alphabet[word2[i]]: return False
            if alphabet[word2[i]] > alphabet[word1[i]]: return True
            if alphabet[word2[i]] == alphabet[word1[i]]: continue
        # At the end, the 2 words contain the same letters, return True if the first word is shorter or equal to the second word in length
        return len(word1) <= len(word2)
