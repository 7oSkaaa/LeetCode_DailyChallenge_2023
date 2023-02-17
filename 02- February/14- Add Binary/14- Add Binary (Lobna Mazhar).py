# Author: Lobna Mazhar

class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) > len(b): return self.addBinary(b, a)
        carry, res = 0, []
        values = {0:('0',0), 1:('1',0), 2:('0',1), 3:('1',1)}
        for i in range(1, len(a) + 1):
            value = carry + int(a[-i]) + int(b[-i])
            res.append(values[value][0])
            carry = values[value][1]

        for i in range(len(b) - len(a) - 1, -1, -1):
            value = carry + int(b[i])
            res.append(values[value][0])
            carry = values[value][1]
        
        if carry is 1: res.append('1')

        res.reverse()
        return ''.join(res)