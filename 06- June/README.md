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
1. **[Can Make Arithmetic Progression From Sequence](#06--can-make-arithmetic-progression-from-sequence)**
1. **[Minimum Flips to Make a OR b Equal to c](#07--minimum-flips-to-make-a-or-b-equal-to-c)**
1. **[Count Negative Numbers in a Sorted Matrix](#08--count-negative-numbers-in-a-sorted-matrix)**
1. **[Find Smallest Letter Greater Than Target](#09--find-smallest-letter-greater-than-target)**
1. **[Maximum Value at a Given Index in a Bounded Array](#10--maximum-value-at-a-given-index-in-a-bounded-array)**
1. **[Snapshot Array](#11--snapshot-array)**
1. **[Summary Ranges](#12--summary-ranges)**
1. **[Equal Row and Column Pairs](#13--equal-row-and-column-pairs)**
1. **[Minimum Absolute Difference in BST](#14--minimum-absolute-difference-in-bst)**
1. **[Maximum Level Sum of a Binary Tree](#15--maximum-level-sum-of-a-binary-tree)**
1. **[Number of Ways to Reorder Array to Get Same BST](#16--number-of-ways-to-reorder-array-to-get-same-bst)**
1. **[Make Array Strictly Increasing](#17--make-array-strictly-increasing)**
1. **[Number of Increasing Paths in a Grid](#18--number-of-increasing-paths-in-a-grid)**
1. **[Find the Highest Altitude](#19--find-the-highest-altitude)**
1. **[K Radius Subarray Averages](#20--k-radius-subarray-averages)**
1. **[Minimum Cost to Make Array Equal](#21--minimum-cost-to-make-array-equal)**
1. **[Best Time to Buy and Sell Stock with Transaction Fee](#22--best-time-to-buy-and-sell-stock-with-transaction-fee)**
1. **[Longest Arithmetic Subsequence](#23--longest-arithmetic-subsequence)**
1. **[Tallest Billboard](#24--tallest-billboard)**
1. **[Count All Possible Routes](#25--count-all-possible-routes)**
1. **[Total Cost to Hire K Workers](#26--total-cost-to-hire-k-workers)**
1. **[Find K Pairs with Smallest Sums](#27--find-k-pairs-with-smallest-sums)**
1. **[Path with Maximum Probability](#28--path-with-maximum-probability)**
1. **[Shortest Path to Get All Keys](#29--shortest-path-to-get-all-keys)**
1. **[Last Day Where You Can Still Cross](#30--last-day-where-you-can-still-cross)**

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
    
<hr>
<br><br>

## 06)  [Can Make Arithmetic Progression From Sequence](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Sorting`

### Code


```cpp
class Solution {
public:

    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        // Sorting the vector in ascending order
        sort(arr.begin(), arr.end());
        
        // Checking the difference between consecutive elements
        // If the difference is not the same for all elements, return false
        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
                return false;
        }
        
        // If the difference is the same for all elements, return true
        return true;
    }

};
```
    
<hr>
<br><br>

## 07)  [Minimum Flips to Make a OR b Equal to c](https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Bit Manipulation`

### Code


```cpp
class Solution {
public:
    int minFlips(int a, int b, int c) {
        // Lambda function to get the value of a particular bit
        auto get_bit = [&](int bit, int x){
            return (x >> bit) & 1;
        };
        
        int flips = 0;
        
        // Iterate through each bit from right to left (0 to 31)
        for(int bit = 0; bit < 32; bit++){
            // Check if the current bit in 'c' is set to 1
            if(get_bit(bit, c)) 
                // If 'c' has a 1 and 'a' and 'b' have 0, increment flips
                flips += !(get_bit(bit, a) | get_bit(bit, b));
            
            // Check if the current bit in 'c' is set to 0
            if(!get_bit(bit, c))
                // If 'c' has a 0 and either 'a' or 'b' has a 1, increment flips
                flips += (get_bit(bit, a) + get_bit(bit, b));
        }
        
        return flips;
    }
};
```
    
<hr>
<br><br>

## 08)  [Count Negative Numbers in a Sorted Matrix](https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Matrix`

### Code


```cpp
class Solution {
public:
    
    int countNegatives(vector<vector<int>>& grid) {
        // Get the number of rows in the grid
        int n = grid.size();
        
        // Initialize a counter variable to store the count of negative numbers
        int cnt = 0;
        
        // Iterate over each row in the grid
        for(int i = 0; i < n; i++) {
            // Find the position of the first element greater than -1 (negative number)
            auto it = upper_bound(grid[i].rbegin(), grid[i].rend(), -1);
            
            // Calculate the count of negative numbers in the current row
            int rowCnt = it - grid[i].rbegin();
            
            // Add the count of negative numbers in the current row to the total count
            cnt += rowCnt;
        }
        
        // Return the total count of negative numbers in the grid
        return cnt;
    }

};
```
    
<hr>
<br><br>

## 09)  [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Get the size of the vector
        int n = letters.size();
        
        // Find the upper bound of the target letter in the vector and calculate its index
        // If the index exceeds the size of the vector, wrap around to the beginning
        int idx = (upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % n;
        
        // Return the next greatest letter
        return letters[idx];
    }
};
```
    
<hr>
<br><br>

## 10)  [Maximum Value at a Given Index in a Bounded Array](https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Binary Search` `Greedy`

### Code


```cpp
class Solution {
public:
    
    int maxValue(int n, int index, int maxSum) {
        // function to calculate the sum of integers from 1 to x
        auto sum = [&](long long x){
            return x * (x + 1) / 2;
        };

        // function to check if the given value is good or not
        auto is_good = [&](long long m){
            long long arrSum = 0;

            // Calculate sum for the left segment
            arrSum = sum(m - 1);
            arrSum += (index > m - 1 ? index - m + 1 : -sum(m - 1 - index));

            // Calculate sum for the right segment
            arrSum += sum(m - 1);
            arrSum += (n - index > m ? n - index - m : -sum(m - n + index));

            // Check if the overall sum is less than or equal to maxSum
            return arrSum <= maxSum - m;
        };

        // Binary search to find the maximum value
        int l = 1, r = 1, ans = -1;

        // Get the boundary limit of r
        while(is_good(r))
            r *= 2;
        
        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? l = m + 1, ans = m : r = m - 1);
        }

        // Return the maximum value
        return ans;
    }
};
```
<hr>
<br><br>

## 11)  [Snapshot Array](https://leetcode.com/problems/snapshot-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Binary Search` `Design`

### Code


```cpp
class SnapshotArray {
public:

    // Declaration of variables
    int snap_id;
    map < int, vector < pair < int, int > > > snapshot;

    // Constructor
    SnapshotArray(int length) {
        snap_id = 0;
        for (int i = 0; i < length; i++)
            snapshot[length].emplace_back(snap_id, 0);
    }

    // Set the value at the given index
    void set(int index, int val) {
        snapshot[index].emplace_back(snap_id, val);
    }

    // Create a snapshot and return the snapshot ID
    int snap() {
        return snap_id++;
    }

    // Get the value at the given index for a specific snapshot ID
    int get(int index, int query_snap_id) {
        vector < pair < int, int > >& snap = snapshot[index];
        
        // get the last value the have a snap id less than or equal the given one
        int l = 0, r = snap.size() - 1, ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            (snap[m].first <= query_snap_id ? l = m + 1, ans = snap[m].second : r = m - 1);
        }
        return ans;
    }

};
```

<hr>
<br><br>

## 12)  [Summary Ranges](https://leetcode.com/problems/summary-ranges/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array`

### Code


```cpp
class Solution {
public:

    // Function to create a range string representation
    string make_range(int l, int r) {
        if (l == r)
            return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }

    // Function to summarize ranges in a vector of integers
    vector < string > summaryRanges(const vector < int >& nums) {
        // if the nums array is empty
        if(nums.empty()) return {};
        
        vector < string > Ranges; // Vector to store the summarized ranges
        int begin = nums[0]; // Initialize the beginning of the range

        // Iterate through the numbers
        for (int i = 1; i < nums.size(); i++) {
            // If the current number is not consecutive to the previous number
            if (nums[i] != nums[i - 1] + 1) {
                // Add the summarized range to the vector
                Ranges.emplace_back(make_range(begin, nums[i - 1]));
                begin = nums[i]; // Update the beginning of the next range
            }
        }

        // Add the last range to the vector
        Ranges.emplace_back(make_range(begin, nums.back()));

        return Ranges; // Return the summarized ranges
    }

};
```
    
<hr>
<br><br>

## 13)  [Equal Row and Column Pairs](https://leetcode.com/problems/equal-row-and-column-pairs/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Matrix` `Simulation`

### Code


```cpp
class Solution {
public:
    // This function calculates the number of equal pairs in a 2D grid
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size(); // Get the size of the grid (assuming it's a square grid)
        int equal_pairs = 0; // Initialize the count of equal pairs

        map < vector < int >, int > freq; // Create a map to store the frequency of each row vector

        // Count the frequency of each row vector in the grid
        for(int row = 0; row < n; row++)
            freq[grid[row]]++;

        // Iterate through each column in the grid
        for(int col = 0; col < n; col++) {
            vector<int> curr_col(n); // Create a temporary vector to store the current column

            // Extract the elements of the current column from each row
            for(int row = 0; row < n; row++)
                curr_col[row] =  grid[row][col];

            // Add the frequency of the current column vector to the count of equal pairs
            equal_pairs += freq[curr_col];
        }

        return equal_pairs; // Return the total count of equal pairs
    }
};
```
    
<hr>
<br><br>

## 14)  [Minimum Absolute Difference in BST](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Search Tree` `Binary Tree`

### Code


```cpp
class Solution {
public:

    // This code defines a vector to store integer values
    vector < int > values;

    // This function recursively traverses a binary tree and adds its node values to the 'values' vector sorted increasing
    void get_values(TreeNode* root){
        // Base case: if the root is null, return
        if(!root) return;
        
        // Recursive calls: traverse the left subtree, add the root value, then traverse the right subtree (Sorted)
        get_values(root -> left);
        values.emplace_back(root -> val);
        get_values(root -> right);
    }

    int getMinimumDifference(TreeNode* root) {
        // Populate the 'values' vector by calling the 'get_values' function
        get_values(root);
        
        // Initialize the minimum difference variable with the maximum possible value
        int minDiff = INT_MAX;
        
        // Iterate through the 'values' vector to find the minimum difference between adjacent values
        for(int i = 1; i < values.size(); i++)
            minDiff = min(minDiff, values[i] - values[i - 1]);
        
        // Return the minimum difference
        return minDiff;
    }
};
```
    
<hr>
<br><br>

## 15)  [Maximum Level Sum of a Binary Tree](https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        // Variables to store the level with the maximum sum, the minimum level sum, and the current level
        int minLevel = -1, minLevelSum = INT_MIN, currLevel = 1;

        // Queue for breadth-first search traversal
        queue < TreeNode* > bfs;

        // Add the root node to the queue
        bfs.emplace(root);

        // Perform breadth-first search
        while (!bfs.empty()) {
            // Get the number of nodes in the current level and initialize the sum of values in the current level
            int levelSz = bfs.size(), currSum = 0;

            // Process each node in the current level
            while (levelSz--) {
                // Get the front node from the queue and remove it
                TreeNode* currRoot = bfs.front();
                bfs.pop();

                // Add the value of the current node to the sum
                currSum += currRoot->val;

                // Enqueue the left and right children of the current node if they exist
                if (currRoot->left)
                    bfs.emplace(currRoot->left);
                if (currRoot->right)
                    bfs.emplace(currRoot->right);
            }

            // Check if the sum of the current level is greater than the minimum level sum
            // If so, update the minimum level sum and the level with the maximum sum
            if (minLevelSum < currSum)
                minLevelSum = currSum, minLevel = currLevel;

            // Move to the next level
            currLevel++;
        }

        // Return the level with the maximum sum
        return minLevel;
    }
};
```
    
<hr>
<br><br>

## 16)  [Number of Ways to Reorder Array to Get Same BST](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Math` `Divide and Conquer` `Dynamic Programming` `Tree` `Union Find` `Binary Search Tree` `Memoization` `Combinatorics` `Binary Tree`

### Code


```cpp
// Constants
constexpr int N = 1000, MOD = 1e9 + 7;
// 2D vector to store combinations
vector<vector<int>> nCr;
// if the nCr not build
bool is_nCr_built = false;

// Function to perform modular multiplication
template <typename T = int>T mul_mod(std::initializer_list<T> vals, T mod) {
    T res = 1;
    // Iterate through the values and multiply them, taking modulo at each step
    for (auto x : vals) res = (1LL * res * (x % mod)) % mod;
    return res;
}

// Function to build the nCr table
void build() {
    // Resize the nCr vector
    nCr = vector < vector < int > >(N + 5, vector < int > (N + 5));
    // Initialize the base cases
    for (int n = 0; n <= N; n++)
        nCr[n][0] = 1;
    // Calculate the combinations using dynamic programming
    for (int n = 1; n <= N; n++)
        for (int r = 1; r <= n; r++)
            nCr[n][r] = (nCr[n - 1][r - 1] + nCr[n - 1][r]) % MOD;
}

class Solution {
public:

    // Constructor to build the nCr table
    Solution() {
        if(!is_nCr_built)
            build();
        is_nCr_built = true;
    }

    // Recursive function to compute the number of ways to split the array
    int dfs(const vector<int>& nums) {
        // Base case: If the array size is less than or equal to 1, return 1
        if (nums.size() <= 1)
            return 1;
        // Separate the array into two parts: Left and Right
        vector<int> Left, Right;
        for (int i = 1; i < nums.size(); i++)
            (nums[i] >= nums[0] ? Right : Left).emplace_back(nums[i]);
        int L = Left.size(), R = Right.size();
        // Compute the number of ways recursively using modular multiplication
        return mul_mod({dfs(Left), dfs(Right), nCr[L + R][L]}, MOD);
    }

    // Function to compute the number of ways to split the array
    int numOfWays(const vector<int>& nums) {
        // Compute the number of ways recursively and subtract 1, then take modulo
        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
```
    
<hr>
<br><br>

## 17)  [Make Array Strictly Increasing](https://leetcode.com/problems/make-array-strictly-increasing/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Dynamic Programming` `Sorting`

### Code


```cpp
// Define constants
constexpr int N = 2005, INF = 2e9;

// Define variables and arrays
int dp[N][N][2];  // Dynamic programming array
int vis[N][N][2];  // Visited array
int n, m, id;  // Variables for size and identification
vector<int> a, b;  // Vectors for input arrays
bool is_memed = false;  // Flag for memory initialization

class Solution {
public:
    // Function to calculate the minimum moves
    int min_moves(int a_idx, int b_idx, bool is_a_last) {
        // Base case: if all elements in arr1 have been processed, return 0
        if (a_idx == n)
            return 0;
        
        // Reference to the current state in dp array
        int& ret = dp[a_idx][b_idx][is_a_last];
        
        // Check if the state has already been visited
        if (vis[a_idx][b_idx][is_a_last] == id)
            return ret;
        
        // Mark the state as visited
        vis[a_idx][b_idx][is_a_last] = id;
        
        // Initialize the minimum moves to a large value
        ret = INF;
        
        // Determine the last number in the sequence
        int last_num = is_a_last ? a[a_idx - 1] : b[b_idx - 1];
        
        // Case 1: Include the next element from arr1 if it is greater than the last number
        if (a[a_idx] > last_num)
            ret = min(ret, min_moves(a_idx + 1, b_idx, true));
        
        // Case 2: Include the next element from arr2 if it can make the sequence increasing
        int idx = upper_bound(b.begin(), b.end(), last_num) - b.begin();
        if (idx != m)
            ret = min(ret, 1 + min_moves(a_idx + 1, idx + 1, false));
        
        // Return the minimum moves
        return ret;
    }

    // Constructor
    Solution() {
        // Increment the identification
        id++;

        // Initialize the dp and visited arrays only once
        if (!is_memed) {
            memset(dp, -1, sizeof(dp));
            memset(vis, -1, sizeof(vis));
            is_memed = true;
        }
    }

    // Function to find the minimum moves to make the array increasing
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // Sort the second array in ascending order
        sort(arr2.begin(), arr2.end());
        
        // Assign the input arrays and their sizes
        a = arr1, b = arr2;
        n = a.size(), m = b.size();
        
        // Calculate the minimum moves starting with arr1[0] as the first element
        int best_moves = min(min_moves(1, 0, true), 1 + min_moves(1, 1, false));
        
        // If the minimum moves are greater than or equal to INF, set it to -1
        if (best_moves >= INF)
            best_moves = -1;
        
        // Return the best_moves
        return best_moves;
    }
};
```
    

<hr>
<br><br>

## 18)  [Number of Increasing Paths in a Grid](https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Depth-First Search` `Breadth-First Search` `Graph` `Topological Sort` `Memoization` `Matrix`

### Code


```cpp
class Solution {
public:

    int n, m; // Variables to store the dimensions of the grid
    vector < vector < int > > dp, grid; // 2D vectors to store dynamic programming values and the grid itself
    vector < pair < int, int > > dir; // Vector of pairs to store the possible directions to move
    static constexpr int MOD = 1e9 + 7; // Constant variable to represent the modulo value

    void add(int& a, int b){
        a += b; // Add 'b' to 'a'
        if(a >= MOD) a -= MOD; // If 'a' exceeds the modulo value, subtract the modulo value from 'a'
    }

    bool is_valid(int r, int c){
        return r >= 0 && r < n && c >= 0 && c < m; // Check if the indices 'r' and 'c' are within the grid boundaries
    }

    int get_paths(int x, int y){
        int& ret = dp[x][y]; // Reference to store the dynamic programming value for coordinates (x, y)
        if(~ret) return ret; // If the value is already computed, return it
        ret = 1; // Set the initial value of 'ret' to 1
        for(auto& [dx, dy] : dir){ // Iterate over the possible directions to move
            int nx = dx + x, ny = dy + y; // Calculate the new coordinates based on the direction
            if(is_valid(nx, ny) && grid[nx][ny] > grid[x][y]) // Check if the new coordinates are valid and the value at the new position is greater than the current position
                add(ret, get_paths(nx, ny)); // Recursively calculate the number of paths from the new position and add it to 'ret'
        }
        return ret; // Return the number of paths from position (x, y)
    }

    int countPaths(vector<vector<int>>& grid) {
        this -> grid = grid; // Store the input grid in the class member variable
        n = grid.size(), m = grid[0].size(); // Get the dimensions of the grid
        dp = vector < vector < int > > (n, vector < int > (m, -1)); // Initialize the dynamic programming values with -1
        dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} }; // Set the possible directions to move (right, left, down, up)
        int paths = 0; // Variable to store the total number of paths
        for(int i = 0; i < n; i++) // Iterate over each row of the grid
            for(int j = 0; j < m; j++) // Iterate over each column of the grid
                add(paths, get_paths(i, j)); // Add the number of paths from each position to 'paths'
        return paths; // Return the total number of paths
    }
};
```
    
<hr>
<br><br>

## 19)  [Find the Highest Altitude](https://leetcode.com/problems/find-the-highest-altitude/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Prefix Sum`

### Code


```cpp
class Solution {
public:
    // This function takes a vector of altitude gains as input and returns
    // the largest altitude reached.
    int largestAltitude(vector<int>& gain) {
        // Initialize variables for maximum altitude and current altitude.
        int maxAltitude = 0, currAltitude = 0;
        
        // Iterate over each altitude gain in the vector.
        for(auto& x : gain){
            // Update the current altitude by adding the current gain.
            currAltitude += x;
            
            // Update the maximum altitude if the current altitude is higher.
            maxAltitude = max(maxAltitude, currAltitude);
        }
        
        // Return the maximum altitude reached.
        return maxAltitude;
    }
};
```
    
<hr>
<br><br>

## 20)  [K Radius Subarray Averages](https://leetcode.com/problems/k-radius-subarray-averages/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Sliding Window`

### Code


```cpp
class Solution {
public:
    // This function takes a vector of integers and an integer 'k' as input and returns a vector of averages.
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(); // 'n' stores the size of the input vector
        int len = 2 * k + 1; // 'len' calculates the length of the subarray
        vector < int > avg(n); // 'avg' is a vector to store the averages of subarrays
        vector < long long > prefix(n); // 'prefix' is a vector to store the prefix sum of the input vector
        
        for(int i = 0; i < n; i++)
            prefix[i] = (i ? prefix[i - 1] : 0) + nums[i]; // Calculate the prefix sum
        
        // Create a lambda function 'sum' to calculate the sum of elements in a given range
        auto sum = [&](int l, int r) {
            return prefix[r] - (l ? prefix[l - 1] : 0);
        };
        
        for(int i = 0; i < n; i++) {
            int L = i - k; // Calculate the left index of the subarray
            int R = i + k; // Calculate the right index of the subarray
            bool isIn = (L >= 0 && R < n); // Check if the subarray is within the bounds of the input vector
            avg[i] = (isIn ? sum(L, R) / len : -1); // Calculate the average of the subarray or assign -1 if it is out of bounds
        }
        return avg; // Return the vector of averages
    }
};
```
    
<hr>
<br><br>

## 21)  [Minimum Cost to Make Array Equal](https://leetcode.com/problems/minimum-cost-to-make-array-equal/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Greedy` `Sorting` `Prefix Sum`

### Code


```cpp
class Solution {
public:
    long long minCost(const vector<int>& nums, const vector<int>& cost) {
        int n = nums.size(); // Get the size of the nums vector
        long long sum = 0, Cost1 = 0, Cost2 = 0;
        
        // Create a vector of pairs to store the corresponding values from nums and cost
        vector < pair < int, int > > vec(n);
        
        // Iterate over the nums and cost vectors and populate the vec vector with pairs
        for(int i = 0; i < n; i++){
            vec[i] = make_pair(nums[i], cost[i]);
            sum += cost[i]; // Calculate the sum of all costs
        }
        
        // Sort the vec vector in ascending order based on the nums values
        sort(vec.begin(), vec.end()); 
        
         // Calculate target1, target2, num1, and num2 to get the median of the costs
        long long target1 = sum / 2, target2 = target1 + 1, num1 = -1, num2 = -1;
        sum = 0; // Reset the sum variable
        
        // Iterate over the vec vector
        for(int i = 0; i < n; i++){
            auto [x, w] = vec[i]; // Destructure the pair into variables x and w
            sum += w; // Calculate the cumulative sum of weights
            
            // Check if the sum is greater than or equal to target1 and num1 has not been assigned a value yet
            if(sum >= target1 && !~num1) num1 = x;
            
            // Check if the sum is greater than or equal to target2 and num2 has not been assigned a value yet
            if(sum >= target2 && !~num2) num2 = x;
        }
        
        // Calculate the costs based on num1 and num2
        for(int i = 0; i < n; i++){
            auto [x, w] = vec[i]; // Destructure the pair into variables x and w
            
            // Calculate the cost1 by multiplying the absolute difference between x and num1 with w
            Cost1 += (1LL * abs(x - num1) * w);

            // Calculate the cost2 by multiplying the absolute difference between x and num2 with w 
            Cost2 += (1LL * abs(x - num2) * w);
        }
        
        // we calculate two median cause if n even the median can be n / 2, n / 2 + 1
        // Return the minimum cost between cost1 and cost2
        return min(Cost1, Cost2);
    }
};
```
    
<hr>
<br><br>

## 22)  [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Greedy`

### Code


```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // Get the number of prices in the vector.
        int n = prices.size();
        
        // Initialize variables for cash (available funds) and hold (stock held).
        // Set the initial value of hold to the negative of the first stock price.
        int cash = 0, hold = -prices[0];
        
        // Iterate through the prices starting from the second price.
        for(int i = 1; i < n; i++){ 
            // Calculate the maximum of either keeping the cash as it is or selling the stock and deducting the fee.
            cash = max(cash, hold + prices[i] - fee);
            
            // Calculate the maximum of either keeping the hold as it is or buying the stock and deducting the cash.
            hold = max(hold, cash - prices[i]);
        }
        
        // Return the maximum profit (cash) after all transactions.
        return cash;
    }
};
```
    
<hr>
<br><br>

## 23)  [Longest Arithmetic Subsequence](https://leetcode.com/problems/longest-arithmetic-subsequence/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Binary Search` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // Declaration of variables
    int n;
    static constexpr int D = 500;
    vector < int > nums;
    vector < vector < int > > dp, adj;

    int LAS(int idx, int diff) {
        // Base case: if we reach the end of the array, return 0
        if (idx == n) return 0;
        
        // Memoization: check if the result for the current index and difference is already calculated
        int& ret = dp[idx][diff + D];
        if (~ret) return ret;
        
        // Initialize the result to 0
        ret = 0;
        
        // Find the index of the next element that forms an arithmetic subsequence
        int nxtIDX = adj[idx][diff + D];
        
        // If a valid next index exists, recursively calculate the length of the next arithmetic subsequence
        if (~nxtIDX)
            ret = 1 + LAS(nxtIDX, diff);
        
        return ret;
    }

    void build() {
        // Initialize the adjacency matrix with -1
        this -> adj = vector < vector < int > >(n, vector < int > (2 * D + 5, -1));
        
        // Iterate through the array and populate the adjacency matrix
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!~adj[i][nums[j] - nums[i] + D])
                    adj[i][nums[j] - nums[i] + D] = j;
    }

    int longestArithSeqLength(vector<int>& nums) {
        // Initialize the class variables
        this -> n = nums.size();
        this -> nums = nums;
        this -> dp = vector < vector < int > > (n, vector < int > (2 * D + 5, -1));
        
        // Build the adjacency matrix
        build();
        
        // Initialize the maximum length of the arithmetic subsequence to 1
        int maxLAS = 1;
        
        // Iterate through all possible differences and indices
        for (int diff = -D; diff <= D; diff++)
            for (int idx = 0; idx < n; idx++)
                // Update the maximum length if a longer arithmetic subsequence is found
                maxLAS = max(maxLAS, 1 + LAS(idx, diff));
        
        // Return the maximum length of the arithmetic subsequence
        return maxLAS;
    }
};
```
    
<hr>
<br><br>

## 24)  [Tallest Billboard](https://leetcode.com/problems/tallest-billboard/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:

    int n; // Number of rods
    static constexpr int MAXN = 5000, INF = 1e9; // Constants for array size and infinite value
    vector < int > rods; // Vector to store the lengths of the rods
    vector < vector < int > > dp; // Dynamic programming array

    // Function to calculate the maximum score
    int max_score(int idx, int diff) {
        // Base case: If all rods have been processed, return 0 if the difference is 0, or -INF otherwise
        if (idx == n) return (!diff ? 0 : -INF);
        
        // Reference to the maximum score at current index and difference
        int& ret = dp[idx][diff + MAXN];
        
        // If the maximum score has already been calculated, return it 
        if (~ret) return ret; 

        // Scenario 1: Exclude the current rod
        ret = max_score(idx + 1, diff); 
        
        // Scenario 2: Include the current rod as positive difference
        ret = max(ret, rods[idx] + max_score(idx + 1, diff + rods[idx]));
        
        // Scenario 3: Include the current rod as negative difference
        ret = max(ret, max_score(idx + 1, diff - rods[idx]));

        // Return the maximum score
        return ret;
    }

    int tallestBillboard(vector<int>& rods) {
        this -> rods = rods; // Assign the input rods to the member variable
        this -> n = rods.size(); // Set the number of rods

        // Initialize the dynamic programming array with -1
        this -> dp = vector < vector < int > > (n, vector < int > (2 * MAXN + 5, -1));
        
        // Return the maximum score starting from index 0 and with 0 difference
        return max_score(0, 0);
    }
};
```
    
<hr>
<br><br>

## 25)  [Count All Possible Routes](https://leetcode.com/problems/count-all-possible-routes/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Memoization`

### Code


```cpp
class Solution {
public:
    // Constant variables
    static constexpr int MOD = 1e9 + 7;   // Modulo value
    static constexpr int N = 100;         // Maximum number of locations
    static constexpr int F = 200;         // Maximum fuel capacity

    // Member variables
    int n;                               // Number of locations
    int finish;                          // Destination location
    int dp[N][F];                        // Dynamic programming table
    vector < int > locations;               // Vector to store the locations

    // Function to add a value to another value and handle modulo
    void add(int& ret, int to_add) {
        ret += to_add;
        if (ret >= MOD)
            ret -= MOD;
    }

    // Function to count the number of ways to reach the destination with given fuel
    int cnt_ways(int curr, int fuel) {
        // Base case: If fuel is negative, no more moves can be made
        if (fuel < 0)
            return 0;

        // Check if the result is already computed
        int& ret = dp[curr][fuel];
        if (~ret)
            return ret;

        ret = 0;  // Initialize the result

        // If the current location is the destination, increment the result
        if (curr == finish)
            ret++;

        // Iterate through all possible next locations
        for (int nxt = 0; nxt < n; nxt++) {
            // Skip the current location
            if (curr != nxt)
                // Recursively count the ways by subtracting the fuel consumed
                add(ret, cnt_ways(nxt, fuel - abs(locations[nxt] - locations[curr])));
        }

        return ret;  // Return the result
    }

    // Function to initialize the member variables
    void init(vector<int>& locations, int finish) {
        this -> n = locations.size();
        this -> finish = finish;
        this -> locations = locations;
        memset(dp, -1, sizeof(dp));  // Initialize the dp table with -1
    }

    // Function to count the number of routes
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        init(locations, finish);  // Initialize the member variables
        return cnt_ways(start, fuel);  // Count the number of ways to reach the destination
    }
};
```
    
<hr>
<br><br>

## 26)  [Total Cost to Hire K Workers](https://leetcode.com/problems/total-cost-to-hire-k-workers/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Two Pointers` `Heap (Priority Queue)` `Simulation`

### Code


```cpp
class Solution {
public:
    // Using a template alias to define a priority queue with minimum element at the top
    template < typename T = int > using PQ = priority_queue < T, vector < T >, greater < T > >;

    // Function to calculate the total cost
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Priority queues to store the lowest k elements from the start and end
        PQ < int > first, last;
        
        // Lambda function to get the top element from a priority queue, returns INT_MAX if empty
        auto get_top = [&](PQ < int >& pq) {
            return pq.empty() ? INT_MAX : pq.top();
        };
        
        // Variables to store the total cost and the number of elements taken
        long long ans = 0, taken = 0;
        
        // Pointers to track the start and end of the costs vector
        int l = 0, r = costs.size() - 1;
        
        // Loop until the required number of elements are taken
        while (taken < k) {
            // Fill the first priority queue with the lowest elements from the start
            while (l <= r && first.size() < candidates)
                first.push(costs[l++]);
            
            // Fill the last priority queue with the lowest elements from the end
            while (l <= r && last.size() < candidates)
                last.push(costs[r--]);
            
            // Get the top elements from both priority queues
            int topF = get_top(first), topL = get_top(last);
            
            // Choose the smaller top element and add it to the total cost
            if (topF <= topL)
                ans += topF, first.pop();
            else
                ans += topL, last.pop();
            
            // Increase the count of taken elements
            taken++;
        }
        
        // Return the total cost
        return ans;
    }
};
```
    
<hr>
<br><br>

## 27)  [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Result vector to store the k smallest pairs
        vector < vector < int > > res;
        
        // If any of the input vectors is empty or k is zero, return an empty result
        if (nums1.empty() || nums2.empty() || k == 0)
            return res;
        
        // Custom comparator function to determine the order in priority queue based on sum of pair values
        auto cmp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        
        // Priority queue to store pairs, with the smallest sum at the top
        priority_queue < pair < int, int >, vector < pair < int, int > >, decltype(cmp) > pq(cmp);
        
        for (int i = 0; i < min(k, static_cast<int>(nums1.size())); ++i) {
            pq.push({i, 0}); // Push the indices of the pairs with the smallest values of nums1 into the priority queue
        }
        
        while (k-- > 0 && !pq.empty()) {
            // Get the pair with the smallest sum from the priority queue
            auto idx = pq.top();

            // Remove the pair from the priority queue
            pq.pop();

            // Add the pair to the result vector
            res.push_back({nums1[idx.first], nums2[idx.second]});
            
            // Push the next pair with the same index from nums1 but the next index from nums2
            if (idx.second + 1 < nums2.size()) 
                pq.push({idx.first, idx.second + 1});
        }
        
        // Return the k smallest pairs
        return res;
    }
};
```

<hr>
<br><br>

## 28)  [Path with Maximum Probability](https://leetcode.com/problems/path-with-maximum-probability/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Heap (Priority Queue)` `Graph` `Shortest Path`

### Code


```cpp
class Solution {
public:

    // Struct representing a vertex in the graph
    struct Vertex {
        int u; // Vertex index
        double w; // Weight of the edge
        Vertex(int u = 0, double w = 1) : u(u), w(w) {};
        
        // Overloading the less than operator for sorting
        bool operator < (const Vertex& rhs) const {
            return w < rhs.w;
        } 
    };

    vector < vector < pair < int, double > > > adj; // Adjacency list representing the graph

    // Function to build the adjacency list
    void build_adj(int n, vector < vector < int > >& edges, vector < double >& succProb) {
        adj = vector < vector < pair < int, double > > > (n); // Initialize the adjacency list with n elements
        
        // Loop through the edges and probabilities
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double w = succProb[i];
            adj[u].emplace_back(v, w); // Add an edge from u to v with weight w
            adj[v].emplace_back(u, w); // Add an edge from v to u with weight w
        }
    }

    // Function to find the maximum probability using Dijkstra's algorithm
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue < Vertex > dij; // Priority queue for Dijkstra's algorithm
        vector < double > dist(n, 0); // Initialize the distance vector with 0s
        build_adj(n, edges, succProb); // Build the adjacency list
        dij.emplace(start, 1); // Start vertex with probability 1
        dist[start] = 1; // Update the distance of the start vertex
        
        // Dijkstra's algorithm
        while(!dij.empty()){
            auto [u, cost] = dij.top();
            dij.pop();
            if(cost > dist[u]) continue; // Skip if a shorter path to u has already been found
            for(auto& [v, w] : adj[u]){
                if(dist[v] < cost * w){ // Update the distance if a shorter path is found
                    dist[v] = cost * w;
                    dij.emplace(v, dist[v]);
                }
            }
        }
        
        return dist[end]; // Return the maximum probability to reach the end vertex
    }
};
```

<hr>
<br><br>

## 29)  [Shortest Path to Get All Keys](https://leetcode.com/problems/shortest-path-to-get-all-keys/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Bit Manipulation` `Breadth-First Search` `Matrix`

### Code


```cpp
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
```
    

<hr>
<br><br>

## 30)  [Last Day Where You Can Still Cross](https://leetcode.com/problems/last-day-where-you-can-still-cross/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Union Find` `Matrix`

### Code


```cpp
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
```
    