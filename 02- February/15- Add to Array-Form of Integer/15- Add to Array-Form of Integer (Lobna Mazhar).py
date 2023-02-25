# Author: Lobna Mazhar

class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        index = len(num) - 1
        num[index] = num[index] + k
        k, num[index] = num[index] // 10, num[index] % 10
        while k:
            index -= 1
            if index < 0: 
                num.insert(0, 0)
                index = 0
            num[index] = num[index] + k
            k, num[index] = num[index] // 10, num[index] % 10
        
        return num
