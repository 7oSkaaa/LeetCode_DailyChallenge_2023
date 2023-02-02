# Author: Lobna Mazhar

class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # if length of str1 is longer return the same method swapped to make sure that str1 length is shorter
        if len(str1) > len(str2): return self.gcdOfStrings(str2, str1)

        for i in range(len(str1), 0, -1):
            # str1 or str2 can't be made by i characters
            if len(str1) % i != 0 or len(str2) % i:
                continue

            # No. of repititions required to make up each string
            count1, count2 = len(str1) // i, len(str2) // i
            # set the prefix as the full string till character at i index
            prefix = str1[:i]
            # if the first string is equal to the current prefix with repititions count1 and the same for count2 then use that prefix
            if str1 == count1 * prefix and str2 == count2 * prefix:
                return prefix
        return ""

        