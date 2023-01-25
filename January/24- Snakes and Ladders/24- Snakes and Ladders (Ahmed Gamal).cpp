// Author: Ahmed Gamal

class Solution {
public:

    // we need to find the shortest path from {n - 1, 0} (the bottom left corner) to the position of the last cell (it may change depending on the board size)
    // we can use BFS to find the shortest path if we represent the board as a graph and the cells as nodes and the edges as the possible moves from a cell to another
    // we can represent the board as a graph by mapping each cell to its position in the board and vice versa
    // from each cell we can move to the next 6 cells (if they exist) and if there is a ladder or a snake we can move to the cell that it leads to
    // we can use a queue to do BFS and a vector to store the distances from the starting cell to each cell
    // we can use a map to map each cell to its position in the board and vice versa (I'm sure there is a better way to do this but I didn't think of it)


    #define inf 2000'000'000

    int snakesAndLadders(vector<vector<int>>& board) {
        const int n = (int)board.size();

        // turn: true -> we are moving right, false -> we are moving left 
        bool turn = true;
        // id: the id of the current cell
        int id = 1;
        // pos: maps each cell to its position in the board
        map<int, pair<int, int>> pos;
        // idx: maps each position in the board to its cell
        map<pair<int, int>, int> idx;
        // we start from the bottom left corner
        int i = n - 1, j = 0;

        // until we reach the last cell
        while(id <= n * n){
            // map the current cell to its position in the board and vice versa
            pos[id] = {i, j};
            idx[{i, j}] = id++;
            
            // move to the next cell
            int nxt_i, nxt_j;
            if(turn){
                // if we are moving right and we reached the rightmost cell we need to move up and start moving left
                if(j == n - 1){
                    turn = not turn;
                    nxt_i = i - 1;
                    nxt_j = n - 1;
                }else{
                // if we are moving right and we didn't reach the rightmost cell we need to move right
                    nxt_i = i;
                    nxt_j = j + 1;
                }
            }else{
                // if we are moving left and we reached the leftmost cell we need to move up and start moving right
                if(not j){
                    turn = not turn;
                    nxt_i = i - 1;
                    nxt_j = 0;
                }else{
                // if we are moving left and we didn't reach the leftmost cell we need to move left
                    nxt_i = i;
                    nxt_j = j - 1;
                }
            }
            // update the current cell
            i = nxt_i, j = nxt_j;
        }

        // BFS
        // q: the queue that we will use to do BFS
        queue<pair<int, int>> q;
        // dist: the vector that we will use to store the distances from the starting cell to each cell
        vector<vector<int>> dist(n, vector<int>(n, inf));

        // push the starting cell to the queue and update its distance
        q.push({n - 1, 0});
        dist[n - 1][0] = 0;

        // until the queue is empty
        while(not q.empty()){
            // size: the number of cells in the current level
            int size = int(q.size());

            // for each cell in the current level
            while(size--){
                // get the current cell
                auto [curr_i, curr_j] = q.front();

                // get the id of the current cell
                int curr = idx[{curr_i, curr_j}];
                
                // pop the current cell from the queue
                q.pop();

                // for each possible move from the current cell
                for(int nxt = curr + 1; nxt <= min(curr + 6, n * n); nxt++){
                    // get the position of the next cell
                    auto [nxt_i, nxt_j] = pos[nxt];
                    
                    // if there is a ladder or a snake we need to move to the cell that it leads to
                    if(board[nxt_i][nxt_j] != -1){
                        auto [tmp_i, tmp_j] = pos[board[nxt_i][nxt_j]];
                        nxt_i = tmp_i, nxt_j = tmp_j;
                    }

                    // if we haven't visited the next cell before or we can reach it in a shorter path we need to update its distance and push it to the queue
                    if(dist[nxt_i][nxt_j] > dist[curr_i][curr_j] + 1){
                        dist[nxt_i][nxt_j] = dist[curr_i][curr_j] + 1;
                        q.push({nxt_i, nxt_j});
                    }
                }
            }
        }

        // get the position of the last cell
        auto final_pos = pos[n * n];

        // get the answer
        int ans = dist[final_pos.first][final_pos.second];
        
        // return the answer (if there is no path return -1 instead)
        return ans == inf ? -1 : ans;
    }
};