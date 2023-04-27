# Author: Noura Algohary

class Solution:
    def addDigits(self, num: int) -> int:

        def recursiveAddition(num):
            # the ending contidion is reaching a one digit number
            if len(num) == 1:
                return int(num)

            # to store the summation of digits of num
            sumInt = 0

            for i in range(len(num) - 1, -1, -1):
                sumInt += int(num[i])

            return recursiveAddition(str(sumInt))

        return recursiveAddition(str(num))