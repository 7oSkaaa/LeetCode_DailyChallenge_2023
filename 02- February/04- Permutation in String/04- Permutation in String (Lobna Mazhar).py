# Author : Lobna Mazhar

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        # If the length of the second string is smallers, return False, no permutation of the first string can exist
        if len(s2) < len(s1): return False

        # Make a dictionary counter for s1 letters
        s1Original = defaultdict(int)
        for i in range(len(s1)): s1Original[s1[i]] += 1

        # Loop on the second string full length decrementing the length of the first string, as the last s1 length's indices can't have permutation so no need to check
        # using a copy of s1 dictionary and counter for the remianing count from s1, loop from the current character to current + s1 length, if the found characters matches characters from s1, keep deceremnting
        # If remianing count reaches 0, return True a permutation was found
        # If a new character was found, break the loop and start the process again from the next s2 character
        for i in range(len(s2) - len(s1) + 1):
            s1Copy, s1Remaining = s1Original.copy(), len(s1)
            for j in range(i, i + len(s1)):
                if s1Copy[s2[j]] != 0:
                    s1Copy[s2[j]] -= 1
                    s1Remaining -= 1
                    if s1Remaining == 0: return True
                else: break
        
        # Return False as no permutations were found
        return False