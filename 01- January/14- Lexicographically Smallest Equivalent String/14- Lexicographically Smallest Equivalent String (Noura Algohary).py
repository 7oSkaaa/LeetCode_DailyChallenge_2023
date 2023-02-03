# Author: Noura Algohary
import numpy as np
class Solution:
    def smallestEquivalentString(self, s1: str, s2: str, baseStr: str) -> str:
        equivalent = ""  # equivalent string to baseStr
       
        adjMat = np.zeros((26, 26), dtype=int)
        l1 = l2 = 0

        # first, impelement relation between each two letters into adjacency matrix
        for i in range(len(s1)):
            l1 = ord(s1[i]) - 97
            l2 = ord(s2[i]) - 97

            adjMat[l1][l2] = 1
            adjMat[l2][l1] = 1
        
        # store the minChar of each letter
        # begin with the char itself
        eq = [i for i in range(26)]

        visited = [False for i in range(26)]

        for ch in range(26):
            if not visited[ch]:
                minChar = ch
                group = []   # group of related or equal letters

                def dfs(ch, minChar):
                    visited[ch] = True

                    # add the char to the group of equevalent letters
                    group.append(ch)

                    minChar = min(ch, minChar)

                    for i in range(26):
                        if (adjMat[ch][i] and not visited[i]):
                            dfs(i, minChar)


                dfs(ch, minChar)

                for c in group:
                    eq[c] = minChar  # assign the min char of the group as equivalent to the rest

        for c in baseStr:
            # print(c)
            equivalent += chr(eq[ord(c) - 97] + 97)  
        
        return equivalent

