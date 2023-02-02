// Author: Mahmoud Aboelsoud

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // n is the size of each side of the board
        int n = board.size();
        // ma is a map that maps each number to its position in the board
        unordered_map<int, pair<int,int>> ma;
        // str_left is a boolean that indicates if the current row is left to right or right to left
        bool str_left = 1;

        // fill the map
        // the first row is the last row in the board
        // the first column is the first column in the board
        // the first row is left to right
        // the second row is right to left
        // the third row is left to right
        // and so on

        int x = 1;
        for(int i = n - 1; i >= 0; i--){
            if(str_left){
                for(int j = 0; j < n; j++)
                    ma[x++] = {i, j};
            }else{
                for(int j = n - 1; j >= 0; j--)
                    ma[x++] = {i, j};
            }

            str_left = !str_left;
        }

        // bfs to find the shortest path (the minimum number of moves) form 1 to n * n
        // cnt is the number of moves
        // bfs is the queue that contains the current number
        // vis is the set that contains the visited numbers
        // if the current number is the last number, return cnt
        // else, add the next 6 numbers to the queue
        // if the next number is a ladder, add the number that the ladder leads to
        // if the next number is a snake, add the number that the snake leads to
        // if the next number is a normal number, add it
        // if the next number is out of the board, break
        // if the queue is empty that means that there is no path to the last number so we return -1

        int cnt = -1;
        queue<int> bfs;
        bfs.push(1);
        set<int> vis;
        while(bfs.size()){
            // k is the number of numbers in the current level
            int k = bfs.size();
            // increase the number of moves
            cnt++;
            // for each number in the current level
            // if the number is visited, continue
            // else, add it to the visited set
            // if the number is the last number, return cnt
            // else, add the next 6 numbers to the queue if they are not out of the board
            while(k--){
                int x = bfs.front();
                bfs.pop();

                if(vis.count(x)) continue;
                vis.insert(x);

                if(x == n * n) return cnt;

                for(int i = 1; i <= 6; i++){
                    if(x + i > n * n) break;
                    // u is the row of the next number
                    // v is the column of the next number
                    int u = ma[x + i].first, v = ma[x + i].second;

                    // if the next number is a ladder or a snake, add the number that the ladder or the snake leads to to the queue
                    // else, add the next number to the queue
                    if(board[u][v] == -1) bfs.push(x + i);
                    else bfs.push(board[u][v]);
                }
            }
        }

        // if the queue is empty that means that there is no path to the last number so we return -1
        return -1;
    }
};
