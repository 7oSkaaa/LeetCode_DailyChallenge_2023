# Author: Lobna Mazhar

class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        # Util variables for the length of the board and total cells
        n, n2 = len(board), len(board) ** 2
        # Initialize the res by a max value of the total cells as this count of moves can't be achieved
        res = n2

        cells, moves, visited = [], {}, set()
        
        # Append cell 1 (starting position) to the queue with 0 move
        cells.append(1)
        moves[1] = 0

        # Add target cells to queue and keep popping from it until visiting all the cells
        while cells:
            current = cells.pop(0)
            visited.add(current)
            move = moves[current]
            
            # For each of the possible moves from the current cell
            for i in range(current + 1, min(current + 6, n2) + 1):
                # Get the row and col for the current cell
                r, c = self.getRowCol(i, n, n2)
                # Get the target cell if the current has a ladder or snake then use the board[r][c] as the target cell
                target = i if board[r][c] == -1 else board[r][c]
                # If the target cell is the end, update the res
                if target == n2: res = min(res, 1 + move)
                else:
                    # If the target cell wasn't visited before, and not added before to the queue or added with more moves ,, update its moves count
                    if target not in visited and (target not in cells or moves[target] > 1 + move):
                        if target not in cells: cells.append(target)
                        moves[target] = 1 + move
                    
        # If new res was found instead of the max, return it else return -1 as the end can't be reached
        return res if res != n2 else -1

    # Get the row and col for the given cell
    # To get the row, divide the current position by the length but before that deceremnt it from the total as the rows are upside down
    # To get the column, get the remainder from dividing by the length after deceremnting from the total as well, if the current row was in a position of rotation (right to left) (odd from the bottom), deceremnt the calculated column from the length (flipped) 
    def getRowCol(self, current, length, total):
        row, col = (total - current) // length, (total - current) % length
        if (length - row) % 2 != 0: col = length - 1 - col
        return (row, col)



        


