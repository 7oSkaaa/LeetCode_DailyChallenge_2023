# Author: Lobna Mazhar

class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        queue, visited = [], set()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1: queue.append((i,j,0))
        res = -1
        while queue:
            r,c,d = queue.pop(0)
            if (r,c) not in visited:
                if grid[r][c] == 0: res = d
                visited.add((r, c))
                if r - 1 >= 0: queue.append((r - 1, c, d + 1))
                if r + 1 < len(grid): queue.append((r + 1, c, d + 1))
                if c - 1 >= 0: queue.append((r, c - 1, d + 1))
                if c + 1 < len(grid): queue.append((r, c + 1, d + 1))
        return res
