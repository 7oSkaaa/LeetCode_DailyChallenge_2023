# Author: Noura Algohary
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        total_cnt = 0

        suffixes = [set() for _ in range(26)]

        for idea in ideas:
            suffixes[ord(idea[0]) - ord('a')].add(idea[1:]) # assign all the strings(withour first letter) to the first letter group

        for i in range(25):
            for j in range(i+1, 26):
                # counting mutual names produced by concatenating strings from 1 group to the other letter of a second group
                mutual_cnt = 0
                for suffix in suffixes[i]:
                    if suffix in suffixes[j]:
                        mutual_cnt += 1
                
                total_cnt += 2 * (len(suffixes[i]) - mutual_cnt) * (len(suffixes[j]) - mutual_cnt)
        
        return total_cnt