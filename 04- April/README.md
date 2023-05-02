# LeetCode Daily Challenge Problems for April

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

1. **[Binary Search](#01--binary-search)**
1. **[Successful Pairs of Spells and Potions](#02--successful-pairs-of-spells-and-potions)**
1. **[Boats to Save People](#03--boats-to-save-people)**
1. **[Optimal Partition of String](#04--optimal-partition-of-string)**
1. **[Minimize Maximum of Array](#05--minimize-maximum-of-array)**
1. **[Number of Closed Islands](#06--number-of-closed-islands)**
1. **[Number of Enclaves](#07--number-of-enclaves)**
1. **[Clone Graph](#08--clone-graph)**
1. **[Largest Color Value in a Directed Graph](#09--largest-color-value-in-a-directed-graph)**
1. **[Valid Parentheses](#10--valid-parentheses)**
1. **[Removing Stars From a String](#11--removing-stars-from-a-string)**
1. **[Simplify Path](#12--simplify-path)**
1. **[Validate Stack Sequences](#13--validate-stack-sequences)**
1. **[Longest Palindromic Subsequence](#14--longest-palindromic-subsequence)**
1. **[Maximum Value of K Coins From Piles](#15--maximum-value-of-k-coins-from-piles)**
1. **[Number of Ways to Form a Target String Given a Dictionary](#16--number-of-ways-to-form-a-target-string-given-a-dictionary)**
1. **[Kids With the Greatest Number of Candies](#17--kids-with-the-greatest-number-of-candies)**
1. **[Merge Strings Alternately](#18--merge-strings-alternately)**
1. **[Longest ZigZag Path in a Binary Tree](#19--longest-zigzag-path-in-a-binary-tree)**
1. **[Maximum Width of Binary Tree](#20--maximum-width-of-binary-tree)**
1. **[Profitable Schemes](#21--profitable-schemes)**
1. **[Minimum Insertion Steps to Make a String Palindrome](#22--minimum-insertion-steps-to-make-a-string-palindrome)**
1. **[Restore The Array](#23--restore-the-array)**
1. **[Last Stone Weight](#24--last-stone-weight)**
1. **[Smallest Number in Infinite Set](#25--smallest-number-in-infinite-set)**
1. **[Add Digits](#26--add-digits)**
1. **[Bulb Switcher](#27--bulb-switcher)**
1. **[Similar String Groups](#28--similar-string-groups)**
1. **[Checking Existence of Edge Length Limited Paths](#29--checking-existence-of-edge-length-limited-paths)**
1. **[Remove Max Number of Edges to Keep Graph Fully Traversable](#30--remove-max-number-of-edges-to-keep-graph-fully-traversable)**

<hr>
<br><br>

## 01)  [Binary Search](https://leetcode.com/problems/binary-search/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int search(vector < int >& nums, int target) {
        // the start and end of the interval that we will search in it
        int l = 0, r = nums.size() - 1;

        // Start a while loop with condition "l <= r".
        while(l <= r){
            // Declare an integer variable "m" and initialize it to the midpoint between "l" and "r".
            int m = l + (r - l) / 2;
            
            // If the value at index "m" in the "nums" vector is equal to the target integer, return "m".
            if(nums[m] == target) return m;
            
            // If the value at index "m" in the "nums" vector is less than the target integer, update "l" to "m + 1". Otherwise, update "r" to "m - 1".
            (nums[m] < target ? l = m + 1 : r = m - 1);
        }

        // If the target integer was not found in the "nums" vector, return -1.
        return -1;
    }
};
```
    

<hr>
<br><br>

## 02)  [Successful Pairs of Spells and Potions](https://leetcode.com/problems/successful-pairs-of-spells-and-potions/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Two Pointers` `Binary Search` `Sorting`

### Code


```cpp
class Solution {
public:

    // Inline function to calculate the ceil value
    inline long long ceil(long long a, long long b){
        return (a + b - 1) / b;
    }

    // Function to calculate successful pairs
    vector < int > successfulPairs(vector < int >& spells, vector < int >& potions, long long success) {
        // Get the sizes of vectors
        int n = spells.size(), m = potions.size();
        
        // Sort potions vector
        sort(potions.begin(), potions.end());
        
        // Vector to store successful pairs
        vector < int > successful_pairs;
        
        for(auto& x : spells){
            // Calculate target value for a spell that will make it greater than success
            long long target = ceil(success, x);
            
            // Get the index of first potion having value greater or equal to target
            int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            
            // Calculate number of successful pairs
            successful_pairs.push_back(m - idx);
        }

        // Return the vector containing number of successful pairs for each spell
        return successful_pairs;
    }
};
```
    
<hr>
<br><br>

## 03)  [Boats to Save People](https://leetcode.com/problems/boats-to-save-people/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Two Pointers` `Greedy` `Sorting`

### Code


```cpp
class Solution {
public:
    // Function to calculate the number of rescue boats required
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the array in ascending order
        sort(people.begin(), people.end());
        
        // Initialize variables for left index, right index and number of boats
        int l = 0, r = people.size() - 1, boats = 0;
        
        // Iterate through the array using two pointers, one from the left and one from the right
        while(l <= r){
            // If the sum of the weights of the people at the two pointers is less than or equal to the limit, increment the left pointer
            if(people[l] + people[r] <= limit) l++;
            
            // Decrement the right pointer and increment the number of boats
            r--, boats++;
        }
        
        // Return the total number of boats required
        return boats;
    }

};
```
    
<hr>
<br><br>

## 04)  [Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `String` `Greedy`

### Code


```cpp
class Solution {
public:
    int partitionString(string& s) {
        int partitions = 1, mask = 0;
        
        // Iterate over each character in the string
        for(auto& c : s){
            // Create a mask for the current character
            int curr_mask = (1 << (c - 'a'));
            
            // If the current mask is already present in the mask variable
            // increment the number of partitions and reset the mask variable
            if(mask & curr_mask)
                partitions++, mask = 0;
            
            // XOR the current mask with the mask variable
            mask ^= curr_mask;
        }
        
        // Return the number of partitions
        return partitions;
    }
};
```
    
<hr>
<br><br>

## 05)  [Minimize Maximum of Array](https://leetcode.com/problems/minimize-maximum-of-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Dynamic Programming` `Greedy` `Prefix Sum`

### Code


```cpp
class Solution {
public:

    // make shortcut for long long
    #define ll long long

    int minimizeArrayValue(vector < int >& nums) {
        // Lambda function that takes an integer as input and returns a boolean value indicating whether the given integer is good or not.
        auto is_good = [&](ll m){
            // If the first element in the vector is greater than the given integer, it cannot be good.
            if(nums[0] > m) return false;
            ll last = nums[0];
            
            // Loop through the vector starting from the second element.
            for(int i = 1; i < nums.size(); i++){
                // Calculate the value to be removed from the previous element to make it less than or equal to the given integer.
                ll to_remove = m - last;
                
                // Calculate the new value for the current element after removing the calculated value from the previous element.
                last = nums[i] - abs(to_remove);
                
                // If the new value is greater than the given integer, it cannot be good.
                if(last > m) 
                    return false;
            }
            
            // All elements in the vector are less than or equal to the given integer, hence it is good.
            return true;
        };
        
        // Initialize the lower and upper bounds of the binary search.
        int l = 0, r = 1e9, ans = -1;
        
        // Binary search for the minimum good integer.
        while(l <= r){
            // Calculate the middle point.
            int m = l + (r - l) / 2;
            
            // If the middle point is good, update the upper bound and the answer.
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }

        // Return the minimum good integer.
        return ans;
    }

};
```
    
<hr>
<br><br>

## 06)  [Number of Closed Islands](https://leetcode.com/problems/number-of-closed-islands/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Depth-First Search` `Breadth-First Search` `Union Find` `Matrix`

### Code


```cpp
class Solution {
public:

    // Declare variables for the size of the grid
    int n, m;

    // make the given grid global
    vector < vector < int > > grid;

    // Check if a given cell is inside the grid.
    bool is_valid(int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    }

    // DFS to traverse the grid and check if a cell is part of an island.
    bool dfs(int r, int c) {
        // If the cell is not inside the grid, return false.
        if (!is_valid(r, c)) return false;
        
        // If the cell is already part of an island, return true.
        if (grid[r][c]) return true;
        
        // Mark the cell as visited by changing its value to 2.
        grid[r][c] = 2;
        
        // Traverse all the neighbors of the cell recursively and check if they are part of an island.
        bool valid = true;
        valid &= dfs(r - 1, c);
        valid &= dfs(r + 1, c);
        valid &= dfs(r, c - 1);
        valid &= dfs(r, c + 1);
        
        // Return true if all the neighbors are part of an island, false otherwise.
        return valid;
    }

    // Function to count the number of closed islands in the grid.
    int closedIsland(vector<vector<int>>& mat) {
        // Assign the input grid to the class grid variable, and get its size.
        this -> grid = mat;
        n = grid.size(), m = grid[0].size();
        
        // Initialize the answer variable to zero, and traverse the entire grid to count the number of closed islands.
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!grid[i][j])
                    ans += dfs(i, j);
        
        // Return the number of closed islands.
        return ans;
    }

};
```
    
<hr>
<br><br>

## 07)  [Number of Enclaves](https://leetcode.com/problems/number-of-enclaves/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Depth-First Search` `Breadth-First Search` `Union Find` `Matrix`

### Code


```cpp
class Solution {
public:
    
    // Initializing two 2D vectors to store the grid values
    vector < vector < int > > grid;

    // Variables for the dimensions of the grid
    int n, m;

    // Function to check if a cell is valid
    bool is_valid(int r, int c){
        return r >= 0 && c >= 0 && r < n && c < m && grid[r][c];
    }

    // Depth first search function
    int dfs(int r, int c){
        // If the cell is not valid return 0
        if(!is_valid(r, c)) return 0;

        // Set the cell as visited
        grid[r][c] = 0;
        
        // Return 1 plus the results of the DFS of the adjacent cells
        return 1 + dfs(r + 1, c) + dfs(r, c + 1) + dfs(r - 1, c) + dfs(r, c - 1);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // Set the grid dimensions
        this -> grid = grid;
        n = grid.size(), m = grid[0].size();
                
        // Perform DFS on all cells on the border
        for(int i = 0; i < n; i++) dfs(i, 0); // left border
        for(int i = 0; i < n; i++) dfs(i, m - 1); // right border
        for(int i = 0; i < m; i++) dfs(0, i); // upper border
        for(int i = 0; i < m; i++) dfs(n - 1, i); // lower border
        
        // Count the number of enclaves by performing DFS on each valid cell
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(is_valid(i, j))
                    cnt += dfs(i, j);
        
        // Return the count of enclaves
        return cnt;
    }

};
```
    
<hr>
<br><br>

## 08)  [Clone Graph](https://leetcode.com/problems/clone-graph/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Depth-First Search` `Breadth-First Search` `Graph`

### Code


```cpp
class Solution {
public:
    
    // Define an unordered map to store the nodes and their copies
    unordered_map < int, Node* > mp;

    // Define a function to clone the given graph
    Node* cloneGraph(Node* node) {
        // If node is NULL, return the node
        if (node == NULL) return node;

        // If the node already exists in the map, return its copy
        if (mp.count(node -> val)) return mp[node -> val];

        // Create a vector to store the neighbors of the current node and add the current node to the map
        mp[node -> val] = new Node(node -> val, {});

        // Recursively clone the neighbors of the current node and add them to the copy's neighbors vector
        for (auto& newNode : node -> neighbors) {
            Node* newNeighbors = cloneGraph(newNode);
            mp[node -> val] -> neighbors.push_back(newNeighbors);
        }

        // Return the copy of the given node
        return mp[node -> val];
    }
};
```
    
<hr>
<br><br>

## 09)  [Largest Color Value in a Directed Graph](https://leetcode.com/problems/largest-color-value-in-a-directed-graph/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Hash Table` `Dynamic Programming` `Graph` `Topological Sort` `Memoization` `Counting`

### Code


```cpp
class Solution {
public:

    int largestPathValue(const string& colors, vector<vector<int>>& edges) {
        // Initialize variables 'n', 'maxFreq', and 'visited' with initial values.
        int n = colors.size(), maxFreq = 0, visited = 0;
        
        // Initialize a vector called 'adj' with size 'n'.
        vector < vector < int > > adj(n);
        
        // Initialize a vector called 'deg' with size 'n'.
        vector < int > deg(n);
        
        // Initialize a vector called 'freq' with size 'n x 26', and all elements initialized to 0.
        vector < vector < int > > freq(n, vector < int > (26));
        
        // Loop through each vector in the 'edges' vector.
        for(auto& vec : edges){
            // Add the second element in the current vector to the adjacency list of the first element.
            adj[vec[0]].push_back(vec[1]);
            // Increment the degree of the second element.
            deg[vec[1]]++;
        }
        
        // Initialize a queue called 'topo'.
        queue < int > topo;
        
        // Loop through each element in the range [0, n).
        for(int v = 0; v < n; v++)
            // If the degree of the current element is 0, add it to the queue.
            if(!deg[v])
                topo.push(v);
                
        // While the queue is not empty:
        while(!topo.empty()){
            // Get the front element of the queue.
            int u = topo.front();
            
            // Remove the front element from the queue.
            topo.pop();
            
            // Increment the visited counter.
            visited++;
            
            // Update the maximum frequency seen so far.
            maxFreq = max(maxFreq, ++freq[u][colors[u] - 'a']);
            
            // Loop through each element in the adjacency list of the current element.
            for(auto& v : adj[u]){
                // Decrement the degree of the current element.
                if(--deg[v] == 0)
                    // If the degree of the current element is 0, add it to the queue.
                    topo.push(v);
                
                // Loop through each character in the range ['a', 'z'].
                for(char c = 'a'; c <= 'z'; c++)
                    // Update the frequency of the current character in the adjacency list of the current element.
                    freq[v][c - 'a'] = max(freq[v][c - 'a'], freq[u][c - 'a']);
            }
        }
        
        // If all elements have been visited, return the maximum frequency seen so far. Otherwise, return -1.
        return visited == n ? maxFreq : -1;
    }

};
```
    
<hr>
<br><br>

## 10)  [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`String` `Stack`

### Code


```cpp
class Solution {
public:
    bool isValid(const string& s) {
        // Initialize a stack to hold open parenthesis, braces, and brackets
        stack < char > st;
        // Iterate over each character in the string
        for (auto& c : s) {
            // If the character is an open parenthesis, brace, or bracket, add it to the stack
            if (c == '(' || c == '{' || c == '[') st.push(c);
            // If the character is a close parenthesis, brace, or bracket
            else if ((c == ')' || c == '}' || c == ']') && st.empty()) return false;
            // If the stack is empty, the string is invalid, return false
            else {
                // Check if the top element of the stack matches the current character, if so pop the stack
                if (c == ')' && st.top() == '(') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                // If the top element of the stack does not match the current character, return false
                else return false;
            }
        }
        // If the stack is empty, the string is valid, return true
        return st.empty();
    }
};
```
    
<hr>
<br><br>

## 11)  [Removing Stars From a String](https://leetcode.com/problems/removing-stars-from-a-string/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Stack` `Simulation`

### Code


```cpp
class Solution {
public:
    string removeStars(const string& s) {
        string without_stars;

        //iterating over the string s
        for(auto& c : s){
            //if the current character is an asterisk, remove the last character from the answer string
            if(c == '*')
                without_stars.pop_back();
            //otherwise, add the current character to the answer string
            else
                without_stars += c;
        }
        
        //return the answer string without the asterisks
        return without_stars;
    }

};
```
    
<hr>
<br><br>

## 12)  [Simplify Path](https://leetcode.com/problems/simplify-path/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Stack`

### Code


```cpp
class Solution {
public:

    string simplifyPath(string path) {
        // Initialize variables
        int length = path.size();
        string ans;
        stack < int > S;
        int i = 1;
        
        // Loop through the path
        while(i < length){
            // Add a slash to the answer string
            ans += "/";
            
            // Find the next index of '/'
            int next_ind = path.find('/', i);
            
            // If there are no more '/', set next_ind to the end of the path
            if(next_ind == std::string::npos) next_ind = length;
            
            // Get the current directory
            string curr_dir = path.substr(i, next_ind - i);
            
            // If the current directory is empty or '.', remove the last character from the answer string
            if(curr_dir.empty() || curr_dir == ".") ans.pop_back();
            // If the current directory is '..', remove the last directory from the answer string
            else if(curr_dir == ".."){
                if(S.empty()) ans.clear();
                else{
                    int prev_idx = S.top();
                    S.pop();
                    ans = ans.substr(0, prev_idx - 1);
                }
            }
            // Otherwise, add the current directory to the answer string
            else{
                int curr_length = ans.size();
                S.push(curr_length);
                ans += curr_dir;
            }
            
            // Update i to the next index of '/'
            i = next_ind + 1;
        }
        
        // If the answer string is empty, return '/'
        if(ans.empty()) return "/";
        return ans;
    }
};
```
    
<hr>
<br><br>

## 13)  [Validate Stack Sequences](https://leetcode.com/problems/validate-stack-sequences/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Stack` `Simulation`

### Code


```cpp
class Solution {
public:

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Define a vector to store the current state
        vector < int > state;
        
        // Initialize variables i, j, and n
        int i = 0, j = 0, n = pushed.size();
        
        // Initialize variables last_i and last_j
        int last_i = i, last_j = j;
        
        // Loop through pushed vector
        while(i < n){
            // Save current i and j values
            last_i = i, last_j = j;
            
            // Loop through pushed vector until we find the value of popped[i]
            while(j < n && pushed[j] != popped[i]) {
                // Add current value to the state vector
                state.push_back(pushed[j++]);
            }
            
            // If we found the value of popped[i], add it to the state vector
            if(j < n) {
                state.push_back(pushed[j++]);
            }
            
            // Loop through state vector and remove elements that match popped[i]
            while(!state.empty() && state.back() == popped[i]) {
                state.pop_back();
                i++;
            }
            
            // If we haven't made any progress, return false
            if(i == last_i && j == last_j) {
                return false;
            }
        }
        
        // If we have looped through the entire pushed vector and there are no elements left in state, return true
        return (i == n && j == n);
    }
};
```
    
<hr>
<br><br>

## 14)  [Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    int longestPalindromeSubseq(const string& s) {
        // Store the size of the given string
        int sz = s.size();

        // Create a 2D vector with size (sz + 5) * (sz + 5) and initialize all elements to 0
        vector < vector < int > > dp(sz + 5, vector < int > (sz + 5));

        // Loop through all possible pairs of (i, j) where 1 <= i, j <= sz
        for(int i = 1; i <= sz; i++) {
            for(int j = 1; j <= sz; j++) {

                // If the i-th character of the string is equal to the (sz - j + 1)-th character of the string
                if(s[i - 1] == s[sz - j]) {

                    // Update dp[i][j] to be 1 plus the value of dp[i - 1][j - 1]
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {

                    // Otherwise, update dp[i][j] to be the maximum of dp[i - 1][j] and dp[i][j - 1]
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Return the value of dp[sz][sz], which represents the length of the longest palindromic subsequence
        return dp[sz][sz];
    }
};
```
    
<hr>
<br><br>

## 15)  [Maximum Value of K Coins From Piles](https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Prefix Sum`

### Code


```cpp
class Solution {
public:
   
    // This macro is used to get the size of a container 
    #define sz(x) int(x.size())

    // Function to find the maximum value of coins that can be obtained
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        
        // Dynamic programming table to store the maximum value of coins that can be obtained for each state
        vector < vector < int > > dp(n + 1, vector < int > (k + 1));
        
        // Loop through all the possible remaining values of coins
        for(int remain = 0; remain <= k; remain++){
            // Loop through all the piles from right to left
            for(int i = n - 1; ~i; i--){
                // The maximum value of coins that can be obtained if we don't take any coins from this pile
                dp[i][remain] = dp[i + 1][remain];

                // Loop through all the possible number of coins that can be taken from this pile
                for(int take = 1, sum = 0; take <= min(remain, sz(piles[i])); take++){
                    // Calculate the total value of the coins taken
                    sum += piles[i][take - 1];
                    
                    // Update the maximum value of coins that can be obtained for this state
                    dp[i][remain] = max(dp[i][remain], sum + dp[i + 1][remain - take]);
                }
            }
        }

        // Return the maximum value of coins that can be obtained for the initial state
        return dp[0][k];
    }
};
```
    
<hr>
<br><br>

## 16)  [Number of Ways to Form a Target String Given a Dictionary](https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // This function takes a vector of strings 'words' and a string 'target' as input and returns the number of ways to form the 'target' string
    int numWays(vector<string>& words, string target) {
        // Initializing variables
        int n = words.size(), len = words[0].size(), k = target.size();

        // Using a vector of unordered_map to store the frequency of each character in each position of the 'words' vector
        vector < unordered_map < char, int > > frequencies(len);
        
        // Calculating the frequency of each character in each position of the 'words' vector
        for(auto& word : words)
            for(int i = 0; i < len; i++)
                frequencies[i][word[i]]++;
        
        // Defining the constant MOD value
        constexpr int MOD = 1000000007;
        
        // Initializing a 2D vector 'dp' to store the number of ways to form the 'target' string
        vector < vector < int > > dp(k+1, vector < int > (len + 1));
        
        // Initializing the 'dp' vector for base case
        dp[0] = vector < int > (len + 1, 1);
        
        // Filling the 'dp' vector using dynamic programming
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= len; j++){
                dp[i][j] += dp[i][j - 1];
                dp[i][j] += (1ll * frequencies[j - 1][target[i - 1]] * dp[i - 1][j - 1]) % MOD;
                dp[i][j] %= MOD;
            }
        }

        // Returning the number of ways to form the 'target' string
        return dp[k][len];
    }

};
```
    
<hr>
<br><br>

## 17)  [Kids With the Greatest Number of Candies](https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array`

### Code


```cpp
class Solution {
public:

    vector < bool > kidsWithCandies(vector < int >& candies, int extraCandies) {
        // This variable finds the maximum number of candies any kid has
        int Max = *max_element(candies.begin(), candies.end());

        // This creates a boolean vector with the same size as the candies vector
        vector<bool> can(candies.size());

        // This loop checks if each kid can have the most number of candies
        // after adding the extra candies, and stores the result in the boolean vector
        for(int i = 0; i < candies.size(); i++)
            can[i] = candies[i] + extraCandies >= Max;

        // This returns the boolean vector
        return can;
    }
};
```
    
<hr>
<br><br>

## 18)  [Merge Strings Alternately](https://leetcode.com/problems/merge-strings-alternately/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Two Pointers` `String`

### Code


```cpp
class Solution {
public:
    string mergeAlternately(const string& s, const string& t) {
        // Initialize indices and sizes of s and t
        int i = 0, j = 0, n = s.size(), m = t.size();
        
        // Initialize the merged string
        string merged;
        
        // Merge s and t alternately while there are still characters in both strings
        while(i < n && j < m) {
            merged += s[i++];
            merged += t[j++];
        }

        // If there are still characters in s, add them to the merged string
        while(i < n)
            merged += s[i++];

        // If there are still characters in t, add them to the merged string
        while(j < m)
            merged += t[j++];

        // Return the merged string
        return merged;
    }

};
```
    
<hr>
<br><br>

## 19)  [Longest ZigZag Path in a Binary Tree](https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Dynamic Programming` `Tree` `Depth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    
    // Function to find the length of the longest zigzag path in a binary tree
    int longestZigZag(TreeNode* root) {
        // If root is the only node or if the root has no left or right child, return 0
        if(!root -> left && !root -> right)
            return 0;
        
        // Call the depth-first search function with the root, length 0, and shouldGoLeft flag set to false
        return dfs(root, 0, false);
    }

    // Function to perform depth-first search
    int dfs(TreeNode* root, int length, bool shouldGoLeft) {
        // If the current node is null, return the current length
        if(!root) return length;
        
        // Declare variables for left and right paths and the current length
        int left = 0, right = 0, currLen = 0;
        
        // If shouldGoLeft flag is set and there is no left child for the current node, set currLen to length and reset length to 0
        if(shouldGoLeft && !root -> left)
            currLen = length, length = 0;
        // If shouldGoLeft flag is not set and there is no right child for the current node, set currLen to length and reset length to 0
        else if(!shouldGoLeft && !root -> right)
            currLen = length, length = 0;
        
        // Recursively call dfs function for the right and left nodes and update their lengths accordingly
        right = dfs(root -> right, shouldGoLeft ? 1 : length + 1, true);
        left = dfs(root -> left, shouldGoLeft ? length + 1 : 1, false);
        
        // Return the maximum of left, right, length and currLen
        return max({left, right, length, currLen});
    }

};
```
    

<hr>
<br><br>

## 20)  [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    
    // Function to calculate the maximum width of a binary tree
    int widthOfBinaryTree(TreeNode* root) {

        // Return 0 if the tree is empty
        if(!root) return 0;

        // Create a queue to store the nodes of the binary tree
        // A pair is used to store the node and its index
        queue < pair < TreeNode*, int > > bfs;

        // Push the root node and its index to the queue
        bfs.push({root, 1});

        // Set the initial result to 1
        int res = 1;

        // Loop until the queue is empty
        while(!bfs.empty()){
            
            // Get the number of nodes in the current level
            int sz = bfs.size();
            
            // Get the index of the first node in the current level
            int prev = bfs.front().second;
            
            // Update the result by finding the difference between the index of the first and last nodes in the current level
            res = max(res, bfs.back().second - bfs.front().second + 1);
            
            // Process all the nodes in the current level
            while(sz--){
                
                // Get the current node and its index from the queue
                auto [node, curr] = bfs.front();
                
                // If the current node has a left child, push it to the queue with the appropriate index
                if(node -> left) 
                    bfs.push({node -> left, 2ll * (curr - prev) + 1});
                
                // If the current node has a right child, push it to the queue with the appropriate index
                if(node -> right) 
                    bfs.push({node -> right, 2ll * (curr - prev) + 2});
                
                // Remove the current node from the queue
                bfs.pop();
            }
        }
        
        // Return the result
        return res;
    }

};
```
    
<hr>
<br><br>

## 21)  [Profitable Schemes](https://leetcode.com/problems/profitable-schemes/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:

    // Constants
    static constexpr int MOD = 1e9 + 7;
    static constexpr int N = 105;

    // Declare variables
    int dp[N][N][N];
    int n, minProfit;
    vector < int > group, profit;

    // Function to count the number of ways to form profitable schemes
    int cnt_ways(int idx, int members, int prof){
        // If we have iterated through all the groups, check if the profit is greater than or equal to minProfit
        if(idx == group.size()) return prof >= minProfit;
        
        // Memoization
        int& ret = dp[idx][members][prof];
        if(~ret) return ret;
        
        // Recursion
        ret = cnt_ways(idx + 1, members, prof) % MOD;
        if(members + group[idx] <= n)
            ret = (ret + cnt_ways(idx + 1, members + group[idx], min(minProfit, prof + profit[idx]))) % MOD;
        return ret;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        // Initialize variables
        memset(dp, -1, sizeof(dp));
        this -> group = group, this -> profit = profit;
        this -> n = n, this -> minProfit = minProfit;
        
        // Call recursive function and return result
        return cnt_ways(0, 0, 0);
    }

};
```
    
<hr>
<br><br>

## 22)  [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // This function calculates the minimum number of insertions needed to make a given string a palindrome.
    int minInsertions(const string& s) {

        // The size of the string.
        int n = s.size();

        // Creating a 2D vector of size 2 x (n+1) to store the dynamic programming table.
        vector < vector < int > > dp(2, vector < int > (n + 1));

        // Looping through the string from end to start.
        for(int l = n; l >= 1; l--) {

            // Looping through the string from start to end.
            for(int r = l; r <= n; r++) {

                // If the characters at the left and right ends are same, then the answer is the same as that for the substring without these two characters.
                if(s[l - 1] == s[r - 1]) 
                    dp[l & 1][r] = dp[(l + 1) & 1][r - 1];

                // Else, we need to add one character either at the beginning or end, so we take the minimum of two cases:
                // 1) Add character to the left end and recur for substring s[l+1..r]
                // 2) Add character to the right end and recur for substring s[l..r-1]
                else
                    dp[l & 1][r] = 1 + min(dp[(l + 1) & 1][r], dp[l & 1][r - 1]);
            }
        }

        // Returning the answer, which is stored in dp[1][n].
        return dp[1][n];
    }

};
```
    

<hr>
<br><br>

## 23)  [Restore The Array](https://leetcode.com/problems/restore-the-array/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:

    // Set a constant value for modulo operation
    static constexpr int MOD = 1e9 + 7;

    // Declare a vector named dp to store the calculated values
    vector < long long > dp;

    // Define a function named add, which adds two integers and apply modulo operation on the result
    void add(long long& a, int b){
        a += b;
        if(a >= MOD)
            a -= MOD;
    }

    // Define a recursive function named cnt_ways which takes three arguments, 
    // idx denotes the current index of string s, k is an integer value,
    // and s is the string given as an input to the function.
    int cnt_ways(int idx, int k, const string& s){
        // If the end of the string is reached, then return 1
        if(idx == s.size()) return 1;
        
        // Use reference variable ret to store the value of dp[idx]
        // num is used to store the integer value of the substring s[idx...i]
        long long &ret = dp[idx], num = 0;
        
        // If the value of dp[idx] has been calculated before, return the stored value
        if(~ret) return ret;
        
        // Set ret to 0
        ret = 0;
        
        // Iterate from idx to the end of the string, and calculate the integer value of the substring s[idx...i] using variable num
        // If the integer value of the substring is less than or equal to k, then add the number of ways of splitting the string from index i+1 to the end of the string, to the value of ret
        for(int i = idx; i < s.size(); i++){
            num = num * 10 + (s[i] - '0');
            if(num >= 1 && num <= k)
                add(ret, cnt_ways(i + 1, k, s));
            else
                break;
        }
        return ret;
    }

    // Define a function named numberOfArrays which takes two arguments, 
    // s is a string and k is an integer value.
    int numberOfArrays(const string& s, int k) {
        // Initialize dp vector with -1 and size s.size() + 5
        dp = vector < long long > (s.size() + 5, -1);
        
        // Return the number of ways to split the string
        return cnt_ways(0, k, s);
    }

};
```
    
<hr>
<br><br>

## 24)  [Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        //Creates a priority queue with integers
        priority_queue<int> pq;

        //Inserts each stone in the priority queue
        for(auto& stone : stones)
            pq.push(stone);

        //Lambda function to get the top 2 elements from the priority queue and remove them
        auto get_top = [&](){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            return make_pair(x, y);
        };

        //Loops while there are more than 1 stone in the priority queue
        while(pq.size() > 1){
            //Gets the top 2 stones and removes them from the priority queue
            auto [x, y] = get_top();
            
            //If the 2 stones are different, it inserts the difference into the priority queue
            if(x != y)
                pq.push(x - y);
        }

        //Returns the weight of the last stone or 0 if the priority queue is empty
        return (pq.empty() ? 0 : pq.top());
    }
};
```
    
<hr>
<br><br>

## 25)  [Smallest Number in Infinite Set](https://leetcode.com/problems/smallest-number-in-infinite-set/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Design` `Heap (Priority Queue)`

### Code


```cpp
class SmallestInfiniteSet {
public:
    // Define a set variable named Mex
    set < int > Mex;

    // Define a constant integer N with a value of 1000
    static constexpr int N = 1000;

    // Constructor function for the SmallestInfiniteSet class
    SmallestInfiniteSet() {
        // Loop through integers from 1 to N and insert them into the set variable Mex
        for(int i = 1; i <= N; i++)
            Mex.insert(i);
    }
    
    // Function to remove and return the smallest integer from the set variable Mex
    int popSmallest() {
        // Store the smallest integer in the set variable Mex
        int mex = *Mex.begin();

        // Remove the smallest integer from the set variable Mex
        Mex.erase(Mex.begin());
        
        // Return the smallest integer
        return mex;
    }
    
    // Function to add an integer back to the set variable Mex
    void addBack(int num) {
        // Insert the integer into the set variable Mex
        Mex.insert(num);
    }
};
```
    
<hr>
<br><br>

## 26)  [Add Digits](https://leetcode.com/problems/add-digits/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Math` `Simulation` `Number Theory`

### Code


```cpp
class Solution {
public:

    // A function to find the sum of digits of a given number
    int sumDigits(int num){
        // Initialize the sum variable to zero
        int sum = 0;
        
        // Convert the number to a string and iterate over each character
        for(auto& c : to_string(num))
            // Subtract the ASCII value of '0' from the character and add it to the sum
            sum += c - '0';

        // Return the sum of digits
        return sum;
    }

    int addDigits(int num) {
        // Repeat the process until the number is a single digit
        while(num > 9)
            // Sum the digits of the number
            num = sumDigits(num);
            
        // Return the resulting single digit
        return num;
    }
};
```
    
<hr>
<br><br>

## 27)  [Bulb Switcher](https://leetcode.com/problems/bulb-switcher/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Math` `Brainteaser`

### Code


```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        // for this problem we need to know how many light bulbs are on after n rounds
        // to know that you need to know for each light bulb to stay on at the end it needs to have odd number of divisors
        // the only numbers that have odd number of divisors are perfect squares
        // so the answer is the number of perfect squares less than or equal to n
        // which is sqrt(n)


        return sqrt(n);
    }
};
```
    
<hr>
<br><br>

## 28)  [Similar String Groups](https://leetcode.com/problems/similar-string-groups/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `String` `Depth-First Search` `Breadth-First Search` `Union Find`

### Code


```cpp
// Template for disjoint set union (DSU) data structure with custom node type and base index
template <typename T = int, int Base = 0> 
struct DSU {
    // Store parent and group size for each node
    vector<T> parent, Gsize;

    // Constructor initializes parent and group size for all nodes
    DSU(int MaxNodes) {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++) {
            parent[i] = i;
            Gsize[i] = 1;
        }
    }

    // Find the leader of the group for the given node and perform path compression
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Check if two nodes are in the same group
    bool is_same_sets(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    // Merge the groups containing the given nodes
    void union_sets(int u, int v) {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v) return;
        if (Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v];
        parent[leader_v] = leader_u;
    }

    // Get the size of the group containing the given node
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

// Solution class for finding number of similar groups
class Solution {
public:
    // Function to check if two strings differ by at most 2 characters
    bool is_similar(const string& a, const string& b) {
        int diff = 0, n = a.size();

        // Iterate through each character of the two strings and count the number of differences
        for (int i = 0; i < n; i++)
            diff += (a[i] != b[i]);

        // Return true if the number of differences is less than or equal to 2
        return diff <= 2;
    }

    // Function to find the number of similar groups in a vector of strings
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        // Create a disjoint-set data structure with n elements
        DSU<int> dsu(n);

        // Iterate through each pair of strings in the vector and union their sets if they are similar
        for (int i = 1; i < n; i++)
            for (int j = i - 1; j >= 0; j--)
                if (is_similar(strs[i], strs[j]))
                    dsu.union_sets(i, j);

        int groups = 0;

        // Count the number of groups by counting the number of leaders in the disjoint-set data structure
        for (int i = 0; i < n; i++)
            groups += dsu.find_leader(i) == i;

        // Return the number of groups
        return groups;
    }

};
```

<hr>
<br><br>

## 29)  [Checking Existence of Edge Length Limited Paths](https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Union Find` `Graph` `Array` `Sorting`

### Code


```cpp
template <typename T = int, int Base = 1>
struct DSU {
    vector<T> parent, Gsize;

    // Constructor to initialize the parent and Gsize vectors.
    DSU(int MaxNodes) {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Find the leader of the set where 'node' belongs and compress the path while traversing.
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Check if 'u' and 'v' belong to the same set or not.
    bool is_same_sets(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    // Merge the sets containing 'u' and 'v'.
    void union_sets(int u, int v) {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v)
            return;
        if (Gsize[leader_u] < Gsize[leader_v])
            swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Get the size of the set where 'u' belongs.
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

// Define a template struct called LCA
// that takes an optional typename T (default to int)
template <typename T = int>
struct LCA {
    
    // Define an inner struct called Edge
    // that has a vertex v and a weight w
    struct Edge {
        T v, w;

        Edge(T V = 0, T W = 0) : v(V), w(W) {}

        bool operator < (const Edge &rhs) const {
            return w < rhs.w;
        }
    };

    // Initialize variables
    int N, LOG;
    vector < vector <T> > anc, cost;
    vector < vector <Edge> > adj;
    vector <int> dep, vis;

    // Constructor for LCA
    LCA(int n){
        // Set N to n + 10 and find the LOG of N
        N = n + 10, LOG = 0;
        while((1 << LOG) <= N) LOG++;
        // Initialize dep, vis, adj, anc, and cost vectors
        dep = vis = vector <int> (N);
        adj = vector < vector <Edge> > (N);
        anc = cost = vector < vector <T> > (N, vector <T> (LOG));
    }

    // Add edge to the graph
    void add_edge(int u, int v, T w){
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }

    // Build adjacency list from input
    void build_adj(int edges){
        for(int i = 0, u, v, w; i < edges && cin >> u >> v >> w; i++)
            add_edge(u, v, w);
    }

    // Operation to be performed on cost
    T operation(T a, T b){
        return max(a, b);
    }

    // Perform depth-first search on the graph
    void dfs(int u){
        vis[u] = true;
        for(auto& [v, w] : adj[u]){
            if(vis[v]) continue;
            dep[v] = dep[u] + 1, anc[v][0] = u, cost[v][0] = w;
            for(int bit = 1; bit < LOG; bit++){
                anc[v][bit] = anc[anc[v][bit - 1]][bit - 1];
                cost[v][bit] = operation(cost[v][bit - 1], cost[anc[v][bit - 1]][bit - 1]);
            }
            dfs(v);
        }
    }

    // Find the kth ancestor of a node
    int kth_ancestor(int u, int k){
        if(dep[u] < k) 
            return -1;
        for(int bit = LOG - 1; bit >= 0; bit--)
            if(k & (1 << bit))
                u = anc[u][bit];
        return u;
    }

    // Find the lowest common ancestor of two nodes
    int get_lca(int u, int v){
        if(dep[u] < dep[v])
            swap(u, v);
        u = kth_ancestor(u, dep[u] - dep[v]);
        if(u == v)
            return u;
        for(int bit = LOG - 1; bit >= 0; bit--)
            if(anc[u][bit] != anc[v][bit])
                u = anc[u][bit], v = anc[v][bit];
        return anc[u][0];
    }

    // Get the cost from a node to its ancestor at a certain distance    
    T get_cost(int u, int dist){
        if(dep[u] < dist) return -1;
        T ans = 0;
        for(int bit = 0; bit < LOG; bit++)
            if(dist & (1 << bit))
                ans = operation(ans, cost[u][bit]), u = anc[u][bit];
        return ans;
    }
        
    // Function to answer LCA queries between two nodes u and v
    T query(int u, int v){
        int lca = get_lca(u, v);
        return operation(get_cost(u, dep[u] - dep[lca]), get_cost(v, dep[v] - dep[lca]));
    }

    // Function to build the LCA tree
    void build(int n){
        for(int i = 1; i <= n; i++)
            if(!vis[i])
                dfs(i);
    }

};

class Solution {
public:
    // Define a function that takes in an integer n, a vector of vectors of integers edgeList, and a vector of vectors of integers queries and returns a vector of bools.
    vector < bool > distanceLimitedPathsExist(int n, vector < vector < int > >& edgeList, vector < vector < int > >& queries) {
        // Sort the edges by their weights.
        sort(edgeList.begin(), edgeList.end(), [&](vector < int >& a, vector < int >& b){
            return a[2] < b[2];
        });
        
        // Create an instance of a disjoint set union data structure (DSU) and a lowest common ancestor (LCA) data structure.
        DSU < int > dsu(n);
        LCA < int > lca(n);
        
        // Iterate through the sorted edges and add each edge to the LCA data structure if the nodes it connects are not in the same set in the DSU.
        // make mst for the graph
        for(auto& edge : edgeList){
            int u = ++edge[0], v = ++edge[1], w = edge[2];
            if(dsu.is_same_sets(u, v)) continue;
            dsu.union_sets(u, v);
            lca.add_edge(u, v, w);
        }
        
        // Build the LCA data structure.
        lca.build(n);
        
        // Create a vector to store the answers to the queries.
        vector < bool > ans;
        
        // Iterate through the queries and check if the nodes it connects are in the same set in the DSU.
        // If they are, check if the minimum edge weight on the path between them is less than the query limit.
        // If they are not in the same set, it is impossible to have a path between them.
        // Add the answer to the answer vector.
        for(auto& q : queries){
            int u = ++q[0], v = ++q[1], limit = q[2];
            if(dsu.is_same_sets(u, v))
                ans.push_back(lca.query(u, v) < limit);
            else
                ans.push_back(false);
        }
        
        // Return the answer vector.
        return ans;
    }
};
```
    
<hr>
<br><br>

## 30)  [Remove Max Number of Edges to Keep Graph Fully Traversable](https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Union Find` `Graph`

### Code


```cpp
// Define a generic disjoint-set union data structure with an optional base node
// parameter for 1-based indexing, and a template parameter for data type T.
template <typename T = int, int Base = 1>
struct DSU {
    // The parent vector stores the parent of each node, and the Gsize vector
    // stores the size of each disjoint set.
    vector<T> parent, Gsize;

    // Constructor initializes the parent and Gsize vectors for all nodes.
    DSU(int MaxNodes) {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    // Recursive function to find the leader of the disjoint set that the node
    // belongs to, and updates the parent of all visited nodes to the leader.
    T find_leader(int node) {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    // Returns true if the two nodes belong to the same disjoint set.
    bool is_same_sets(int u, int v) {
        return find_leader(u) == find_leader(v);
    }

    // Merges the disjoint sets containing the two nodes u and v.
    void union_sets(int u, int v) {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v) return;
        if (Gsize[leader_u] < Gsize[leader_v]) swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    // Returns the size of the disjoint set that the node belongs to.
    int get_size(int u) {
        return Gsize[find_leader(u)];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Variable to store the number of edges removed.
        int removed_edges = 0;
        // Create two disjoint-set union objects, one for Alice and one for Bob.
        DSU<int> alice(n), bob(n);
        // Sort edges in decreasing order of type so that type 3 edges are
        // processed last.
        sort(edges.rbegin(), edges.rend());
        // Loop through each edge in the sorted list.
        for (auto& edge : edges) {
            int t = edge[0], u = edge[1], v = edge[2];
            // Process the edge based on its type.
            if (t == 1) {
                if (alice.is_same_sets(u, v)) removed_edges++;
                else alice.union_sets(u, v);
            } else if (t == 2) {
                if (bob.is_same_sets(u, v)) removed_edges++;
                else bob.union_sets(u, v);
            } else {
                if (alice.is_same_sets(u, v) && bob.is_same_sets(u, v)) removed_edges++;
                else alice.union_sets(u, v), bob.union_sets(u, v);
            }
        }
        // Check if all nodes belong to the same disjoint set for both Alice and
        // Bob. If not, return -1 as it is impossible to remove enough edges to
        // create a spanning tree for both players.
        if (alice.get_size(1) != n || bob.get_size(1) != n)
            return -1;
        // Return the number of edges removed.
        return removed_edges;
    }
};
```
    
