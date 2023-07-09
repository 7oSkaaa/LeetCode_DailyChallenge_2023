# LeetCode Daily Challenge Problems for July

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
1. **[Fair Distribution of Cookies](#01--fair-distribution-of-cookies)**
1. **[Maximum Number of Achievable Transfer Requests](#02--maximum-number-of-achievable-transfer-requests)**
1. **[Buddy Strings](#03--buddy-strings)**
1. **[Single Number II](#04--single-number-ii)**
1. **[Longest Subarray of 1's After Deleting One Element](#05--longest-subarray-of-1s-after-deleting-one-element)**
1. **[Minimum Size Subarray Sum](#06--minimum-size-subarray-sum)**
1. **[Maximize the Confusion of an Exam](#07--maximize-the-confusion-of-an-exam)**
1. **[Substring With Largest Variance](#09--substring-with-largest-variance)**

<hr>
<br><br>

## 01)  [Fair Distribution of Cookies](https://leetcode.com/problems/fair-distribution-of-cookies/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Backtracking` `Bit Manipulation` `Bitmask`

### Code


```cpp
class Solution {
public:
    // Function to distribute cookies among k children
    int distributeCookies(vector<int>& cookies, int k) {
        // Sort the cookies in ascending order
        sort(cookies.begin(), cookies.end());
        // Initialize ans variable with a large value
        int ans = 1e9;

        // Generate permutations of cookies
        do {
            // Create a min heap priority queue to store the sum of cookies for each child
            priority_queue<int, vector<int>, greater<int>> pq;
            
            // Initialize the priority queue with k zeros
            for (int i = 0; i < k; i++)
                pq.push(0);
            
            // Initialize the current answer variable to 0
            int cur_ans = 0;

            // Distribute cookies among children
            for (int i = 0; i < cookies.size(); i++) {
                // Calculate the new total for the child with the least sum of cookies
                int new_tp = pq.top() + cookies[i];

                // Update the current answer with the maximum sum encountered
                cur_ans = max(cur_ans, new_tp);

                // Remove the child with the least sum of cookies from the priority queue
                pq.pop();

                // Add the child with the updated sum back to the priority queue
                pq.push(new_tp);
            }

            // Update the minimum answer encountered so far
            ans = min(ans, cur_ans);

        } while (next_permutation(cookies.begin(), cookies.end()));

        // Return the minimum answer
        return ans;
    }
};
```
    

<hr>
<br><br>

## 02)  [Maximum Number of Achievable Transfer Requests](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Backtracking` `Bit Manipulation` `Enumeration`

### Code


```cpp
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        // Initialize variables r and maxReq.
        int r = requests.size(), maxReq = 0;
        
        // Iterate through all possible combinations of requests using a bitmask.
        for(int mask = 0; mask < (1 << r); mask++){
            // Create a vector net to keep track of the degree of each node.
            vector < int > net(n);
            
            // Iterate through each request in the requests vector.
            for(int i = 0; i < r; i++){
                // Check if the i-th request is included in the bitmask.
                if(mask & (1 << i)){
                    // If the request is included, decrement the net of the source node
                    // and increment the net of the destination node.
                    net[requests[i][0]]--;
                    net[requests[i][1]]++;
                }
            }
            
            // Check if all nodes have a net of 0, indicating that requests can be made.
            bool can_make_requests = true;
            for(int i = 0; i < n; i++)
                can_make_requests &= (net[i] == 0);
            
            // If all nodes have a net of 0, update maxReq with the maximum number of requests made.
            if(can_make_requests)
                maxReq = max(maxReq, __builtin_popcount(mask));
        }
        
        // Return the maximum number of requests that can be made.
        return maxReq;
    }
};
```
    
<hr>
<br><br>

## 03)  [Buddy Strings](https://leetcode.com/problems/buddy-strings/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Hash Table` `String`

### Code


```cpp
class Solution {
public:
    bool buddyStrings(const string& s, const string& goal) {
        // if the two strings aren't the same size
        if(s.size() != goal.size())
            return false;

        // Create a frequency array to count the occurrence of each character in the first string.
        vector < int > freq(26);
        
        // Variable to store the count of characters that appear more than once in the first string.
        int is_same = 0;

        // 2D vector to store the differences between characters of the two strings.
        vector < int > diffs;
        
        // Iterate through each character in the first string.
        for(int i = 0; i < s.size(); i++){
            // Update the frequency array for the current character.
            freq[s[i] - 'a']++;
            
            // If the characters at the same index in the two strings are different,
            // add them to the differences vector.
            if(s[i] != goal[i])
                diffs.push_back(i);
            
            // Update the count of characters that appear more than once in the first string.
            is_same += (freq[s[i] - 'a'] > 1);
        }
        
        // If there are more than two differences, it is not possible to make the strings equal by swapping two characters.
        if(diffs.size() > 2 || diffs.size() == 1)
            return false;

        // If there are no differences, check if there are characters that appear more than once in the first string.
        if(diffs.empty())
            return is_same;

        // Check if the characters to be swapped are the same in the two differences.
        for(int i = 0; i < 2; i++){
            if(s[diffs[i]] != goal[diffs[!i]])
                return false;
        }

        // If all conditions are satisfied, it is possible to make the strings equal by swapping two characters.
        return true;
    }
};
```
    
<hr>
<br><br>

## 04)  [Single Number II](https://leetcode.com/problems/single-number-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Bit Manipulation`

### Code


```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Variable to store the single number
        int single = 0;

        // Loop through each bit position from 0 to 31
        for(int bits = 0, curr_bit = 0; bits < 32; bits++, curr_bit = 0) {
            // Iterate over each element in the vector
            for(auto& i : nums) {
                // Check if the current bit is set in the element
                if(i & (1ll << bits))
                    curr_bit++;
            }

            // Check if the count of the current bit is not a multiple of 3
            if(curr_bit % 3 == 1)
                // Set the corresponding bit in the single variable
                single |= (1 << bits);
        }

        // Return the single number
        return single;
    }
};
```
    
<hr>
<br><br>

## 05)  [Longest Subarray of 1's After Deleting One Element](https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Sliding Window`

### Code


```cpp
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // n is the size of the input vector
        int n = nums.size();
        // l and r are variables used for tracking the left and right indices of the subarray
        int l = 0, r = 0;
        // maxLen is used to store the length of the longest subarray
        int maxLen = 0;
        // sum is used to keep track of the sum of the elements in the subarray
        int sum = 0;

        // Loop through the elements of the vector
        while(r < n) {
            // Add the current element to the sum
            sum += nums[r];

            // Shrink the subarray from the left until the sum is greater than or equal to the length of the subarray
            while(l < r && sum < r - l)
                sum -= nums[l++];

            // Update the maxLen if the current subarray length is greater than the previous maxLen
            maxLen = max(maxLen, r - l);

            // Move to the next element
            r++;
        }

        // Return the length of the longest subarray
        return maxLen;
    }
};
```
    
<hr>
<br><br>

## 06)  [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Sliding Window` `Prefix Sum`

### Code


```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0; // Pointers for the left and right ends of the subarray
        int Max_length = INT_MAX; // Maximum length of subarray
        int sum = 0; // Current sum of elements in the subarray

        while (l < nums.size()) {
            // Add the next element to the sum and move the right pointer
            while (r < nums.size() && sum < target)
                sum += nums[r++];

            // Update the maximum length if the current length is smaller
            if (sum >= target)
                Max_length = min(Max_length, r - l);

            // Remove the leftmost element from the sum and move the left pointer
            sum -= nums[l++];
        }

        // Return the minimum subarray length or 0 if no such subarray exists
        return (Max_length == INT_MAX ? 0 : Max_length);
    }
};
```
    
<hr>
<br><br>

## 07)  [Maximize the Confusion of an Exam](https://leetcode.com/problems/maximize-the-confusion-of-an-exam/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`String` `Binary Search` `Sliding Window` `Prefix Sum`

### Code


```cpp
class Solution {
public:
    int getMaxConf(const string& answers, int k, char choice) {
        int n = answers.size();
        int maxConf = 0, currChoice = 0;
        int l = 0, r = 0;

        // Iterate through the answer key using two pointers 'l' and 'r'.
        while (r < n) {
            // Increment 'currChoice' if the answer at index 'r' matches the specified 'choice'.
            currChoice += (answers[r] == choice);

            // Adjust the window size by moving the left pointer 'l' if the current number of choices 'currChoice' exceeds the allowed 'k'.
            while (currChoice > k)
                currChoice -= (answers[l++] == choice);

            // Update the maximum consecutive count by comparing the current window size 'r - l + 1' with the previous maximum.
            maxConf = max(maxConf, r - l + 1);
            r++;
        }

        return maxConf;
    }

    int maxConsecutiveAnswers(const string& answerKey, int k) {
        // Return the maximum count between the consecutive 'T' answers and consecutive 'F' answers.
        return max(getMaxConf(answerKey, k, 'T'), getMaxConf(answerKey, k, 'F'));
    }
};
```
    
<hr>
<br><br>

## 09)  [Substring With Largest Variance](https://leetcode.com/problems/substring-with-largest-variance/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    int getDiff(char a, char b, const string& s) {
        int bestDiff = 0;
        int cnt_a = 0, cnt_b = 0;

        // Iterate over each character 'c' in the string 's'.
        for (auto& c : s) {
            // If the character 'c' is equal to 'a', increment the count of 'a' (cnt_a).
            if (c == a) cnt_a++;

            // If the character 'c' is equal to 'b', increment the count of 'b' (cnt_b).
            if (c == b) cnt_b++;

            // Calculate the difference between the counts of 'a' and 'b',
            // and update the best difference if necessary.
            bestDiff = max(bestDiff, cnt_a - max(cnt_b, 1));

            // If the count of 'a' is less than the count of 'b',
            // reset both counts to 0 to start counting again.
            if (cnt_a < cnt_b) {
                cnt_b = cnt_a = 0;
            }
        }

        // Return the maximum difference between the counts of 'a' and 'b' in the string 's'.
        return bestDiff;
    }

    int largestVariance(const string& s) {
        // Initialize a frequency array to count the occurrences of each character in 's'.
        vector<int> freq(26);

        // Iterate over each character 'c' in the string 's'.
        for (auto& c : s) {
            // Increment the count of the character 'c' in the frequency array.
            freq[c - 'a']++;
        }

        // Initialize the best difference as 0.
        int bestDiff = 0;

        // Iterate over each character 'a' from 'a' to 'z'.
        for (char a = 'a'; a <= 'z'; a++) {
            // Iterate over each character 'b' from 'a' to 'z'.
            for (char b = 'a'; b <= 'z'; b++) {
                // Check if the counts of both characters 'a' and 'b' are non-zero and 'a' is not equal to 'b'.
                if (freq[a - 'a'] && freq[b - 'a'] && a != b) {
                    // Calculate the difference between 'a' and 'b' in the string 's'
                    // using the getDiff() function, and update the best difference if necessary.
                    bestDiff = max(bestDiff, getDiff(a, b, s));
                }
            }
        }

        // Return the largest variance found in the string 's'.
        return bestDiff;
    }
};
```
    