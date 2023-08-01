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
    
