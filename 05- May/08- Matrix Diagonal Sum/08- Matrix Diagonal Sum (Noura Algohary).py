# Author: Noura Algohary
class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        sm = 0
        for i in range(n):
            sm += mat[i][i]
            if i!=(n-1)/2:
                sm += mat[i][n-i-1]
            
        return sm
                        