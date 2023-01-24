//Author: Mohamed Ibrahim

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pair<int, int>> idxs(n * n + 1); // Create a vector of pairs of integers called "idxs" with n*n+1 elements, to keep track of the indices of each cell in the board
        int idx = 1; // Initialize variable "idx" to 1
        vector<int> cols(n); // Create a vector of integers called "cols" with size "n", to store the columns of the board
        iota(cols.begin(), cols.end(), 0); // Fill "cols" vector with the values from 0 to n-1
        for (int row = n - 1; row >= 0; --row) { // Iterate over the rows of the board in reverse order (from n-1 to 0)
            for (auto col : cols)
                idxs[idx++] = {row, col}; // For each column, assign the current row and column indices to the corresponding position in the "idxs" vector
            reverse(cols.begin(), cols.end()); // Reverse the order of the elements in the "cols" vector
        }
        return BFS(n, idxs, board); // Call the BFS function
    }

    int BFS(int n, vector<pair<int, int>> &idxs, vector<vector<int>> &board) {
        vector<int> dis(n * n + 1, -1); /*Create a vector of integers called "dis" with n*n+1 elements, initialized to -1,
         this vector is used to keep track of the minimum number of moves required to reach each cell on the board*/

        queue<int> qu; // Create a queue of integers called "qu" which is used to perform the breadth-first search (BFS) algorithm
        dis[1] = 0; // Set the first element of the "dis" vector to 0, as the starting cell is already occupied
        qu.push(1); // Push the first cell of the board (index 1) into the queue

        while (!qu.empty()) { // While the queue is not empty
            int cur = qu.front(); // Assign the front element of the queue to the variable "cur"
            qu.pop(); // Pop the front element from the queue
            
            int m = min(cur + 6, n * n); // Calculate the minimum of cur+6 and n*n. The variable "m" is used to limit the number of possible moves to 6, as the player can roll a die with 6 faces
            for (int cell = cur + 1; cell <= m; ++cell) { // Iterate from the current cell + 1 to the variable "m"
                auto [row, col] = idxs[cell]; // Use destructuring assignment to assign the row and column values of the current cell from the "idxs" vector to the variables "row" and "col" respectively
                int nxt = board[row][col] != -1 ? board[row][col] : cell; // Check if the value of the current cell in the board is not -1. If it is not
                if (dis[nxt] == -1) { // If the minimum number of moves required to reach the "nxt" cell is not set yet
                dis[nxt] = dis[cur] + 1; // Set the minimum number of moves required to reach the "nxt" cell to the minimum number of moves required to reach the "cur" cell + 1
                qu.push(nxt); // Push the "nxt" cell into the queue
                 }
            }
        }
        return dis[n * n];
    }
};