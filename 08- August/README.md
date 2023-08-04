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
    