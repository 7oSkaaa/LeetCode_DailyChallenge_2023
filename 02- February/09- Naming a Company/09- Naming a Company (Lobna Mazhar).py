# Author: Lobna Mazhar

class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        suffix = defaultdict(list)
        for i in range(len(ideas)):
            suffix[ideas[i][0]].append(ideas[i][1:])
            
        res = 0
        for s1 in suffix:
            for s2 in suffix:
                common_count = len(set(suffix[s1]) & set(suffix[s2]))
                res += (len(suffix[s1]) - common_count) * (len(suffix[s2]) - common_count)
        return res
