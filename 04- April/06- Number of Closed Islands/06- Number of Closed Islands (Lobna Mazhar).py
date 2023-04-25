# Author: Lobna Mazhar

class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        self.ranges = [(-1,0),(1,0),(0,-1),(0,1)]
        count = 0
        # Loop on the grid and check for each cell, if it was a land (0) and surrounded by water (checkIfSurroundedByWater method), increment the count by 1
        for r in range(len(grid)):
            for c in range(len(grid[r])):
                if grid[r][c] == 0 and self.checkIfSurroundedByWater(grid, r, c):
                    count += 1
        return count

    def checkIfSurroundedByWater(self, grid, row, col):
        # If the cell was a boundary cell, return true if it was water
        if row == 0 or col == 0 or row == len(grid) - 1 or col == len(grid[0]) - 1:
            return grid[row][col] != 0

        # If the cell was a water (1) or has been visited before as a valid land (-1), return True
        if grid[row][col] == 1 or grid[row][col] == -1: return True

        # Mark the cell as visited by changing it to any number other than 0 and 1
        grid[row][col] = -1

        # Check the 4 (top, left, right, bottom) cells arround the current cell
        res = True
        for r,c in self.ranges:
            # Check if it wasn't surrounded by water (land boundary or any neighbour cell has a land boundary), add that to the boolean result
            res = self.checkIfSurroundedByWater(grid, row + r, col + c) and res
        # Return the result of that connected land as whole
        return res
        
