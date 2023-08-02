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
1. **[Minimum Depth of Binary Tree](#10--minimum-depth-of-binary-tree)**
1. **[Course Schedule](#13--course-schedule)**
1. **[Longest Arithmetic Subsequence of Given Difference](#14--longest-arithmetic-subsequence-of-given-difference)**
1. **[Maximum Number of Events That Can Be Attended II](#15--maximum-number-of-events-that-can-be-attended-ii)**
1. **[Smallest Sufficient Team](#16--smallest-sufficient-team)**
1. **[Add Two Numbers II](#17--add-two-numbers-ii)**
1. **[LRU Cache](#18--lru-cache)**
1. **[Non-overlapping Intervals](#19--non-overlapping-intervals)**
1. **[Asteroid Collision](#20--asteroid-collision)**
1. **[Knight Probability in Chessboard](#22--knight-probability-in-chessboard)**
1. **[All Possible Full Binary Trees](#23--all-possible-full-binary-trees)**
1. **[Pow(x, n)](#24--powx-n)**
1. **[Peak Index in a Mountain Array](#25--peak-index-in-a-mountain-array)**
1. **[Minimum Speed to Arrive on Time](#26--minimum-speed-to-arrive-on-time)**
1. **[Maximum Running Time of N Computers](#27--maximum-running-time-of-n-computers)**
1. **[Predict the Winner](#28--predict-the-winner)**
1. **[Soup Servings](#29--soup-servings)**
1. **[Strange Printer](#30--strange-printer)**

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
    
<hr>
<br><br>

## 10)  [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)

### Difficulty

![](https://img.shields.io/badge/Easy-green?style=for-the-badge)

### Related Topic

`Tree` `Depth-First Search` `Breadth-First Search` `Binary Tree`

### Code


```cpp
class Solution {
public:
    int minDepth(TreeNode* root, int depth = 0) {
        // return 0 if there are no nodes in the tree otherwise it's not a leaf node
        if(!root) return (!depth ? 0 : 1e9);
        
        // return 1 if it's a leaf node
        if(!root -> left && !root -> right) return 1;

        // get the minimum depth of leaf node from the left and right subtree
        return 1 + min(minDepth(root -> left, depth + 1), minDepth(root -> right, depth + 1));
    }
};
```
    
<hr>
<br><br>

## 13)  [Course Schedule](https://leetcode.com/problems/course-schedule/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Depth-First Search` `Breadth-First Search` `Graph` `Topological Sort`

### Code


```cpp
class Solution {
public:
    // Declare variables for adjacency list, depth and degree
    vector < vector < int > > adj;
    vector < int > depth, deg;

    // Function to initialize adjacency list, depth and degree
    void init(int n){
        adj.assign(n + 10, vector < int > ());
        depth.assign(n + 10, 0);
        deg.assign(n + 10, 0);
    }

    // Function to add edges to the adjacency list and increment degree of destination node
    void add_edge(int u, int v){
        adj[v].push_back(u);
        deg[u]++;
    }

    // Function to perform topological sort and return true if possible, false otherwise
    bool topology (int n){
        queue < int > topo;
        vector < int > graph;

        // Push all nodes with degree 0 into the queue
        for(int i = 0; i < n; i++)
            if(deg[i] == 0) topo.push(i), deg[i]--;

        // Perform topological sort
        while(!topo.empty()){
            int curr_node = topo.front();
            topo.pop();
            graph.push_back(curr_node);

            // Decrement degree of all neighbors and push them into queue if degree becomes 0
            for(auto& new_node : adj[curr_node]){
                deg[new_node]--;
                if(deg[new_node] == 0)
                    topo.push(new_node);
            }
        }

        // Return true if all nodes have been visited, false otherwise
        return graph.size() == n;
    }

    // Function to check if all courses can be finished
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        init(numCourses);

        // Add all prerequisites as edges to the adjacency list
        for(auto& pr : prerequisites)
            add_edge(pr[0], pr[1]);

        // Perform topological sort and return result
        return topology(numCourses);
    }
};
```
    
<hr>
<br><br>

## 14)  [Longest Arithmetic Subsequence of Given Difference](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Hash Table` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        // N is a constant representing a large number.
        constexpr int N = 2e4;

        // dp is a vector of integers with size 2 * N + 5.
        // It is used to store the dynamic programming values.
        vector < int > dp(2 * N + 5);

        // Iterate through each element x in the input vector arr.
        for (auto& x : arr)
            // Calculate the index for the current element x in the dp vector by adding N.
            // Update the value at the calculated index in the dp vector by taking the maximum
            // between the current value and the value at index x - difference + N + 1.
            dp[x + N] = max(dp[x + N], dp[x - difference + N] + 1);

        // Return the maximum element in the dp vector.
        return *max_element(dp.begin(), dp.end());
    }
};
```
    
<hr>
<br><br>

## 15)  [Maximum Number of Events That Can Be Attended II](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Dynamic Programming` `Sorting`

### Code


```cpp
class Solution {
public:

    int n;  // Number of events
    vector<vector<int>> dp;  // Dynamic programming table to store computed results
 
    // Function to get the index of the next event
    // Returns the index of the next event after the current event
    int get_next_event(int idx, vector<vector<int>>& events){
        int l = idx + 1, r = n - 1, ans = n;
        while(l <= r){
            int m = l + (r - l) / 2;
            (events[m][0] > events[idx][1] ? r = m - 1, ans = m : l = m + 1);
        }
        return ans;
    }

    // Function to compute the maximum sum of event values
    int maxSum(int idx, int events_left, vector<vector<int>>& events){
        if(idx == n) return 0;  // Base case: No more events left to consider
        int& ret = dp[idx][events_left];
        if(~ret) return ret;  // If result is already computed, return it
        ret = maxSum(idx + 1, events_left, events);  // Exclude the current event
        if(events_left){
            int next_idx = get_next_event(idx, events);
            // Include the current event and recursively compute the maximum sum
            ret = max(ret, maxSum(next_idx, events_left - 1, events) + events[idx][2]);
        }
        return ret;
    }

    // Function to calculate the maximum value of events that can be attended
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();  // Number of events
        sort(events.begin(), events.end());  // Sort events based on their starting time
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));  // Initialize the DP table
        return maxSum(0, k, events);  // Compute and return the maximum sum
    }
};
```
    
<hr>
<br><br>

## 16)  [Smallest Sufficient Team](https://leetcode.com/problems/smallest-sufficient-team/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Bit Manipulation` `Bitmask`

### Code


```cpp
class Solution {
public:
    int n, m, req_skills_mask; // Variables to store the number of people, number of required skills, and the bitmask for required skills
    map<string, int> mapping; // Mapping of skills to their indices
    vector<vector<int>> dp; // Dynamic programming table
    vector<int> people_masks, people_ans; // Bitmasks for each person's skills and the answer vector

    // Function to build the mapping of skills to indices
    void build(const vector<string>& req_skills) {
        int idx = 0;
        // Iterate through the required skills and assign indices
        for (auto& skill : req_skills)
            mapping[skill] = idx++;
    }

    // Function to build the bitmask for a person's skills
    int build_mask(const vector<string>& people_skill) {
        int mask = 0;
        // Iterate through the person's skills and set the corresponding bits in the bitmask
        for (auto& skill : people_skill)
            mask |= (1 << mapping[skill]);
        return mask;
    }

    // Function to initialize the variables and data structures
    void init(const vector<string>& req_skills, const vector<vector<string>>& people) {
        req_skills_mask = 0; // Initialize the bitmask for required skills to 0
        n = people.size(); // Store the number of people
        m = req_skills.size(); // Store the number of required skills
        people_masks = vector<int>(n); // Initialize the bitmask for each person's skills
        // Build the bitmask for each person's skills
        for (int i = 0; i < n; i++)
            people_masks[i] = build_mask(people[i]);
        // Build the bitmask for required skills
        for (auto& skill : req_skills)
            req_skills_mask |= (1 << mapping[skill]);
        dp = vector<vector<int>>(n, vector<int>(1 << m, -1)); // Initialize the dynamic programming table with -1
    }

    // Function to calculate the minimum number of people needed
    int get_min_people(int idx, int mask) {
        // Return a large value if the bitmask doesn't satisfy the required skills
        if (idx == n) return ((mask & req_skills_mask) == req_skills_mask ? 0 : 1e9);

        int& ret = dp[idx][mask]; // Reference to the corresponding entry in the dynamic programming table
        if (~ret) return ret; // Return the stored value if it has been calculated previously

        // Recursively calculate the minimum number of people needed
        ret = get_min_people(idx + 1, mask);
        ret = min(ret, get_min_people(idx + 1, mask | people_masks[idx]) + 1);

        return ret;
    }

    // Function to build the answer vector
    void build_ans(int idx, int mask) {
        if (idx == n) return; // Base case: reached the end of the people

        int& ret = dp[idx][mask]; // Reference to the corresponding entry in the dynamic programming table

        // Check if the current person is included in the minimum team
        if (ret == get_min_people(idx + 1, mask))
            build_ans(idx + 1, mask);
        else {
            people_ans.push_back(idx); // Add the current person to the answer vector
            build_ans(idx + 1, mask | people_masks[idx]);
        }
    }

    // Function to find the smallest sufficient team
    vector<int> smallestSufficientTeam(const vector<string>& req_skills, const vector<vector<string>>& people) {
        build(req_skills); // Build the skill mapping
        init(req_skills, people); // Initialize the variables and data structures
        get_min_people(0, 0); // Calculate the minimum number of people needed
        build_ans(0, 0); // Build the answer vector
        return people_ans; // Return the answer vector
    }
};
```
    
<hr>
<br><br>

## 17)  [Add Two Numbers II](https://leetcode.com/problems/add-two-numbers-ii/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Linked List` `Math` `Stack`

### Code


```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create two stacks to store the digits of l1 and l2
        stack < int > s1, s2;
        
        // Push digits of l1 into stack s1
        while (l1 != NULL)
            s1.push(l1 -> val), l1 = l1 -> next;
        
        // Push digits of l2 into stack s2
        while (l2 != NULL)
            s2.push(l2 -> val), l2 = l2 -> next;
        
        // Create a dummy node as the head of the resulting linked list
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        
        // Perform addition digit by digit until both stacks and carry are empty
        while (!s1.empty() || !s2.empty() || carry) {
            int first = 0, second = 0;
            
            // Get the top digit from stack s1 if it is not empty
            if (!s1.empty())
                first = s1.top(), s1.pop();
            
            // Get the top digit from stack s2 if it is not empty
            if (!s2.empty())
                second = s2.top(), s2.pop();
            
            // Calculate the sum of the digits including the carry
            int sum = carry + first + second;
            carry = sum / 10;
            
            // Create a new node with the digit and attach it to the resulting linked list
            ListNode* attach = new ListNode(sum % 10);
            attach -> next = dummy -> next;
            dummy -> next = attach;
        }
        
        // Return the head of the resulting linked list
        return dummy->next;
    }
};
```
    
<hr>
<br><br>

## 18)  [LRU Cache](https://leetcode.com/problems/lru-cache/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Hash Table` `Linked List` `Design` `Doubly-Linked List`

### Code


```cpp
class Node {
public:
    int key, val;
    Node *next, *prev;
    Node(int key = -1, int val = -1) {
        this -> key = key;
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class LRUCache {
public:
    static constexpr int N = 1e4 + 5;
    int maxCap, currSz; // Maximum capacity of the cache
    vector < Node* > nodes; // Map to store key-node pairs
    Node *head = new Node(); // Dummy head node for doubly-linked list
    Node *tail = new Node(); // Dummy tail node for doubly-linked list

    // Constructor to initialize the LRUCache with a given capacity
    LRUCache(int capacity) {
        maxCap = capacity, currSz = 0;
        head -> next = tail;
        tail -> prev = head;
        nodes = vector < Node* > (N, nullptr);
    }

    // Function to add a new node after the head node in the doubly-linked list
    void addNode(Node *newNode) {
        Node *temp = head -> next;
        head -> next = newNode;
        newNode -> next = temp;
        newNode -> prev = head;
        temp -> prev = newNode;
    }

    // Function to delete a node from the doubly-linked list
    void deleteNode(Node *delNode) {
        Node *prev = delNode -> prev;
        Node* next = delNode -> next;
        prev -> next = next;
        next -> prev = prev;
    }

    // Function to retrieve the value associated with the given key
    int get(int key) {
        if (!nodes[key]) return -1; // Key not found in cache
        Node *node = nodes[key];
        deleteNode(node); // Move the accessed node to the front
        addNode(node);
        nodes[key] = head -> next; // Update the position in the cache
        return nodes[key] -> val; // Return the value associated with the key
    }

    // Function to insert or update a key-value pair in the cache
    void put(int key, int value) {
        if (nodes[key]) {
            Node *node = nodes[key];
            deleteNode(node); // Remove the existing node
            node -> val = value; // Update the value of the existing node
            addNode(node); // Move the node to the front
            nodes[key] = head -> next; // Update the position in the cache
        } else {
            if (currSz == maxCap) {
                Node *prev = tail -> prev; // Remove the least recently used node
                deleteNode(prev);
                Node *newNode = new Node(key, value); // Create a new node with the given key and value
                addNode(newNode); // Add the new node to the front
                nodes[prev -> key] = nullptr; // Remove the old key from the cache
                nodes[key] = head -> next; // Update the position in the cache
            } else {
                Node *newNode = new Node(key, value); // Create a new node with the given key and value
                addNode(newNode); // Add the new node to the front
                nodes[key] = head -> next; // Update the position in the cache
                currSz++;
            }
        }
    }
};
```
    
<hr>
<br><br>

## 19)  [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Dynamic Programming` `Greedy` `Sorting`

### Code


```cpp
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort the intervals based on their start times in ascending order
        sort(intervals.begin(), intervals.end());
        
        // Initialize a variable to store the count of erased intervals
        int erased_intervals = 0;
        
        // Initialize a variable to keep track of the end time of the previous interval
        int previous_end = intervals[0][1];
        
        // Loop through the intervals starting from the second interval (index 1)
        for (int i = 1; i < intervals.size(); ++i) {
            // If the current interval overlaps with the previous one
            if (intervals[i][0] < previous_end) {
                // Increment the erased_intervals count, as we need to erase the current interval
                erased_intervals++;
                
                // Update the previous_end to the minimum of the current interval's end time and the previous_end
                previous_end = min(previous_end, intervals[i][1]);
            } else {
                // If the current interval does not overlap with the previous one, update the previous_end
                previous_end = intervals[i][1];
            }
        }
        
        // Return the count of erased intervals
        return erased_intervals;
    }
};
```
    
<hr>
<br><br>

## 20)  [Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Stack` `Simulation`

### Code


```cpp
class Solution {
public:
    vector < int > asteroidCollision(vector < int >& ast) {
        int n = ast.size();
        stack < int > s; // Stack to simulate collisions.

        // Iterating through the asteroids.
        for (int i = 0; i <  n;  i++) {
            if (ast[i] > 0 || s.empty()) // If the asteroid is positive or stack is empty, push it onto the stack.
                s.push(ast[i]);
            else {
                // Handling negative asteroids colliding with positive ones.
                while (!s.empty() && s.top() > 0 && s.top() < abs(ast[i]))
                    s.pop(); // Pop the positive asteroids until they're smaller or equal to the negative one.

                if (!s.empty() && s.top() == abs(ast[i]))
                    s.pop(); // If a positive asteroid equals the negative one in size, they both explode.

                else if (s.empty() || s.top() < 0) 
                    s.push(ast[i]); // If the stack is empty or the top asteroid is negative, the negative asteroid survives.
            }
        }

        int sz = s.size();
        vector < int > res(sz);

        // Reconstructing the final result.
        for (int i = sz - 1; ~i; i--) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};
```
    
<hr>
<br><br>

## 22)  [Knight Probability in Chessboard](https://leetcode.com/problems/knight-probability-in-chessboard/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // Define a 3D DP array to store the calculated probabilities
    double dp[101][25][25];
    // Define a vector of pairs to represent the possible knight move directions
    vector<pair<int, int>> dir;

    // Constructor to initialize the DP array and direction vector
    Solution() {
        // Set all values in the DP array to -1 (indicating not calculated yet)
        memset(dp, -1, sizeof(dp));
        // Populate the direction vector with the possible knight moves
        dir = {{1, 2}, {2, 1}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}, {2, -1}, {-1, 2}};
    }

    // Function to check if a position (i, j) is valid in an n x n board
    bool valid(int i, int j, int n) {
        return 0 <= i && i < n && 0 <= j && j < n;
    }

    // Function to calculate the probability of a knight staying on the board after making k moves
    double knightProbability(int n, int k, int row, int column) {
        // If the position (row, column) is not valid, the probability is 0
        if (!valid(row, column, n))
            return 0;

        // If k is 0, the probability of staying on the board is 1 (base case)
        if (k == 0)
            return 1;

        // Use a reference variable 'ret' to store the result for current state
        double &ret = dp[k][row][column];

        // If the result has already been calculated, return it
        if (ret == ret)
            return ret;

        // Initialize 'ret' to 0
        ret = 0;

        // Iterate over all possible knight move directions
        for (auto& [dx, dy] : dir) {
            // Calculate the probability of moving to the next position
            ret += 1 / 8.0 * knightProbability(n, k - 1, row + dx, column + dy);
        }

        // Return the calculated probability for current state
        return ret;
    }
};
```
    
<hr>
<br><br>

## 23)  [All Possible Full Binary Trees](https://leetcode.com/problems/all-possible-full-binary-trees/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Dynamic Programming` `Tree` `Recursion` `Memoization` `Binary Tree`

### Code


```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Declare a map 'dp' to store the results of subproblems (memoization)
    map<int, vector<TreeNode*>> dp;
    
    // Function to generate all possible full binary trees with 'n' nodes
    vector<TreeNode*> allPossibleFBT(int n) {
        // If 'n' is even, it is not possible to create a full binary tree with 'n' nodes, return an empty vector
        if (n % 2 == 0)
            return {};
        
        // If 'n' is 1, there is only one possible full binary tree with a single node, return a vector containing that node
        if (n == 1)
            return {new TreeNode()};
        
        // If the result for 'n' is already computed, return it from the map 'dp'
        if (dp.count(n))
            return dp[n];
        
        // Initialize an empty vector for 'n' in 'dp'
        dp[n] = {};
        
        // Loop through all possible left subtree sizes (odd numbers from 1 to n-1)
        for (int l = 1; l < n; l += 2) {
            // Calculate the size of the right subtree
            int r = n - l - 1;
            
            // Recursively generate all possible full binary trees for left and right subtrees
            vector<TreeNode*> left = allPossibleFBT(l);
            vector<TreeNode*> right = allPossibleFBT(r);
            
            // Combine the left and right subtrees to form the full binary trees with 'n' nodes
            for (TreeNode* L : left) {
                for (TreeNode* R : right) {
                    // Create a new full binary tree with root having value 0 and left and right subtrees as 'L' and 'R'
                    dp[n].push_back(new TreeNode(0, L, R));
                }
            }
        }
        
        // Return the vector of all possible full binary trees with 'n' nodes
        return dp[n];
    }
};
```
    
<hr>
<br><br>

## 24)  [Pow(x, n)](https://leetcode.com/problems/powx-n/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Math` `Recursion`

### Code


```cpp
class Solution {
public:
    double myPow(double x, int n) {
        // Initialize a variable "power" to store the result of the power calculation, and set it to 1 initially
        double power = 1;
        // Check if the value of "n" is negative and store the result in a boolean variable "neg"
        bool neg = (n < 0);

        // Start a loop that continues as long as "n" is non-zero
        while (n) {
            // Check if "n" is odd (n % 2 is non-zero), and if so, multiply "power" with "x"
            if (n % 2)
                power *= x;
            
            // Square the value of "x" in each iteration
            x *= x;

            // Divide "n" by 2 in each iteration to perform binary exponentiation
            n /= 2;
        }

        // Return the final result, either "power" or its reciprocal based on the value of "neg"
        return (neg ? 1 / power : power);
    }
};
```
    
<hr>
<br><br>

## 25)  [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Initialize two pointers l and r to the start and end of the array, and a variable ans to store the peak index
        int l = 0, r = arr.size() - 1, ans = 0;
        // Use a binary search algorithm to find the peak index
        while(l <= r){
            // Calculate the middle index using the l and r pointers
            int m = l + (r - l) / 2;
            // If the element at index m is greater than the element at index m+1, move r pointer to m-1 and update ans to m
            // This means that the peak is on the left side of m
            (arr[m] > arr[m + 1] ? r = m - 1, ans = m : l = m + 1);
        }
        // Return the peak index
        return ans;
    }
};
```
    
<hr>
<br><br>

## 26)  [Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Binary Search`

### Code


```cpp
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Get the number of distances in the vector
        int n = dist.size();
        
        // Define a lambda function to check if a given speed is good for finishing in time
        auto is_good = [&](double speed){
            double time = 0;
            // Iterate through all distances except the last one
            for(int i = 0; i < n; i++){
                // waiting for the time to become an integer
                time = ceil(time);
                
                // Calculate the time taken for each distance and add it to the total time
                time += dist[i] / speed;
            }
            
            // Check if the total time is less than or equal to the specified hour
            return time <= hour;
        };
        
        // Initialize the search space for the binary search
        int l = 1, r = 1e7, ans = -1;
        
        // Perform binary search to find the minimum speed
        while(l <= r){
            // Calculate the middle speed
            int m = l + (r - l) / 2;
            
            // Update the search space based on whether the current speed is good or not
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        
        // Return the minimum speed found
        return ans;
    }
};
```
    
<hr>
<br><br>

## 27)  [Maximum Running Time of N Computers](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`Array` `Binary Search` `Greedy` `Sorting`

### Code


```cpp
class Solution {
public:
    // Define a type alias for long long
    typedef long long ll;

    long long maxRunTime(int n, vector<int>& batteries) {
        // Define a lambda function to check if given time x is sufficient
        auto is_good = [&](ll x){
            // Initialize variables for counting computers and current power
            ll computers = 0, curr_power = 0;
            // Iterate through each battery in the sorted order
            for(auto& b : batteries){
                // Add the current battery's power to the current power
                curr_power += b;
                // If the current power is greater than or equal to x,
                // it means we can run a computer, so decrement the current power and increase the computer count.
                if(curr_power >= x)
                    curr_power -= x, computers++;
            }
            // If the number of computers that can run is greater than or equal to n, return true
            return computers >= n;
        };

        // Sort the batteries in ascending order
        sort(batteries.begin(), batteries.end());

        // Initialize variables for binary search
        ll l = 1, r = 1e18, maxTime = -1;

        // Perform binary search to find the maximum run time
        while(l <= r){
            ll m = l + (r - l) / 2;
            // If is_good returns true, update the left pointer and store the current time as the maximum time
            (is_good(m) ? l = m + 1, maxTime = m : r = m - 1);
        }

        // Return the maximum run time
        return maxTime;
    }
};
```
    
<hr>
<br><br>

## 28)  [Predict the Winner](https://leetcode.com/problems/predict-the-winner/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Array` `Math` `Dynamic Programming` `Recursion` `Game Theory`

### Code


```cpp
class Solution {
public:
    int solve(vector<vector<int>>& dp, vector<int>& nums, int l, int r) {
        // Base case: if left pointer exceeds right pointer, return 0
        if (l > r) return 0;
        
        // Reference to the current memoization cell
        int& ret = dp[l][r];
        
        // If the result has already been calculated, return it
        if (~ret) return dp[l][r];
        
        // Calculate the maximum score difference between the first and last element
        int first = nums[l] - solve(dp, nums, l + 1, r); 
        int last = nums[r] - solve(dp, nums, l, r - 1); 
        
        // Store the maximum of the two choices in the memoization cell and return it
        return ret = max(first, last);
    }

    // Function to determine if the first player can win the game or not
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        // Create a memoization table with initial values as -1
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Check if the first player's score is greater than or equal to 0 (which means they can win)
        return solve(dp, nums, 0, n - 1) >= 0;
    }
};
```
    
<hr>
<br><br>

## 29)  [Soup Servings](https://leetcode.com/problems/soup-servings/)

### Difficulty

![](https://img.shields.io/badge/Medium-orange?style=for-the-badge)

### Related Topic

`Math` `Dynamic Programming` `Probability and Statistics`

### Code


```cpp
class Solution {
public:
    // Constants for array sizes and the limit for N
    static constexpr int Sz = 200, Limit = 4800;
    
    // 2D array to store memoized values
    double memo[Sz][Sz];

    // Function to calculate the probability of providing soup servings
    double soupServings(int N) {
        // Initialize memo array with -1
        memset(memo, -1, sizeof(memo));
        
        // If N is greater than the Limit, return 1.0
        // As the probability becomes almost 1 as N increases
        return N > Limit ? 1.0 : f((N + 24) / 25, (N + 24) / 25);
    }

    double f(int a, int b) {
        // Base case: if both a and b are non-positive, return 0.5
        // As half of the probability is reached when both servings are empty
        if (a <= 0 && b <= 0) return 0.5;

        // Base case: if either a or b is non-positive, return 1 or 0 respectively
        // If one serving is empty, probability of reaching this state is 1 (empty)
        // If the other serving is empty, probability of reaching this state is 0 (impossible)
        if (a <= 0 || b <= 0) return (a <= 0);

        // Check if the result for the current state (a, b) is already memoized
        double& ret = memo[a][b];
        if (ret == ret) return ret;

        // Calculate the probability for the current state using the given recursive formula
        // Probability at the current state = 0.25 * (sum of probabilities of 4 possible transitions)
        ret = 0.25 * (f(a - 4, b) + f(a - 3, b - 1) + f(a - 2, b - 2) + f(a - 1, b - 3));

        // Return the calculated probability
        return ret;
    }
};
```
    
<hr>
<br><br>

## 30)  [Strange Printer](https://leetcode.com/problems/strange-printer/)

### Difficulty

![](https://img.shields.io/badge/Hard-red?style=for-the-badge)

### Related Topic

`String` `Dynamic Programming`

### Code


```cpp
class Solution {
public:
    // Recursive function to calculate the minimum number of turns required to print a substring
    // The function takes left index (l), right index (r), the input string (s), and a memoization 2D vector (dp)
    int min_turns(int l, int r, string &s, vector < vector < int > > &dp) {
        // If the substring contains only one character, it requires only one turn to print
        if (l == r) return 1;
        
        // Use a reference to ret to store and access the result of the current state in the memoization table
        int &ret = dp[l][r];
        
        // If the result is already calculated, return it
        if (~ret) return ret;
        
        // Initialize ret to the maximum integer value to find the minimum number of turns
        ret = INT_MAX;
        
        // Loop through all possible divisions of the substring and calculate the minimum turns required
        for (int i = l; i < r; i++)
            ret = min({ret, min_turns(l, i, s, dp) + min_turns(i + 1, r, s, dp)});
        
        // Return the minimum turns, subtracting 1 if the characters at the left and right indices are the same
        return ret -= (s[l] == s[r]);
    }
    
    int strangePrinter(string& s) {
        // Get the length of the input string
        int n = s.length();
        
        // Initialize a 2D memoization vector with -1 to store previously calculated results
        vector < vector < int > > dp(n, vector < int >(n, -1));
        
        // Call the recursive function to find the minimum turns for the whole input string
        return min_turns(0, n - 1, s, dp);
    }
};
```
    