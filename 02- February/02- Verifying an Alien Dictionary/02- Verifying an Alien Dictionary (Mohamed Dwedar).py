# Author: Mohamed Dwedar
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        # Create a mapping of characters to their positions in the given order
        # Iterate over the list of words and compare each consecutive pair
        # Compare character by character until one of the words runs out of characters
        # If First word has a greater character -> return False
        # If Second Word has a greater character -> return True
        # If First Word is less than or equal to Second -> return True
        # If First Word is greater than Second -> return False
        # If all pairs are in correct order -> return True 
        map = {}
        for i in range(len(order)):
            map[order[i]] = i
        for i in range(1, len(words)):
            first = words[i - 1]
            second = words[i]
            n = min(len(first), len(second))
            flag = False
            for j in range(n):
                if map[first[j]] < map[second[j]]:
                    flag = True
                    break
                elif map[first[j]] > map[second[j]]:
                    return False
            if not flag and len(first) > len(second):
                return False
        return True
