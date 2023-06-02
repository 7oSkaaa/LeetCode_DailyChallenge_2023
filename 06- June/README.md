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
1. **[Shortest Path in Binary Matrix](#01--shortest-path-in-binary-matrix)**

1. **[Detonate the Maximum Bombs](#02--detonate-the-maximum-bombs)**

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
    

<hr>
<br><br>

## 02)  [Detonate the Maximum Bombs](https://leetcode.com/problems/detonate-the-maximum-bombs/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Math` `Depth-First Search` `Breadth-First Search` `Graph` `Geometry`

### Code


```cpp
class Solution {
public:

    vector<vector<int>> adj; // Adjacency list representing the graph.
    vector<bool> vis; // Boolean array to keep track of visited nodes.

    // Function to check if a circle is intersect another circle.
    bool isIntersect(const vector<int>& a, const vector<int>& b){
        int X = (a[0] - b[0]), Y = (a[1] - b[1]), R = a[2];
        return (1ll * R * R) >= (1ll * X * X) + (1ll * Y * Y); 
    }

    // Depth-first search function to calculate the length of a path.
    int dfs(int u){
        vis[u] = true; // Mark the current node as visited.
        int pathLength = 1; // Initialize the path length to 1 for the current node.
        for(auto& v : adj[u]){ // Iterate through the adjacent nodes of the current node.
            if(!vis[v]) // If the adjacent node is not visited, recursively call dfs on it.
                pathLength += dfs(v); // Add the path length of the adjacent node to the current path length.
        }
        return pathLength; // Return the total path length.
    }

    // Function to build the adjacency list based on the given bombs coordinates.
    void build_adj(const vector<vector<int>>& bombs){
        int n = bombs.size();
        adj = vector<vector<int>>(n + 5); // Initialize the adjacency list.
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isIntersect(bombs[i], bombs[j])){ // Check if bomb j is intersect bomb i.
                    adj[i].push_back(j); // Add j to the adjacency list of i.
                }
            }
        }
    }

    // Function to calculate the maximum detonation path length.
    int maximumDetonation(const vector<vector<int>>& bombs) {
        int n = bombs.size(); // Get the number of bombs.
        
        build_adj(bombs); // Build the adjacency list.
        
        int maxPathLength = 0; // Initialize the maximum path length to 0.
        for(int i = 0; i < n; i++){ // Iterate through each bomb.
            vis = vector<bool>(n + 5); // Reset the visited array.
            maxPathLength = max(maxPathLength, dfs(i)); // Calculate the maximum path length starting from bomb i.
        }
        
        return maxPathLength; // Return the maximum path length.
    }
};
```
    