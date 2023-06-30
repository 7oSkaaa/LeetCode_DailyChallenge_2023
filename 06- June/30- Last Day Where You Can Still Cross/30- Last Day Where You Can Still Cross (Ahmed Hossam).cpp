// Author: Ahmed Hossam

class Solution {
public:
    // Constant representing infinity
    static constexpr int INF = 1e9;
    // Variables to store the number of rows, columns, and cells
    int rows, cols, cellsCnt;
    // 2D vector to store the cells
    vector < vector < int > > cells;

    // Function to calculate the distances
    vector<int> get_dist(int day) {
        // Create a grid and initialize it with zeros
        vector < vector < int > > grid(rows, vector < int > (cols, 0));
        // Create a 2D vector to store the distances and initialize them with infinity
        vector < vector < int > > dist(rows, vector < int > (cols, INF));

        // Place the cells on the grid for the first 'day' number of days
        for (int i = 0; i < min(day, cellsCnt); i++) {
            int x = cells[i][0], y = cells[i][1];
            grid[--x][--y] = 1;
        }

        // Lambda function to check if a position is valid
        auto is_valid = [&](int r, int c) {
            return r >= 0 && r < rows && c >= 0 && c < cols && !grid[r][c];
        };

        // Vector representing the possible directions to move
        vector < pair < int, int > > dir = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        // Queue for breadth-first search
        queue < pair < int, int > > bfs;

        // Start the BFS from the cells in the first row
        for (int col = 0; col < cols; col++) {
            if (grid[0][col]) continue;
            bfs.emplace(0, col);
            dist[0][col] = 0;
        }

        // Perform breadth-first search
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();
            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;
                // if the new cell isn't out of bound and the current distance greater than new one add it
                if (is_valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    bfs.emplace(nx, ny);
                }
            }
        }

        // Return the distances of the last row
        return dist[rows - 1];
    }

    // Function to initialize the class variables
    void init(int row, int col, const vector < vector < int > >& cells) {
        this -> rows = row;
        this -> cols = col;
        this -> cellsCnt = cells.size();
        this -> cells = cells;
    }

    int latestDayToCross(int row, int col, const vector < vector < int > >& cells) {
        // Initialize the class variables
        init(row, col, cells);
        
        // Lambda function to check if a day is good
        auto is_good = [&](int m) {
            vector < int > dist = get_dist(m);
            return *min_element(dist.begin(), dist.end()) < INF;
        };
        
        // Binary search to find the latest day
        int l = 0, r = cellsCnt, ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            is_good(m) ? l = m + 1, ans = m : r = m - 1;
        }

        // Return the latest day
        return ans;
    }
};
