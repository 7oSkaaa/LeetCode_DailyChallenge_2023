# LeetCode Daily Challenge Problems for June

<br><br>

## Workflow Checking

<div align="center">
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Author_Line.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/File_Names.yml" taget="_blank"/>
</img>
&nbsp;
<img src="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml/badge.svg" alt="Checkers" width="150">
<a href="https://github.com/7oSkaaa/LeetCode_DailyChallenge_2023/actions/workflows/Daily_Problem.yml" taget="_blank"/>
</img>
</div>

<br><br>

## Problems:


<hr>
<br><br>

## 01)  [Shortest Path in Binary Matrix](https://leetcode.com/problems/shortest-path-in-binary-matrix/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Breadth-First Search` `Matrix`

### Code


```cpp
class Solution {
public:
    
    // Define a template alias for Pair using pair<T, T>
    template < typename T = int > using Pair = pair < T, T >;

    // Function to find the shortest path in a binary matrix
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid
        int INF = 2e9; // Set a large value for infinity

        // Define the possible directions to move
        vector < Pair < int > > dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        // Lambda function to check if a position is valid
        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n && !grid[x][y];
        };

        // Initialize the distances with infinity
        vector < vector < int > > dist(n, vector < int > (n, INF));

        // Set the distance of the starting position
        dist[0][0] = (grid[0][0] == 0 ? 1 : INF);

        // Create a queue for BFS traversal
        queue < Pair < int > > bfs;

        // Add the starting position to the queue
        bfs.emplace(0, 0);

        // Perform BFS traversal
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            bfs.pop();

            // Check all possible directions to move
            for (auto& [dx, dy] : dir) {
                int nx = x + dx, ny = y + dy;

                // Check if the new position is valid and the distance can be updated
                if (is_valid(nx, ny) && dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    bfs.emplace(nx, ny);
                }
            }
        }

        // Return the shortest path distance or -1 if no path exists
        return (dist[n - 1][n - 1] == INF ? -1 : dist[n - 1][n - 1]);
    }
};
```
    