// Author: Ahmed Hossam

class Solution {
public:
    // Define the possible directions: right, left, up, down
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Create a queue to store the positions and keys
        queue<pair<pair<int, int>, int>> que;

        // Create a map to track the collected keys for each position
        vector<vector<unsigned long>> mapKey(m, vector<unsigned long>(n, 0));

        int target = 0; // Variable to store the bitmask of all keys

        // Iterate through the grid to find the starting position and collect the target keys
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    target |= 1 << (grid[i][j] - 'a');
                    continue;
                }
                if (grid[i][j] == '@') {
                    // Initialize the queue with the starting position
                    que.emplace(make_pair(i, j), 0);
                    mapKey[i][j] = 1; // Mark the starting position as visited
                }
            }
        }

        int steps = 0; // Variable to count the number of steps

        // BFS traversal
        while (!que.empty()) {
            int size = que.size();
            for (int s = 0; s < size; s++) {
                auto [point, key] = que.front();
                auto [i, j] = point;
                que.pop();

                if ('a' <= grid[i][j] && grid[i][j] <= 'f') {
                    // Collect the key and update the bitmask
                    key |= 1 << (grid[i][j] - 'a');
                    if (key == target)
                        return steps; // Return the number of steps if all keys are collected
                    mapKey[i][j] |= 1l << key; // Mark the position with the collected key
                }

                for (auto [di, dj] : dir) {
                    int newi = i + di;
                    int newj = j + dj;

                    // Check if the new position is within the grid
                    if (!(0 <= newi && newi < m && 0 <= newj && newj < n))
                        continue;

                    int val = grid[newi][newj];
                    
                    // Skip if the new position is a wall
                    if (val == '#')
                        continue;

                    // Skip if the new position is a locked door and the required key is not collected
                    if ('A' <= val && val <= 'F' && (key & (1 << (val - 'A'))) == 0)
                        continue;

                    // Skip if the new position with the current key has been visited before
                    if (mapKey[newi][newj] & (1l << key))
                        continue;

                    // Mark the new position with the current key and add it to the queue
                    mapKey[newi][newj] |= 1l << key;
                    que.emplace(pair<int, int>(newi, newj), key);
                }
            }
            steps++; // Increment the number of steps
        }
        return -1; // Return -1 if it's not possible to collect all keys
    }
};
