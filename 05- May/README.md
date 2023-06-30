# LeetCode Daily Challenge Problems for May

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
1. **[Average Salary Excluding the Minimum and Maximum Salary](#01--average-salary-excluding-the-minimum-and-maximum-salary)**
1. **[Sign of the Product of an Array](#02--sign-of-the-product-of-an-array)**
1. **[Find the Difference of Two Arrays](#03--find-the-difference-of-two-arrays)**
1. **[Dota2 Senate](#04--dota2-senate)**
1. **[Maximum Number of Vowels in a Substring of Given Length](#05--maximum-number-of-vowels-in-a-substring-of-given-length)**
1. **[Number of Subsequences That Satisfy the Given Sum Condition](#06--number-of-subsequences-that-satisfy-the-given-sum-condition)**
1. **[Find the Longest Valid Obstacle Course at Each Position](#07--find-the-longest-valid-obstacle-course-at-each-position)**
1. **[Matrix Diagonal Sum](#08--matrix-diagonal-sum)**
1. **[Spiral Matrix](#09--spiral-matrix)**
1. **[Spiral Matrix II](#10--spiral-matrix-ii)**
1. **[Uncrossed Lines](#11--uncrossed-lines)**
1. **[Solving Questions With Brainpower](#12--solving-questions-with-brainpower)**
1. **[Count Ways To Build Good Strings](#13--count-ways-to-build-good-strings)**
1. **[Maximize Score After N Operations](#14--maximize-score-after-n-operations)**
1. **[Swapping Nodes in a Linked List](#15--swapping-nodes-in-a-linked-list)**
1. **[Swap Nodes in Pairs](#16--swap-nodes-in-pairs)**
1. **[Maximum Twin Sum of a Linked List](#17--maximum-twin-sum-of-a-linked-list)**
1. **[Minimum Number of Vertices to Reach All Nodes](#18--minimum-number-of-vertices-to-reach-all-nodes)**
1. **[Is Graph Bipartite?](#19--is-graph-bipartite)**
1. **[Evaluate Division](#20--evaluate-division)**
1. **[Shortest Bridge](#21--shortest-bridge)**
1. **[Kth Largest Element in a Stream](#23--kth-largest-element-in-a-stream)**
1. **[Maximum Subsequence Score](#24--maximum-subsequence-score)**
1. **[New 21 Game](#25--new-21-game)**
1. **[Stone Game II](#26--stone-game-ii)**
1. **[Stone Game III](#27--stone-game-iii)**
1. **[Minimum Cost to Cut a Stick](#28--minimum-cost-to-cut-a-stick)**
1. **[Design Parking System](#29--design-parking-system)**
1. **[Design HashSet](#30--design-hashset)**
1. **[Design Underground System](#31--design-underground-system)**

<hr>
<br><br>

## 01)  [Average Salary Excluding the Minimum and Maximum Salary](https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Sorting`

### Code


```cpp
class Solution {
public:
    // This function calculates the average of a vector of integers by sorting it and removing the minimum and maximum values.
    double average(vector<int>& salary) {

        // Calculate the sum of all the elements in the vector except for the minimum and maximum values.
        double sum = 0, n = salary.size() - 2;
        sort(salary.begin(), salary.end());
        for(auto& i : salary)
            sum += i;
        sum -= salary.front() + salary.back();

        // Return the average by dividing the sum by the number of elements in the vector minus 2.
        return sum / n;
    }

};
```
    

<hr>
<br><br>

## 02)  [Sign of the Product of an Array](https://leetcode.com/problems/sign-of-the-product-of-an-array/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Math`

### Code


```cpp
class Solution {
public:
    int arraySign(vector<int>& nums) {
        // Initialize variables to count the number of zeros and negatives in the input vector.
        int neg = 0, zero = 0;
        
        // Loop through the input vector and increment zero and/or neg depending on the value of each element.
        for(auto& i : nums) {
            if(i == 0)
                zero++;
            else if(i < 0)
                neg++;
        }
        
        // If there are any zeros in the input vector, return 0. Otherwise, determine the sign of the product of all elements.
        return (zero > 0 ? 0 : (neg & 1 ? -1 : 1));
    }

};
```

<hr>
<br><br>

## 03)  [Find the Difference of Two Arrays](https://leetcode.com/problems/find-the-difference-of-two-arrays/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Array`

### Code


```cpp
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // Create two unordered sets of integers to store the unique values of nums1 and nums2, respectively.
        unordered_set<int> nums1_set, nums2_set;
        
        // Insert each element of nums1 into nums1_set.
        for(auto& x : nums1)
            nums1_set.insert(x);
        
        // Insert each element of nums2 into nums2_set.
        for(auto& x : nums2)
            nums2_set.insert(x);
        
        // Create a 2D vector of integers to store the differences between nums1 and nums2.
        vector<vector<int>> ans(2);
        
        // Iterate through each element in nums1.
        for(auto& x : nums1) {
            // If the element is not in nums2_set, add it to the first row of ans and insert it into nums2_set.
            if(!nums2_set.count(x)) {
                ans[0].push_back(x);
                nums2_set.insert(x);
            }
        }
        
        // Iterate through each element in nums2.
        for(auto& x : nums2) {
            // If the element is not in nums1_set, add it to the second row of ans and insert it into nums1_set.
            if(!nums1_set.count(x)) {
                ans[1].push_back(x);
                nums1_set.insert(x);
            }
        }
        
        // Return the resulting 2D vector.
        return ans;
    }

};
```
    

<hr>
<br><br>

## 04)  [Dota2 Senate](https://leetcode.com/problems/dota2-senate/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Greedy` `Queue`

### Code


```cpp
class Solution {
public:
    string predictPartyVictory(string& senate) {
        int score = 0;

        // Loop through the senate string
        for (int i = 0; i < senate.size(); ++i) {            
            // If the current character is 'R'
            if (senate[i] == 'R') {
                // If the score is negative
                // add a 'D' to the end of the senate string
                if (score < 0) 
                    senate.push_back('D');
                ++score;
            } 
            
            // If the current character is 'D'
            else {
                // If the score is positive
                // add a 'R' to the end of the senate string
                if (score > 0) 
                    senate.push_back('R');
                --score;
            }
        }

        // Return the predicted winning party
        return score > 0 ? "Radiant" : "Dire";
    }

};
```
    

<hr>
<br><br>

## 05)  [Maximum Number of Vowels in a Substring of Given Length](https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Sliding Window`

### Code


```cpp
class Solution {
public:

    // define a string that contains vowels
    string vowels = "aeoiu";

    // function to check if a character is a vowel
    bool is_vowel(const char& c){
        return count(vowels.begin(), vowels.end(), c);
    }

    // function to find the maximum number of vowels in a substring of length k in a given string
    int maxVowels(const string& s, int k){
        // initialize variables to keep track of the current number of vowels and the maximum number of vowels seen so far
        int cnt_vowels = 0, max_vowels = 0;
        
        // define lambda functions to add and remove characters from the current substring and update the vowel count
        auto add = [&](const char& c){
            cnt_vowels += is_vowel(c);
        };
        auto remove = [&](const char& c){
            cnt_vowels -= is_vowel(c);
        };
        
        // iterate over the string
        for(int i = 0; i < s.size(); i++){
            // add the current character to the substring and update the vowel count
            add(s[i]);
            
            // if the length of the substring is greater than k, remove the oldest character from the substring and update the vowel count
            if(i >= k)
                remove(s[i - k]);
            
            // update the maximum number of vowels seen so far
            max_vowels = max(max_vowels, cnt_vowels);
        }
        
        // return the maximum number of vowels seen in any substring of length k
        return max_vowels;
    }
};
```
    
<hr>
<br><br>

## 06)  [Number of Subsequences That Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Two Pointers` `Binary Search` `Sorting`

### Code


```cpp
class Solution {
public:

    // Define a type long long as ll
    typedef long long ll;

    // Define a constant integer MOD as 1000000007
    static constexpr int MOD = 1e9 + 7;

    // A function to calculate b to the power of e in the binary form
    // and returns the result mod MOD.
    ll binPow(ll b, ll e){
        // if e is negative, return 0
        if(e < 0) return 0;

        // Initialize power to 1
        ll power = 1;

        // While e is positive
        while(e > 0){
            // If the least significant bit of e is 1, multiply power by b and take the result mod MOD
            if(e & 1) power = (power * b) % MOD;
            
            // Square b and take the result mod MOD
            b = (b * b) % MOD;
            
            // Shift e one bit to the right -> e /= 2;
            e >>= 1;
        }

        // Return the result
        return power;
    }

    // A function to count the number of non-empty subsequences of nums that sum to target
    int numSubseq(vector<int>& nums, int target) {
        // Get the size of nums
        int n = nums.size();
        
        // Sort nums in non-descending order
        sort(nums.begin(), nums.end());
        
        // Initialize ans to 0
        ll num_of_seq = 0;
        
        // For each element nums[i] in nums
        for(int i = 0; i < n; i++){
            // Find the index of the first element greater than target - nums[i]
            int idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            
            // Add 2^(idx-i-1) to ans and take the result mod MOD -> number of valid subsequences
            num_of_seq = (num_of_seq + binPow(2, idx - i - 1)) % MOD;
        }
        
        // Return num_of_seq
        return num_of_seq;
    }
};
```
    
<hr>
<br><br>

## 07)  [Find the Longest Valid Obstacle Course at Each Position](https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Binary Indexed Tree`

### Code


```cpp
class Solution {
public:
    vector < int > longestObstacleCourseAtEachPosition(const vector < int >& obstacles) {

        // Get the size of the vector of obstacles
        int n = obstacles.size();

        // Create two vectors: LIS (initialized to 1e9) and LOC (initialized to 0)
        vector < int > LIS(n, 1e9), LOC(n);

        // Loop through the obstacles vector
        for(int i = 0; i < n; i++){

            // Get the upper bound of the current obstacle in the LIS vector
            auto up = upper_bound(LIS.begin(), LIS.end(), obstacles[i]);

            // Set the value of LOC at the current position to (the index of the upper bound + 1)
            LOC[i] = (up - LIS.begin() + 1);

            // Update the LIS vector with the current obstacle value
            *up = obstacles[i];
        }

        // Return the LOC vector
        return LOC;
    }
};
```
    
<hr>
<br><br>

## 08)  [Matrix Diagonal Sum](https://leetcode.com/problems/matrix-diagonal-sum/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Matrix`

### Code


```cpp
class Solution {
public:
    // Function to calculate the sum of diagonals of a given matrix
    int diagonalSum(const vector<vector<int>>& mat) {
        // Get the size of the matrix and initialize the sum variable to zero
        int n = mat.size(), sum = 0;
        
        // Loop through each row of the matrix
        for(int i = 0; i < n; i++) {
            // Add the element at the ith row and ith column to the sum
            sum += mat[i][i];
            // Add the element at the ith row and (n-i-1)th column to the sum
            sum += mat[i][n - i - 1];
        }
        
        // If the size of the matrix is odd, subtract the middle element from the sum
        return sum - (n & 1 ? mat[n / 2][n / 2] : 0);
    }
};
```
    
<hr>
<br><br>

## 09)  [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Matrix` `Simulation`

### Code


```cpp
class Solution {
public:
        
    // Declare a vector to store the elements of the matrix in spiral order.
    vector<int> spiral;

    // Recursive function to traverse the matrix in spiral order and store the elements in the spiral vector.
    void getSprial(vector<vector<int>>& grid, int i, int j, int m, int n) {

        // Base case: if i >= m or j >= n, return from the function.
        if (i >= m or j >= n)
            return;

        // Traverse the first row from j to n-1 and push the elements into the spiral vector.
        for (int p = j; p < n; p++)
            spiral.push_back(grid[i][p]);

        // Traverse the last column from i+1 to m-1 and push the elements into the spiral vector.
        for (int p = i + 1; p < m; p++)
            spiral.push_back(grid[p][n - 1]);

        // Traverse the last row from n-2 to j and push the elements into the spiral vector.
        if ((m - 1) != i)
            for (int p = n - 2; p >= j; p--)
                spiral.push_back(grid[m - 1][p]);

        // Traverse the first column from m-2 to i+1 and push the elements into the spiral vector.
        if ((n - 1) != j)
            for (int p = m - 2; p > i; p--)
                spiral.push_back(grid[p][j]);

        // Recursive call to traverse the next inner matrix.
        getSprial(grid, i + 1, j + 1, m - 1, n - 1);
    }

    // Function to return the elements of the matrix in spiral order.
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        // Call the recursive function getSprial with the initial parameters.
        getSprial(matrix, 0, 0, matrix.size(), matrix[0].size());

        // Return the spiral vector containing the elements of the matrix in spiral order.
        return spiral;
    }


};
```
    
<hr>
<br><br>

## 10)  [Spiral Matrix II](https://leetcode.com/problems/spiral-matrix-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Matrix` `Simulation`

### Code


```cpp
class Solution {
public:

    // Check if (x, y) is inside the grid with size n
    bool onGrid(int x, int y, int n) {
        return (x >= 0 && x < n && y >= 0 && y < n);
    }

    // Generate a matrix with size n x n in a spiral pattern
    vector<vector<int>> generateMatrix(int n) {
        // Define the directions to move in the spiral pattern
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        
        // Initialize the matrix with all zeros
        vector<vector<int>> ret(n, vector<int>(n));
        
        // Set the starting position to (0, 0) and initialize the counter to 1
        int dir = 0, cnt = 0, x = 0, y = 0;
        ret[x][y] = ++cnt;
        
        // Keep moving in the spiral pattern until all elements are filled
        while (cnt < n * n) {
            // Compute the next position to move to
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            
            // If the next position is not inside the grid, change direction and continue
            if (false == onGrid(xx, yy, n)) {
                dir = (dir + 1) % 4;
                continue;
            }
            
            // If the next position is already filled, change direction and continue
            if (ret[xx][yy] != 0) {
                dir = (dir + 1) % 4;
                continue;
            }
            
            // Move to the next position and fill it with the next counter value
            x = xx, y = yy;
            ret[x][y] = ++cnt;
        }
        
        // Return the generated matrix
        return ret;
    }

};
```
    
<hr>
<br><br>

## 11)  [Uncrossed Lines](https://leetcode.com/problems/uncrossed-lines/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // A function to find the maximum number of uncrossed lines between two vectors
    int maxUncrossedLines(vector<int>& a, vector<int>& b) {

        // Get the size of the two vectors
        int n = a.size(), m = b.size();

        // Create a 2D vector with 2 rows and m+1 columns
        // to store the maximum number of uncrossed lines
        vector < vector < int > > dp(2, vector < int > (m + 1));

        // Loop through the elements in the vectors, starting from the end
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {

                // Get the reference to the current element in the 2D vector
                int& ret = (dp[i & 1][j] = 0);

                // Calculate the maximum number of uncrossed lines
                ret = max(dp[(i + 1) & 1][j], dp[i & 1][j + 1]);

                // If the current elements in the vectors are the same, add 1 to the maximum number of uncrossed lines
                if(a[i] == b[j])
                    ret = max(ret, dp[(i + 1) & 1][j + 1] + 1);
            }
        }

        // Return the maximum number of uncrossed lines
        return dp[0][0];
    }
};
```
    
<hr>
<br><br>

## 12)  [Solving Questions With Brainpower](https://leetcode.com/problems/solving-questions-with-brainpower/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
// for this problem we will use dp to solve it
// we can see that we can take the question or leave it, so we will try to take it and leave it and take the maximum
// we will use dp[i] to be the maximum points we can take from the questions from i to n
// so dp[i] = max(dp[i+1], dp[i+b+1] + p) where p is the points of the question and b is the number of questions we will skip

// dp[i+1] is the maximum points we can take if we skip the current question (move to the next question)
// dp[i+b+1] + p is the maximum points we can take if we take the current question and skip the next b questions (move to the next b+1 question)
// the answer will be dp[0] which is the maximum points we can take from the first question to the last question

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = int(questions.size());
        vector<long long> dp(n + 5);

        for(int i = n - 1; ~i; --i) {
            int p = questions[i][0], b = questions[i][1];
            dp[i] = max(dp[i + 1], dp[min(i + b + 1, n)] + p);
        }

        return dp[0];
    }
};
```

<hr>
<br><br>

## 13)  [Count Ways To Build Good Strings](https://leetcode.com/problems/count-ways-to-build-good-strings/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // Set the value of the constant MOD to 1e9+7
    static constexpr int MOD = 1e9 + 7;

    // Function that adds a value to another and checks if the result is greater than or equal to MOD
    void add(int& ret, int to_add){
        ret += to_add;
        if(ret >= MOD)
            ret -= MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Initialize a vector called dp with size equal to high + 1
        vector < int > dp(high + 1);
        
        // Set the first element of dp to 1
        dp[0] = 1;
        
        // Initialize a variable called sum to 0
        int sum = 0;
        
        for(int i = 1; i <= high; i++){
            // If i is greater than or equal to zero, add the value of dp[i-zero] to dp[i]
            if(i >= zero)
                add(dp[i], dp[i - zero]);
            
            // If i is greater than or equal to one, add the value of dp[i-one] to dp[i]
            if(i >= one)
                add(dp[i], dp[i - one]);
            
            // If i is greater than or equal to low, add the value of dp[i] to sum
            if(i >= low)
                add(sum, dp[i]);
        }

        // Return the value of sum
        return sum;
    }
};
```
    
<hr>
<br><br>

## 14)  [Maximize Score After N Operations](https://leetcode.com/problems/maximize-score-after-n-operations/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Math` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Number Theory` `Bitmask`

### Code


```cpp
class Solution {
public:

    // declare variables
    int n, full_mask;
    // vectors to store numbers and dynamic programming results
    vector<int> nums, dp;

    // function to check if a bit is empty in a binary mask
    bool is_empty_bit(int bit, int mask){
        return !(mask & (1 << bit));
    }

    // recursive function to calculate the maximum score
    int max_score(int mask){
        // if all bits are filled, return 0
        if(mask == full_mask) return 0;
        // use memoization to avoid redundant computations
        int& ret = dp[mask];
        // calculate the current index based on the number of filled bits
        int idx = __builtin_popcount(mask) / 2 + 1;
        // if the result has already been calculated, return it
        if(~ret) return ret;
        ret = 0;
        // iterate over all pairs of numbers
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                // if both numbers are empty, calculate the score
                if(is_empty_bit(i, mask) && is_empty_bit(j, mask))
                    ret = max(ret, (idx * __gcd(nums[i], nums[j])) + max_score(mask | (1 << i) | (1 << j)));
        // return the maximum score
        return ret;
    }

    int maxScore(vector<int>& nums) {
        // set the number of elements
        n = nums.size();
        // set the vector of numbers
        this -> nums = nums;
        // set the full binary mask
        full_mask = (1 << n) - 1;
        // initialize the dynamic programming vector with -1
        dp = vector<int>(1 << n, -1);
        // return the maximum score starting with an empty mask
        return max_score(0);
    }
};
```
    
<hr>
<br><br>

## 15)  [Swapping Nodes in a Linked List](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Two Pointers`

### Code


```cpp
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // Initialize pointers to the head of the list
        ListNode* one = head;
        ListNode* two = head;
        ListNode* curr = head;

        // Calculate the size of the list
        int sz = 0;
        while (curr)
            sz++, curr = curr -> next;

        // Move 'one' pointer to the kth node from the beginning
        for (int i = 1; i < k; i++)
            one = one -> next;

        // Move 'two' pointer to the kth node from the end
        for (int i = 1; i < sz - k + 1; i++)
            two = two -> next;

        // Swap the values of the two nodes
        swap(one -> val, two -> val);

        // Return the updated head of the list
        return head;
    }

};
```
    
<hr>
<br><br>

## 16)  [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Recursion`

### Code


```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // If the linked list is empty or has only one node
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        // Store the next node in a variable
        ListNode* next = head -> next;

        // Recursively swap the pairs of nodes
        head -> next = swapPairs(next -> next);
        next -> next = head;

        // Return the new head of the swapped linked list
        return next;
    }
};
```
    
<hr>
<br><br>

## 17)  [Maximum Twin Sum of a Linked List](https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Two Pointers` `Stack`

### Code


```cpp
class Solution {
public:
    
    int pairSum(ListNode* head) {
        // Create a vector to store the values of the linked list nodes
        vector < int > nums;
        ListNode* curr = head;

        // Traverse the linked list and store the values in the vector
        while (curr != nullptr) {
            nums.push_back(curr -> val);
            curr = curr -> next;
        }

        // Initialize left and right pointers, and the maximum sum
        int l = 0, r = nums.size() - 1, mx_sum = INT_MIN;

        // Find the maximum sum of pairs
        while (l < r)
            mx_sum = max(mx_sum, nums[l++] + nums[r--]);

        // Return the maximum sum
        return mx_sum;
    }

};
```
    
<hr>
<br><br>

## 18)  [Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Graph`

### Code


```cpp
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // Create two arrays to store the count of outgoing and incoming edges for each vertex
        vector<int> from(n), to(n);

        // Count the number of outgoing and incoming edges for each vertex
        for (auto& vec : edges) {
            from[vec[0]]++;  // Increment the outgoing edge count for the source vertex
            to[vec[1]]++;    // Increment the incoming edge count for the destination vertex
        }

        // Create a vector to store the result
        vector < int > res;

        // Iterate over all vertices
        for (int i = 0; i < n; i++) {
            // Check if the vertex has outgoing edges but no incoming edges
            if (from[i] && !to[i])
                res.push_back(i);  // Add the vertex to the result
        }

        // Return the result vector
        return res;
    }

};
```
    
<hr>
<br><br>

## 19)  [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Union Find` `Graph`

### Code


```cpp
class Solution {
public:

    vector < int > colour;

    // Function to check if a graph is bipartite
    bool is_Bipartite(int u, vector < vector < int > >& adj) {
        // Iterate over the adjacent vertices of u
        for (auto v : adj[u]) {
            // If v has the same color as u, the graph is not bipartite
            if (colour[v] == colour[u])
                return false;
            // If v is uncolored, assign a different color to it
            else if (colour[v] == 0) {
                colour[v] = -colour[u];
                // Recursively check if the subgraph starting from v is bipartite
                if (!is_Bipartite(v, adj))
                    return false;
            }
        }
        // All adjacent vertices have been processed and no conflict was found
        return true;
    }

    bool isBipartite(vector < vector < int > >& graph) {
        int n = graph.size();
        colour = vector < int > (n);
        
        bool isBip = true;
        // Process each vertex in the graph
        for (int u = 0; u < n; u++) {
            // If the vertex is uncolored, assign color 1 to it
            if (!colour[u]) {
                colour[u] = 1;
                // Check if the subgraph starting from u is bipartite
                isBip &= is_Bipartite(u, graph);
            }
        }

        // Return whether the graph is bipartite or not
        return isBip;
    }

};
```
    
<hr>
<br><br>

## 20)  [Evaluate Division](https://leetcode.com/problems/evaluate-division/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Depth-First Search` `Breadth-First Search` `Union Find` `Graph` `Shortest Path`

### Code


```cpp
class Solution {
public:
    
    unordered_map < string, unordered_map < string, double > > graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        for (int i = 0; i < equations.size(); i++) {
            auto equation = equations[i];
            string a = equation[0];
            string b = equation[1];
            double value = values[i];

            graph[a][b] = value;
            graph[b][a] = 1 / value;
        }

        vector < double > res;
        for (auto it : queries) {
            string start = it[0];
            string end = it[1];
            // Calculate the result using breadth-first search
            double ans = bfs(start, end);
            res.push_back(ans);
        }
        return res;
    }

    double bfs(string& start, string& target) {
        // check if current and target nodes exist in the graph
        if (graph.find(start) == graph.end() || graph.find(target) == graph.end())
            return -1;

        queue < pair < string, double > > q;
        q.push({start, 1});

        unordered_set < string > vis;
        vis.insert(start);

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            string node = curr.first;
            double value = curr.second;

            // if current node is the target
            if (node == target)
                return value;

            // Traverse the neighbors of the current node
            for (auto neighbor : graph[node]) {
                string next = neighbor.first;
                // check if the neighbor has not been visited before
                if (vis.find(next) == vis.end()) {
                    vis.insert(next);
                    // multiply the current value by the value of the edge to the neighbor
                    q.push({next, value * neighbor.second});
                }
            }
        }
        return -1;
    }
};
```
    
<hr>
<br><br>

## 21)  [Shortest Bridge](https://leetcode.com/problems/shortest-bridge/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Depth-First Search` `Breadth-First Search` `Matrix`

### Code


```cpp
class Solution {

    int n;
    vector < vector < int > > grid;

    // Check if the current position (r, c) is a valid position for island expansion
    bool is_valid(int r, int c, set < pair < int, int > >& isL) {
        return min(r, c) >= 0 && max(r, c) < n && !isL.count({r, c}) && grid[r][c];
    }

    // Depth-first search to expand the island
    void dfs(int r, int c, set < pair < int, int > >& isL) {
        if (!is_valid(r, c, isL)) return;
        isL.insert({r, c});  // Mark the current position as visited
        grid[r][c] = 0;     // Set the current position as water
        dfs(r + 1, c, isL);  // Check the bottom position
        dfs(r - 1, c, isL);  // Check the top position
        dfs(r, c + 1, isL);  // Check the right position
        dfs(r, c - 1, isL);  // Check the left position
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        this -> n = grid.size();
        this -> grid = grid;

        set < pair < int, int > > isl1, isl2;  // Sets to store the positions of the two islands
        bool isL = true;  // Flag to differentiate between the two islands

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y]) {
                    if (isL)
                        dfs(x, y, isl1), isL = false;  // Expand the first island
                    else
                        dfs(x, y, isl2);  // Expand the second island
                }
            }
        }

        int ans = INT_MAX;
        for (auto [x1, y1] : isl1)
            for (auto [x2, y2] : isl2)
                ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);  // Calculate the minimum distance between the two islands
            

        return ans;
    }
};
```
    
<hr>
<br><br>

## 23)  [Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Design` `Binary Search Tree` `Heap (Priority Queue)` `Binary Tree` `Data Stream`

### Code


```cpp
class KthLargest {
public:
    
    // Priority queue to store the kth largest elements
    priority_queue < int, vector < int >, greater < int > > pq;
    int k;

    // Constructor to initialize the object with k and a vector of numbers
    KthLargest(int k, vector < int >& nums) {
        this -> k = k;
        
        // Add all the numbers to the priority queue
        for(auto& x : nums)
            add(x);
    }
    
    // Function to add a new value to the priority queue and return the kth largest element
    int add(int val) {
        // Add the new value to the priority queue
        pq.push(val);  
        
        // Remove the smallest element if the size exceeds k
        if(pq.size() > k)
            pq.pop();
        
        // Return the current kth largest element
        return pq.top();  
    }
};
```
    
<hr>
<br><br>

## 24)  [Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Greedy` `Sorting` `Heap (Priority Queue)`

### Code


```cpp
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Get the size of nums1
        int n = nums1.size();
        
        // Create a vector of indices from 0 to n - 1
        vector < int > idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort the indices based on the corresponding values in nums2
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums2[i] < nums2[j];
        });
        
        // Create a min-heap priority queue
        priority_queue < int, vector < int >, greater < int > > pq;
        
        // Variables to keep track of the current sum and maximum sequence
        long long curr_sum = 0, max_seq = 0;
        
        // Lambda function to add an element to the current sum and the priority queue
        auto add = [&](int x){
            curr_sum += x;
            pq.push(x);
        };
        
        // Lambda function to remove the smallest element from the current sum and the priority queue
        auto remove = [&](){
            curr_sum -= pq.top();
            pq.pop();
        };
        
        // Iterate over the indices in reverse order
        for(int i = n - 1; i >= 0; i--){
            // Add the corresponding element from nums1 to the current sum and the priority queue
            add(nums1[idx[i]]);
            
            // If the size of the priority queue reaches k, update the maximum sequence and remove the smallest element
            if(pq.size() == k){
                max_seq = max(max_seq, curr_sum * nums2[idx[i]]);
                remove();
            }
        }
        
        // Return the maximum sequence
        return max_seq;
    }
};
```
    
<hr>
<br><br>

## 25)  [New 21 Game](https://leetcode.com/problems/new-21-game/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Math` `Dynamic Programming` `Sliding Window` `Probability and Statistics`

### Code


```cpp
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Get the size of nums1
        int n = nums1.size();
        
        // Create a vector of indices from 0 to n - 1
        vector < int > idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort the indices based on the corresponding values in nums2
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums2[i] < nums2[j];
        });
        
        // Create a min-heap priority queue
        priority_queue < int, vector < int >, greater < int > > pq;
        
        // Variables to keep track of the current sum and maximum sequence
        long long curr_sum = 0, max_seq = 0;
        
        // Lambda function to add an element to the current sum and the priority queue
        auto add = [&](int x){
            curr_sum += x;
            pq.push(x);
        };
        
        // Lambda function to remove the smallest element from the current sum and the priority queue
        auto remove = [&](){
            curr_sum -= pq.top();
            pq.pop();
        };
        
        // Iterate over the indices in reverse order
        for(int i = n - 1; i >= 0; i--){
            // Add the corresponding element from nums1 to the current sum and the priority queue
            add(nums1[idx[i]]);
            
            // If the size of the priority queue reaches k, update the maximum sequence and remove the smallest element
            if(pq.size() == k){
                max_seq = max(max_seq, curr_sum * nums2[idx[i]]);
                remove();
            }
        }
        
        // Return the maximum sequence
        return max_seq;
    }
};
```
    
<hr>
<br><br>

## 26)  [Stone Game II](https://leetcode.com/problems/stone-game-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Math` `Dynamic Programming` `Game Theory`

### Code


```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        // dp[i][m] represents the maximum number of stones the player can obtain
        // when starting at pile i with a maximum pick of m.
        vector < vector < int > > dp(n, vector < int > (2 * n + 5));
        
        // sum[i] stores the sum of stones from pile i to the end.
        vector < int > sum(n + 5);
        
        // Calculate the sum of stones from each pile to the end.
        for (int i = n - 1; i >= 0; i--)
            sum[i] = piles[i] + sum[i + 1];
        
        // Iterate over the piles from right to left.
        for (int i = n - 1; i >= 0; i--) {
            // Iterate over the maximum pick from 1 to n.
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n)
                    // If there are not enough piles remaining, take all the stones.
                    dp[i][m] = sum[i];
                else {
                    // Consider all possible picks from 1 to 2 * m.
                    for (int x = 1; x <= 2 * m; x++)
                        // Calculate the maximum stones the player can obtain
                        // by either taking x stones and recursively solving for the remaining piles,
                        // or not taking any stones and letting the other player play.
                        dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(m, x)]);
                }
            }
        }
        
        // The maximum number of stones the first player can obtain starting from the first pile
        // with a maximum pick of 1 is stored in dp[0][1].
        return dp[0][1];
    }
};
```
    
<hr>
<br><br>

## 27)  [Stone Game III](https://leetcode.com/problems/stone-game-iii/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Math` `Dynamic Programming` `Game Theory`

### Code


```cpp
class Solution {
public:
    string stoneGameIII(const vector < int >& stones) {
        int n = stones.size();

        // Create a dynamic programming table with initial values set to -1e9
        vector < int > dp(n + 1, -1e9);

        // Set the value of the last cell in the dp table to 0
        dp[n] = 0;

        // Iterate backwards through the stones
        for (int i = n - 1; i >= 0; --i) {
            // Iterate from 0 to 2 (inclusive) to simulate taking 1, 2, or 3 stones
            for (int k = 0, take = 0; k < 3 && i + k < n; ++k) {
                // Calculate the total number of stones taken
                take += stones[i + k];

                // Update the value of dp[i] by taking the maximum of its current value
                // and the difference between the total number of stones taken and the value
                // of dp at the next position
                dp[i] = max(dp[i], take - dp[min(i + k + 1, n)]);
            }
        }

        // Create a vector with the possible outcomes: "Alice", "Tie", "Bob"
        vector < string > ans = {"Alice", "Tie", "Bob"};

        // Return the corresponding outcome based on the value of dp[0]
        return ans[(dp[0] == 0) + (dp[0] < 0) * 2];
    }
};
```
    
<hr>
<br><br>

## 28)  [Minimum Cost to Cut a Stick](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Sorting`

### Code


```cpp
class Solution {
public:

    int minCost(int n, vector < int >& cuts) {
        // Get the size of the cuts vector
        int m = cuts.size();

        // Insert 0 at the beginning and n at the end of the cuts vector
        cuts.insert(cuts.begin(), 0);
        cuts.insert(cuts.end(), n);
        
        // Sort the cuts vector in ascending order
        sort(cuts.begin(), cuts.end());
        
        // Create a 2D vector dp to store the minimum cost values
        vector < vector < int > > dp(m + 5, vector < int > (m + 5, INT_MAX));
        
        // Initialize the base case where l > r with 0 cost
        for(int l = 0; l <= m + 1; l++)
            for(int r = l - 1; r >= 0; r--)
                dp[l][r] = 0;
        
        // Calculate the minimum cost for each subproblem
        for(int l = m; l >= 1; l--)
            for(int r = 1; r <= m; r++)
                for(int idx = l; idx <= r; idx++)
                    // Update the minimum cost based on the cuts and subproblems
                    dp[l][r] = min(dp[l][r], cuts[r + 1] - cuts[l - 1] + dp[l][idx - 1] + dp[idx + 1][r]);
        
        // Return the minimum cost of the original problem
        return dp[1][m];
    }
};
```
    
<hr>
<br><br>

## 29)  [Design Parking System](https://leetcode.com/problems/design-parking-system/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Design` `Simulation` `Counting`

### Code


```cpp
class ParkingSystem {
public:

    // Define a vector to store the number of available parking spaces for each car type
    vector < int > carTypes;

    ParkingSystem(int big, int medium, int small) {
        // Initialize the vector with the given number of parking spaces for each car type
        carTypes = { big, medium, small };
    }
    
    bool addCar(int carType) {
        // Decrease the number of available parking spaces for the given car type and check if it's still greater than 0
        return carTypes[--carType]-- > 0;
    }
};
```
    
<hr>
<br><br>

## 30)  [Design HashSet](https://leetcode.com/problems/design-hashset/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Linked List` `Design` `Hash Function`

### Code


```cpp
class MyHashSet {
public:

    // Declare an unordered_set named hash_set to store integers
    unordered_set<int> hash_set;

    MyHashSet() {
        // Initialize the unordered_set using the default constructor
        hash_set = unordered_set < int > ();
    }
    
    void add(int key) {
        // Insert the given key into the hash_set
        hash_set.insert(key);
    }
    
    void remove(int key) {
        // Remove the given key from the hash_set
        hash_set.erase(key);
    }
    
    bool contains(int key) {
        // Check if the given key exists in the hash_set and return true if it does, false otherwise
        return hash_set.count(key);
    }
};
```
    
<hr>
<br><br>

## 31)  [Design Underground System](https://leetcode.com/problems/design-underground-system/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `String` `Design`

### Code


```cpp
class UndergroundSystem {
public:

    // Map to store the travel details for each station pair
    map<pair<string, string>, pair<int, int>> mp;
    // Hash map to store the check-in details for each person
    unordered_map<int, pair<string, int>> person;

    // Constructor to initialize the data structures
    UndergroundSystem() {
        mp.clear();
        person.clear();
    }

    // Function to record the check-in of a person
    void checkIn(int id, string stationName, int t) {
        person[id] = {stationName, t};
    }

    // Function to record the check-out of a person and calculate the travel duration
    void checkOut(int id, string stationName, int t) {
        // Check if the station pair exists in the map
        if (mp.find({person[id].first, stationName}) == mp.end()) {
            // If not, create a new entry with the travel duration and count set to the current duration and 1 respectively
            mp[{person[id].first, stationName}] = {t - person[id].second, 1};
        } else {
            // If the station pair already exists, update the travel duration and count
            mp[{person[id].first, stationName}].first += t - person[id].second;
            mp[{person[id].first, stationName}].second++;
        }
    }

    // Function to calculate the average travel time between two stations
    double getAverageTime(string startStation, string endStation) {
        // Calculate and return the average travel time by dividing the total duration by the count
        return 1.0 * mp[{startStation, endStation}].first / mp[{startStation, endStation}].second;
    }
};
```
    