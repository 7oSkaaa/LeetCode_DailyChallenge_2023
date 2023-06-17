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
constexpr int N = 2005, INF = 2e9;
int dp[N][N][2], vis[N][N][2], n, m, id;
vector < int > a, b;
bool is_memed = false;

class Solution {
public:

    int min_moves(int a_idx, int b_idx, bool is_a_last){
        if(a_idx == n) return 0;
        int& ret = dp[a_idx][b_idx][is_a_last];
        if(vis[a_idx][b_idx][is_a_last] == id)
            return ret;
        vis[a_idx][b_idx][is_a_last] = id;
        ret = INF;
        int last_num = is_a_last ? a[a_idx - 1] : b[b_idx - 1];
        if(a[a_idx] > last_num)
            ret = min(ret, min_moves(a_idx + 1, b_idx, true));
        int idx = upper_bound(b.begin(), b.end(), last_num) - b.begin();
        if(idx != m)
            ret = min(ret, 1 + min_moves(a_idx + 1, idx + 1, false));
        return ret;
    }

    Solution(){
        id++;
        if(!is_memed){
            memset(dp, -1, sizeof(dp));
            memset(dp, -1, sizeof(vis));
            is_memed = true;
        }
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        a = arr1, b = arr2;
        n = a.size(), m = b.size();
        int best_moves = min(min_moves(1, 0, true), 1 + min_moves(1, 1, false));
        if(best_moves >= INF)
            best_moves = -1;
        return best_moves;
    }
};
```
    