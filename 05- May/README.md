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
    