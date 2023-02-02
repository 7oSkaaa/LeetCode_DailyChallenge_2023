# Author: Lobna Mazhar

class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        # Build a trie tracking all the words in the given list
        self.trie = {}
        for word in words:
            node = self.trie
            for c in word:
                if c not in node:
                    node[c] = {}
                node = node[c]
            node['*'] = True

        res = []
        # for each word check if it can be found through multiple shorter words
        for word in words:
            # If the word can be built from shorter words, add it to the final result
            if self.findWords(self.trie, word, 0, 0):
                res.append(word)
        return res
    
    def findWords(self, node, word, index, found):
        # If the end of the word was reached, check if it was composed of multiple words, return True, else False
        if index == len(word):
            return True if found >= 2 else False

        # For each character in the word, keep updating the current node from the tree if the character exists in the current node.
        for i in range(index, len(word)):
            # if the character doesn't exist, return False as the word can't be composed
            if word[i] not in node: return False
            # Update the current node
            node = node[word[i]]
            # If the current node is a word ending, starting from the next index check if the rest of the word can be found with starting from the head of the trie and incrementing the found count by 1
            if '*' in node:
                # If the word was built successfuly with shorter words, return True for that word
                if self.findWords(self.trie, word, i + 1, found + 1):
                    return True
        return False
