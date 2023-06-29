// Author: Ahmed Gamal

// for this problem we can use bfs to find the shortest path to get all keys
// but here the state is not only the position of the player but also the keys that the player has that determine what doors the player can open
// since the number of keys is small we can use bitmask to represent the keys that the player has (2^6 = 64)
// so the state will be (x, y, msk) where msk is the keys that the player has (represented by the bits of the mask)

// we initially add the start position to the queue with msk = 0 (the player has no keys)
// then we will try to move in the four directions and we will check if the new position is valid and if the player can open the door (if there is a door)
// if the next cell is a key we will add it to the mask
// then we will check if we have all the keys (msk == full_msk) then we will return the distance (the answer)

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        // n: number of rows
        // m: number of columns
        // inf: infinity (some big number)
        const int n = int(grid.size()), m = int(grid[0].size());
        const int inf = 1e5;

        // at: function to convert char to int (a -> 0, b -> 1, ...)
        auto at = [&](char c) -> int {
            return c - 'a';
        };

        // valid: function to check if the position is valid
        auto valid = [&](int i, int j) -> bool {
            return i >= 0 and i < n and j >= 0 and j < m and grid[i][j] != '#';
        };

        // st: start position
        // full_msk: mask to check if we have all the keys and to initialize the distance array
        pair<int, int> st;
        int full_msk = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '@') {
                    st = {i, j};
                } else if(islower(grid[i][j])) {
                    // add the key to the mask
                    full_msk |= 1 << at(grid[i][j]);
                }
            }
        }

        // state: (x, y, msk)
        struct state {
            int x, y, msk;
            state(int x = 0, int y = 0, int msk = 0) : x(x), y(y), msk(msk) {
            }
        };

        // dist: distance array
        // dx, dy: directions (right, left, up, down)
        vector dist(n, vector(m, vector(full_msk + 1, inf)));
        vector<int> dx {0, 0, -1, 1}, dy {1, -1, 0, 0};

        // bfs
        queue<state> q;
        q.emplace(st.first, st.second);
        dist[st.first][st.second][0] = 0;

        while(not q.empty()) {
            auto [x, y, msk] = q.front();
            q.pop();

            // if we have all the keys then return the distance
            if(msk == full_msk) {
                return dist[x][y][msk];
            }

            // try to move in the four directions
            for(int d = 0; d < 4; d++) {
                int new_x = x + dx[d], new_y = y + dy[d];

                if(valid(new_x, new_y)) {
                    // initialy the new mask is the same as the old mask unless we have a key in the new position
                    int new_msk = msk;
                    char c = grid[new_x][new_y];

                    // if we have a key then add it to the mask
                    if(islower(c)) {
                        new_msk |= 1 << at(c);
                    }

                    // if we have a door and we don't have the key then we can't move
                    if(isupper(c)) {
                        int bit = 1 << at(tolower(c));
                        if(not(msk & bit)) {
                            continue;
                        }
                    }
                    
                    // if the new distance is less than the old distance then update the distance and add the new state to the queue
                    if(dist[new_x][new_y][new_msk] > dist[x][y][msk] + 1) {
                        dist[new_x][new_y][new_msk] = dist[x][y][msk] + 1;
                        q.emplace(new_x, new_y, new_msk);
                    }
                }
            }
        }

        // if we can't get all the keys then return -1
        return -1;
    }
};