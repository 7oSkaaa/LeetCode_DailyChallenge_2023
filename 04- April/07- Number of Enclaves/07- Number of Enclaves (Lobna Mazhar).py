# Author: Lobna Mazhar

class Solution:
    def numEnclaves(self, grid: List[List[int]]) -> int:
        self.moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        # For each cell, check if it was a boundary land, explore the cells attached to it to mark them as visitable 
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if r == 0 or r == len(grid) - 1 or c == 0 or c == len(grid[0]) - 1:
                    if grid[r][c] == 1: self.exploreCell(grid, r, c)
       
        count = 0
        # For each cell, check if it was a land, those cells can't be reached, increment the count
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if grid[r][c] == 1: count += 1
        return count


    def exploreCell(self, grid: List[List[int]], row: int, col: int):
        # If out of boundary, return
        if row < 0 or row == len(grid) or col < 0 or col == len(grid[0]): return
        
        # If the current cell is water, or visited before, return
        if grid[row][col] == 0 or grid[row][col] == -1: return
        
        # Mark the cell as visited
        grid[row][col] = -1

        # For each move in the 4 directions, explore the cells that can be reached from the current cell
        for r, c in self.moves: self.exploreCell(grid, row + r, col + c)
