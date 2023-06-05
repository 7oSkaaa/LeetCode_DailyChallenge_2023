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
1. **[Time Needed to Inform All Employees](#03--time-needed-to-inform-all-employees)**
1. **[Number of Provinces](#04--number-of-provinces)**
1. **[Check If It Is a Straight Line](#05--check-if-it-is-a-straight-line)**

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
    
<hr>
<br><br>

## 03)  [Time Needed to Inform All Employees](https://leetcode.com/problems/time-needed-to-inform-all-employees/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search`

### Code


```cpp
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create an adjacency list to represent the organizational structure
        vector < vector < int > > adj(n);
        
        // Build the adjacency list
        for (int v = 0, u = manager[v]; v < n; v++, u = manager[v])
            if (~u) 
                adj[u].push_back(v);
        
        // Initialize distance vector to store the time taken for each employee to be informed
        vector < int > dist(n, -1);
        
        // Create a queue for breadth-first search
        queue < int > bfs;
        
        // Start from the head employee
        dist[headID] = 0;
        bfs.push(headID);
        
        // Perform breadth-first search
        while (!bfs.empty()) {
            // Get the front employee from the queue
            auto u = bfs.front();
            bfs.pop();
            
            // Traverse the employees under the current employee
            for (auto& v : adj[u]) {
                // If the employee hasn't been informed yet, update the distance and add to the queue
                if (dist[v] == -1) {
                    bfs.push(v);
                    dist[v] = dist[u] + informTime[u];
                }
            }
        }
        
        // Return the maximum inform time from the distance vector
        return *max_element(dist.begin(), dist.end());
    }
};
```
    
<hr>
<br><br>

## 04)  [Number of Provinces](https://leetcode.com/problems/number-of-provinces/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
class Solution {
public:

    vector < int > parent, Gsize;

    // Initialize the parent and size vectors with the given maximum number of nodes
    void init(int MaxNodes){
        parent.resize(MaxNodes + 5);
        Gsize.resize(MaxNodes + 5);
        for(int i = 1; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Find the leader/representative of the set that the given node belongs to
    int find_leader(int node){
        // If the parent of the node is the node itself, it is the leader
        // Otherwise, recursively find the leader of the parent node
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Union two sets represented by the given nodes
    void union_sets(int u, int v){
        int leader_u = find_leader(u), leader_v = find_leader(v);
        
        // If the leaders are the same, the nodes are already in the same set, so no action is needed
        if(leader_u == leader_v) return;
        
        // Merge the smaller set into the larger set
        if(Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v];
        parent[leader_v] = leader_u;
    }
    
    // Find the number of connected components in the given graph
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Initialize the parent and size vectors
        init(n);
        
        // Traverse the graph and union the connected nodes
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j] == 1)
                    union_sets(i, j);
        
        int connected = 0;
        
        // Count the number of unique leaders to determine the number of connected components
        for(int i = 0; i < n; i++)
            if(find_leader(i) == i) connected++;
        
        // Return the number of connected components
        return connected;
    }
};
```
    
<hr>
<br><br>

## 05)  [Check If It Is a Straight Line](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Math` `Geometry`

### Code


```cpp
class Solution {
public:

    // Define a struct for the coordinates of a point
    struct Point {
        int x, y;

        // Constructor to initialize a point from a vector of integers
        Point(const vector < int >& p) : x(p[0]), y(p[1]) { }
    };

    // Function to check if three points are on the same line
    bool is_same_line(const Point& p1, const Point& p2, const Point& p3){
        // Use slope formula to determine if the points are on the same line
        return (p2.y - p1.y) * (p3.x - p1.x) == (p3.y - p1.y) * (p2.x - p1.x);
    }
    
    bool checkStraightLine(const vector < vector < int > >& coordinates) {
        for(int i = 1; i < coordinates.size() - 1; i++) {
            // Check if the current point, its previous point, and the next point are on the same line
            if(!is_same_line(Point(coordinates[i]), Point(coordinates[i - 1]), Point(coordinates[i + 1])))
                return false;
        }

        // If all points are on the same line, return true
        return true;
    }
};
```
    