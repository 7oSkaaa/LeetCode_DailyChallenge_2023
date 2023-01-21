class Solution:
   def minimumRounds(self, tasks: list[int]) -> int:
    dic = {}
    result = 0
    for i in tasks:
        if i in dic:
            dic[i] += 1
        else:
            dic[i] = 1
    for i in dic:
        if dic[i] == 1:
            return -1
        elif dic[i] % 3 == 0:
            result += dic[i] // 3
        else:
            result += (dic[i] // 3) + 1
    return result