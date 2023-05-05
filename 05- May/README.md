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
    
