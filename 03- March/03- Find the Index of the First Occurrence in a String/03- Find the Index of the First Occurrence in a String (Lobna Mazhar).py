# Author: Lobna Mazhar

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        # use two pointers to track the 2 strings
        haystack_pointer, needle_pointer = 0, 0
        # initial result is -1
        res = -1
        # Loop on the 2 strings while the 2 pointers are not exceeding the lengths
        while haystack_pointer < len(haystack) and needle_pointer < len(needle):
            # If the 2 characters are matched, set the res value if not set and increment the 2 pointers
            if haystack[haystack_pointer] is needle[needle_pointer]:
                if res is -1: res = haystack_pointer
                haystack_pointer += 1
                needle_pointer += 1
            # Else if they do not match, increment the haystack pointer by 1 if wasn't matched yet or set it to the prev result value + 1 and reset the result and needle_pointer to -1 and start index respectively
            else:
                if res is -1: haystack_pointer += 1
                else: haystack_pointer = res + 1
                res = -1
                needle_pointer = 0
        # If the needle pointer didn't reach the end (the haystack pointer was the loop breaker), set res to -1 as the needle string wasn't fully matched and return the res as the final result
        if needle_pointer != len(needle): res = -1
        return res