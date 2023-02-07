# Author: Lobna Mazhar

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s): return []
        # Make counter for s and p string characters by length of p string
        s_counter, p_counter = defaultdict(int), defaultdict(int)
        for i in range(len(p)):
            s_counter[s[i]] += 1
            p_counter[p[i]] += 1

        res = []

        # If the starting counters are equal, add 0 index to the finla result res
        if s_counter == p_counter: res.append(0)

        # Loop on the length of string s starting from length of string p,
        # For each index add its s character to the counter and remove (index - length of p) s character from counter
        # If the 2 counters are the same, add starting index to the final result res
        for i in range(len(p), len(s)):
            s_counter[s[i]] += 1
            s_counter[s[i-len(p)]] -= 1
            if s_counter[s[i-len(p)]] == 0: del s_counter[s[i-len(p)]]
            if s_counter == p_counter: res.append(i - len(p) + 1)
        return res
