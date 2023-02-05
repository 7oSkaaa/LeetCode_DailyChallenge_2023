# Author: Walaa AbdElhady

"""
P     I    N
A   L S  I G
Y A   H R
P     I
if we look in our zigzag we found that :
1- in the first and last row we jump from first idx to idx+6 and so on(in case of numRow=4).
and we can generate that => jump = 2*(numRows-1) => jump=2*(4-1)=6 and this is our increment in each time
2- in the middle rows we also jump => 2*(numRows-1)
but there are another chars we didn't sum it like [L,I] in second row,
so we found that we can add them to ans by subtracting 2*numberOfCurrentRow from our jump
"""


def convert(self, s, numRows):
    if numRows == 1: return s  # // if n == 1 there is no change will be
    ans = ""  # to store our answer
    for r in range(numRows):
        jump = 2 * (numRows - 1)
        for j in range(r, len(s), jump):
            ans += s[j]
            if r != 0 and r != numRows - 1 and j + jump - 2 * r < len(s):  # if in the middle rows
                ans += s[j + jump - 2 * r]

    return ans
