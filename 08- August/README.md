# LeetCode Daily Challenge Problems for August

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
1. **[Combinations](#01--combinations)**
1. **[Permutations](#02--permutations)**
1. **[Letter Combinations of a Phone Number](#03--letter-combinations-of-a-phone-number)**
1. **[Word Break](#04--word-break)**
1. **[Unique Binary Search Trees II](#05--unique-binary-search-trees-ii)**
1. **[Number of Music Playlists](#06--number-of-music-playlists)**
1. **[Search a 2D Matrix](#07--search-a-2d-matrix)**
1. **[Search in Rotated Sorted Array](#08--search-in-rotated-sorted-array)**
1. **[Minimize the Maximum Difference of Pairs](#09--minimize-the-maximum-difference-of-pairs)**
1. **[Search in Rotated Sorted Array II](#10--search-in-rotated-sorted-array-ii)**
1. **[Coin Change II](#11--coin-change-ii)**
1. **[Unique Paths II](#12--unique-paths-ii)**
1. **[Check if There is a Valid Partition For The Array](#13--check-if-there-is-a-valid-partition-for-the-array)**
1. **[Kth Largest Element in an Array](#14--kth-largest-element-in-an-array)**

<hr>
<br><br>

## 01)  [Combinations](https://leetcode.com/problems/combinations/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Backtracking`

### Code


```cpp
class Solution {
public:
    
    // A 2D vector to store all combinations
    vector<vector<int>> comb;

    // A vector to keep track of the current combination being built
    vector<int> curr;
    
    // Recursive function to build combinations
    void build(int n, int k){
        // Base cases: If either n or k becomes negative, return
        if(n < 0 || k < 0) return;

        // Base case: If both n and k are 0, the current combination is complete, add it to the result and return
        if(n == 0 && k == 0) return comb.push_back(curr), void();

        // Exclude the current element and continue building combinations
        build(n - 1, k);
        
        // Include the current element and continue building combinations with reduced n and k
        curr.push_back(n);
        build(n - 1, k - 1);
        
        // Remove the last element to backtrack and try other combinations
        curr.pop_back();
    }
    
    // Function to generate all combinations of size k from numbers 1 to n
    vector<vector<int>> combine(int n, int k) {
        // Start the recursive building process
        build(n, k);
        
        // Return the final combinations
        return comb;
    }
};
```
    

<hr>
<br><br>

## 02)  [Permutations](https://leetcode.com/problems/permutations/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Backtracking`

### Code


```cpp
class Solution {
public:
    // The permute function takes a vector of integers called "nums" as input and returns a vector of vectors of integers representing all possible permutations.
    vector<vector<int>> permute(vector<int>& nums) {
        // Create a vector of vectors of integers called "permutations" to store the generated permutations.
        vector<vector<int>> permutations;

        // Sort the input vector "nums" in ascending order to ensure that permutations are generated in lexicographic order.
        sort(nums.begin(), nums.end());

        // Generate permutations using the next_permutation function and add them to the "permutations" vector.
        do {
            permutations.emplace_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        // Return the vector containing all generated permutations.
        return permutations;
    }
};
```
    
<hr>
<br><br>

## 03)  [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `String` `Backtracking`

### Code


```cpp
class Solution {
public:
    // Vector to store the mapping of digits to corresponding letters
    vector<string> mapping, ans;

    // Recursive function to build all possible combinations of letters
    // for a given set of digits
    void build(const string& digits, int idx, string comb) {
        // If the combination's length matches the digits' length, add it to the answer vector
        if (comb.size() == digits.size())
            ans.push_back(comb);

        // If we have processed all the digits, return from the function
        if (idx == digits.size())
            return;

        // For each letter corresponding to the current digit, recurse and add the letter to the combination
        for (char& c : mapping[digits[idx] - '2'])
            build(digits, idx + 1, comb + c);
    }

    // Function to get all possible letter combinations for a given set of digits
    vector<string> letterCombinations(const string& digits) {
        // Define the mapping of digits to letters
        mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // If the input digits are not empty, start building the combinations
        if (!digits.empty())
            build(digits, 0, "");

        // Return the vector containing all possible letter combinations
        return ans;
    }
};
```
    
<hr>
<br><br>

## 04)  [Word Break](https://leetcode.com/problems/word-break/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `String` `Dynamic Programming` `Trie` `Memoization`

### Code


```cpp
class Solution {
public:
    unordered_map < string, bool > mp;
    
    // The wordBreak function takes a string 's' and a vector of strings 'wordDict'.
    // It returns true if the string 's' can be segmented into words from 'wordDict', false otherwise.
    bool wordBreak(string s, vector < string >& wordDict) {
        // Base case: an empty string can always be segmented (as no word is needed).
        if (s.empty()) return true;
    
        // If the result for the current 's' is already computed, return it to avoid recomputation.
        if (mp.find(s) != mp.end()) return mp[s];
        
        // Get the size of the word dictionary to use it in the loop.
        int n = wordDict.size();
        
        // Loop through the words in the dictionary to find a match with the beginning of 's'.
        for (int i = 0; i < n; i++) {
            // Check if the current word from the dictionary matches the start of 's'.
            if (wordDict[i] == s.substr(0, wordDict[i].length())) {
                // If there is a match, recursively check the rest of the string after removing the matched word.
                bool check = wordBreak(s.substr(wordDict[i].length()), wordDict);
                
                // If the rest of the string can be segmented, update the result for the current 's' to true.
                if (check)
                    return mp[s] = true;
            }
        }
        
        // If no match is found, update the result for the current 's' to false.
        return mp[s] = false;
    }
};
```
    
<hr>
<br><br>

## 05)  [Unique Binary Search Trees II](https://leetcode.com/problems/unique-binary-search-trees-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Dynamic Programming` `Backtracking` `Tree` `Binary Search Tree` `Binary Tree`

### Code


```cpp
class Solution {
public:
    vector < TreeNode* > generateTrees(int E, int S = 1) {
        // If the end of the range is smaller than the start, return a vector with a single nullptr
        if (E < S) return {nullptr};

        // Create a vector to store the generated tree nodes
        vector < TreeNode* > nodes;

        // Iterate through each value from S to E
        for (int i = S; i <= E; ++i) {
            // Generate all possible left subtrees from the range [S, i-1]
            vector < TreeNode* > left = generateTrees(i - 1, S);

            // Generate all possible right subtrees from the range [i+1, E]
            vector < TreeNode* > right = generateTrees(E, i + 1);

            // Combine each left subtree with each right subtree and create a new tree node with value 'i'
            // Then, add the newly created tree node to the 'nodes' vector
            for (auto tl : left)
                for (auto tr : right)
                    nodes.push_back(new TreeNode(i, tl, tr));
        }

        // Return the vector containing all possible binary search trees
        return nodes;
    }
};
```
    
<hr>
<br><br>

## 06)  [Number of Music Playlists](https://leetcode.com/problems/number-of-music-playlists/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Math` `Dynamic Programming` `Combinatorics`

### Code


```cpp
class Solution {
public:
    // Define a constant variable MOD to be used in modulo operations
    const int MOD = 1e9 + 7;

    // Helper function to perform multiplication with modulo
    int mul(int res, int to_mul) {
        // Return the result of multiplying res and to_mul, and taking the modulo of MOD
        return res = (1ll * (res % MOD) * (to_mul % MOD)) % MOD;
    }

    int solve(int n, int goal, int k, vector<vector<int>>& dp) {
        // Base case: If both n and goal are 0, return 1 as one valid playlist is found
        if (n == 0 && goal == 0) return 1;

        // Base case: If either n or goal is 0, return 0 as no valid playlist can be formed
        if (n == 0 || goal == 0) return 0;
        
        // reference for dp[n][goal]
        int& ret = dp[n][goal];

        // If the result for the current state (n, goal) is already computed, return it from the dp table
        if (~ret) return ret;

        // Calculate the number of ways to pick a song and place it at the end of the playlist
        int pick = mul(solve(n - 1, goal - 1, k, dp), n);

        // Calculate the number of ways to place a new song (not already in the playlist) at the end
        // This can be done by choosing from the songs not played in the last k steps
        int notpick = mul(solve(n, goal - 1, k, dp), max(n - k, 0));

        // Store the result in the dp table and return it after taking the modulo of MOD
        return ret = (pick + notpick) % MOD;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        // Create a dp table to store the results of subproblems
        vector < vector < int > > dp(n + 1, vector < int > (goal + 1, -1));

        // Call the solve function to compute the result and return it
        return solve(n, goal, k, dp);
    }
};
```
    
<hr>
<br><br>

## 07)  [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Matrix`

### Code


```cpp
class Solution {
public:
    int BS_2D(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, best = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            // If target is greater or equal, move search to the right half of the column
            // Otherwise, move to the left half and update the potential "best" row index
            (matrix[m][0] <= target ? l = m + 1, best = m : r = m - 1);
        }
        return best;
    }
    
    bool BS_1D(vector< int >& matrix, int target) {
        int l = 0, r = matrix.size() - 1, best = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            // If target is greater or equal, move search to the right half of the vector
            // Otherwise, move to the left half and update the potential "best" index
            (matrix[m] <= target ? l = m + 1, best = m : r = m - 1);
        }
        // Check if target was found at the best index
        return (best == -1 || matrix[best] != target ? false : true);
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Find the potential row index using binary search along the first column
        int row_idx = BS_2D(matrix, target);
        // If no suitable row index is found, target cannot be in the matrix
        if(row_idx == -1) return false;
        // Search for the target in the identified row using binary search in 1D vector
        return BS_1D(matrix[row_idx], target);
    }
};
```
    
<hr>
<br><br>

## 08)  [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize two pointers 'l' and 'r' to the start and end of the vector.
        int l = 0, r = nums.size() - 1;

        // Perform a binary search by narrowing down the search range until 'l' is less than or equal to 'r'.
        while(l <= r){
            // Check if the element at index 'l' is equal to the target. If so, return 'l'.
            if(nums[l] == target) return l;

            // Check if the element at index 'r' is equal to the target. If so, return 'r'.
            if(nums[r] == target) return r;

            // If neither 'l' nor 'r' elements match the target, move 'l' one step right and 'r' one step left.
            r--, l++;
        }

        // If the target element is not found in the vector, return -1.
        return -1;
    }
};
```
    
<hr>
<br><br>

## 09)  [Minimize the Maximum Difference of Pairs](https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Greedy`

### Code


```cpp
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        // Get the size of the input vector
        int n = nums.size();
        
        // Sort the input vector in ascending order
        sort(nums.begin(), nums.end());
        
        // Define a lambda function (is_good) that takes an integer (m) and returns a boolean
        auto is_good = [&](int m){
            int cnt_pairs = 0; // Initialize a counter for pairs
            
            // Iterate through the input vector
            for(int i = 0; i < n - 1; i++){
                // Check if the difference between the current element and the next element is less than or equal to m
                if(nums[i + 1] - nums[i] <= m)
                    cnt_pairs++, i++; // Increment the counter and the index to skip the next element
            }
            
            // Return true if the count of pairs is greater than or equal to p, otherwise return false
            return cnt_pairs >= p;
        };
        
        // Initialize variables l, r, and ans
        int l = 0, r = 1, ans = -1;
        
        while(!is_good(r)) r *= 2;

        // Perform a binary search to find the minimum value of m that satisfies the is_good condition
        while(l <= r){
            int m = l + (r - l) / 2;
            // Update l and r based on the is_good condition
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        
        // Return the final answer
        return ans;
    }
};
```

<hr>
<br><br>

## 10)  [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    // Binary search function to find target in rotated sorted array
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; // Define left and right pointers
        while(l <= r){ // Continue loop as long as left pointer is less than or equal to right pointer
            int m = l + (r - l) / 2; // Calculate middle index
            if(nums[m] == target) return true; // Target found at middle index
            if(nums[l] == nums[m]) l++; // Handle duplicate values at the left end
            else if(nums[l] <= nums[m]) // If left part is sorted
                (nums[l] <= target && target <= nums[m] ? r = m - 1 : l = m + 1); // Adjust pointers based on target location in sorted portion
            else // If right part is sorted
                (nums[m] <= target && target <= nums[r] ? l = m + 1 : r = m - 1); // Adjust pointers based on target location in sorted portion
        }
        return false; // Target not found in the array
    }
};
```
 
<hr>
<br><br>

## 11)  [Coin Change II](https://leetcode.com/problems/coin-change-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // Create a vector 'dp' to store the count of combinations for each amount from 0 to 'amount'
        vector < int > dp(amount + 1);
        
        // There is only one way to make 0 amount, which is by not using any coins
        dp[0] = 1;
        
        // Iterate through each coin in the 'coins' vector
        for(auto& coin : coins)
            // Iterate through each possible amount starting from 1 up to 'amount'
            for(int money = 1; money <= amount; money++)
                // Check if the current coin value is less than or equal to the current amount
                if(money >= coin)
                    // Increment the count of combinations for the current amount by the count of combinations for (current amount - coin value)
                    dp[money] += dp[money - coin];
        
        // Return the count of combinations to make the given 'amount'
        return dp[amount];
    }
};
```
    

<hr>
<br><br>

## 12)  [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Matrix`

### Code


```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Get the number of rows and columns in the obstacleGrid
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        
        // Initialize a 2D vector dp with dimensions (n+5) x (m+5)
        vector<vector<int>> dp(n + 5, vector<int>(m + 5));
        
        // Set the starting point in dp based on the condition in obstacleGrid
        dp[1][1] = (obstacleGrid[0][0] != 1);
        
        // Iterate through each cell in the obstacleGrid
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // Check if the current cell is not an obstacle
                if(obstacleGrid[i - 1][j - 1] != 1) {
                    // Calculate the number of unique paths to the current cell
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        
        // Return the number of unique paths to the bottom-right cell of the obstacleGrid
        return dp[n][m];
    }
};
```
    
<hr>
<br><br>

## 13)  [Check if There is a Valid Partition For The Array](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();

        // Dynamic programming array to store valid partition information
        vector < bool > dp(4);
        dp[0] = true; // Base case: an empty partition is always valid
        // Checking if first two elements are equal
        dp[2] = (dp[2] | (dp[0] & (nums[1] == nums[0])));
        
        // Loop to iterate through the array and populate dp array
        for(int i = 3, j = 2; i <= n; i++, j++) {
            // re initial the current state
            dp[i % 4] = false;

            // If the last two elements are equal, extend the valid partition
            if(nums[j] == nums[j - 1])
                dp[i % 4] = (dp[i % 4] | dp[(i - 2) % 4]);

            // If the last three elements are equal, extend the valid partition
            if(nums[j] == nums[j - 1] && nums[j] == nums[j - 2])
                dp[i % 4] = (dp[i % 4] | dp[(i - 3) % 4]);

            // If the last three elements form an increasing sequence, extend the valid partition
            if(nums[j] == nums[j - 1] + 1 && nums[j] == nums[j - 2] + 2)
                dp[i % 4] = (dp[i % 4] | dp[(i - 3) % 4]);

        }
        
        // Return whether the entire array can be partitioned into valid subsequences
        return dp[n % 4];
    }
};
```
    
<hr>
<br><br>

## 14)  [Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Quickselect`

### Code


```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sort the vector in non-ascending order using the reverse iterators
        sort(nums.rbegin(), nums.rend());
        // Return the kth largest element by accessing the (k-1)th index
        return nums[--k];
    }
};
```
    