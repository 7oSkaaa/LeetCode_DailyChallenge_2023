// Author: Ahmed Hossam

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        // dimension of the board
        int n = board.size();

        // coord[i] will be the coordinate of the cell that value is i
        vector < pair < int, int > > coord(n * n + 1);

        // dist for each value
        vector < int > dist(n * n + 1, 1e9);

        // assign coordinate the direction is alternating by row
        bool is_right = true;
        for(int r = n, idx = 1; r >= 1; r--){
            if(is_right)
                for(int c = 1; c <= n; c++)
                    coord[idx++] = {r, c};
            else
                for(int c = n; c >= 1; c--)
                    coord[idx++] = {r, c};
            is_right = !is_right;
        }

        // make bfs from 1 to n * n
        queue < int > bfs;
        bfs.push(1);
        dist[1] = 0;

        while(!bfs.empty()){
            // current value
            auto u = bfs.front();
            auto [r, c] = coord[u];        
            bfs.pop();

            for(int v = u + 1; v <= min(u + 6, n * n); v++){
                // get coordinate of the next value
                auto [new_r, new_c] = coord[v];

                // if the next value contains snake or ladder so we will go forward to it
                int next = (board[new_r - 1][new_c - 1] == -1 ? v : board[new_r - 1][new_c - 1]);
                
                // bfs 0-1
                if(dist[next] > dist[u] + 1)
                    dist[next] = dist[u] + 1, bfs.push(next);
            }
        }

        // if it's impossible to reach n * n
        if(dist[n * n] == int(1e9))
            dist[n * n] = -1;

        // distance to move to n * n
        return dist[n * n];
    }
};
