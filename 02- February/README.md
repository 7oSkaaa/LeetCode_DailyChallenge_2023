# LeetCode Daily Challenge Problems for January

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

1. **[Greatest Common Divisor of Strings](#1--greatest-common-divisor-of-strings)**
1. **[Verifying an Alien Dictionary](#2--verifying-an-alien-dictionary)**
1. **[Zigzag Conversion](#3--zigzag-conversion)**
1. **[Permutation in String](#4--permutation-in-string)**
1. **[Find All Anagrams in a String](#5--find-all-anagrams-in-a-string)**
1. **[Shuffle the Array](#6--shuffle-the-array)**

<hr>

<br><br>

## 1)  [Greatest Common Divisor of Strings](https://leetcode.com/problems/greatest-common-divisor-of-strings/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String` `Math`

### Code


```cpp
class Solution {
public:

    /*
        str1 = mGCD, str2 = nGCD, str1 + str2 = (m + n) x GCD = str2 + str1
    */
    
    string gcdOfStrings(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        return (s1 + s2 == s2 + s1 ? s2.substr(0, __gcd(n, m)) : "");
    }
};
```

<hr>

<br><br>

## 2)  [Verifying an Alien Dictionary](https://leetcode.com/problems/verifying-an-alien-dictionary/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`String` `Array`  `Hash Table`

### Code

```cpp
class Solution {
public:
    
    // to save the ordered of each charachter
    vector < int >  ord;
    
    bool isSmaller(string& a, string& b){

        // loop for the minimum size between them
        for(int i = 0; i < min(a.size(), b.size()); i++){
            // if the ordered of the char of the first word is smaller than the right word so return false
            // if the ordered of the char of the first word is bigger than the right word so return true
            // if they are the same skip this character
            if(ord[a[i] - 'a'] < ord[b[i] - 'a']) 
                return false;
            else if(ord[a[i] - 'a'] > ord[b[i] - 'a']) 
                return true;
        }

        // if the all character are same so return if the left word size greatet than or equal
        return a.size() >= b.size();
    }

    bool isAlienSorted(vector<string>& words, string& order) {
        ord = vector < int > (26);
        
        // assign each character with its order
        for(int i = 0; i < order.size(); i++)
            ord[order[i] - 'a'] = i + 1;

        // compare each two consecutive words if the left word is smaller than right word
        for(int i = 1; i < words.size(); i++)
            if(!isSmaller(words[i], words[i - 1])) 
                return false;
        
        return true;
    }
};
```

<hr>

<br><br>

## 3)  [Zigzag Conversion](https://leetcode.com/problems/zigzag-conversion/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`String`

### Code


```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        // If the number of rows is 1, the pattern will be a straight line,
        // so we can simply return the original string
        if (numRows == 1) return s;

        // Create a vector of strings, where each element represents a row
        vector<string> rows(min(numRows, int(s.size())));

        // curRow keeps track of the current row we are on
        int curRow = 0;
        // goingDown indicates the direction we are moving (up or down)
        bool goingDown = false;

        // For each character in the input string,
        for (char c : s) {
            // add the character to the current row
            rows[curRow] += c;
            // If we have reached the top or bottom row, change direction
            if (curRow == 0 || curRow == numRows - 1) goingDown = !goingDown;
            // Update the current row
            curRow += goingDown ? 1 : -1;
        }

        // Combine all the rows into a single string
        string res;
        for (string row : rows) res += row;
        return res;
    }
};
```
<hr>

<br><br>

## 4)  [Permutation in String](https://leetcode.com/problems/permutation-in-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `Two Pointers` `String` `Sliding Window`

### Code


```cpp
class Solution {
public:

    // function that compares two maps, each map represents a frequency array.
    bool equal(unordered_map<char,int>&first, unordered_map<char,int>&second){
        for(char c='a'; c<='z'; c++){
            if(first[c]!=second[c])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // first string is bigger than second string, it is impossible to include all the first in the second.
        if(s1.size()>s2.size())
            return false;

        // carrys the count of each character in the first string
        unordered_map<char,int>first;
        for(auto& c: s1)
            first[c]++;

        // carrys the count of each character in the initial window (windows size = s1.size())
        unordered_map<char,int>second;
        for(int i=0; i<s1.size(); i++)
            second[s2[i]]++;

        // check if the initial window frequency is equal to the first string (s1)
        if(equal(first, second))
            return true;

        // slide the window till we reach the end of s2, updating the second map with each step (adding the next element, and removing the very first element of the previous window)
        for(int i=s1.size(); i<s2.size(); i++)
        {
            second[s2[i]]++;                // add new element to the window
            second[s2[i-s1.size()]]--;      // remove the very first element of the old window

            if(equal(first, second))        // check if window freq == first string freq
                return true;        
        }
        return false;
    }
};

```
<hr>

<br><br>

## 5)  [Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

### Difficulty

**${\bf{\color\{orange}\{Medium}}}$**

### Related Topic

`Hash Table` `String` `Sliding Window`

### Code


```cpp
class Solution {
public:
    vector<int> findAnagrams(string& s, string& p) {
        // make frequency for string s and string p
        vector < int > freq_s(26), freq_p(26);

        // add all character in string p to the frequency
        for(auto& c : p) freq_p[c - 'a']++;

        // store the indices of the start of the angrams
        vector < int > ans;

        int l = 0, r = 0;
        while(r < s.size()){
            // while r - l smaller than p we will add new characters to the current frequency
            while(r < s.size() && r - l < p.size()) freq_s[s[r++] - 'a']++;
            
            // if the two frequencies are the same so the current window will be an angram 
            if(freq_s == freq_p) ans.push_back(l);

            // remove the current character
            freq_s[s[l++] - 'a']--;
        }

        // the indices of the start of the angrams
        return ans;
    }
};
```

<hr>

<br><br>

## 6)  [Shuffle the Array](https://leetcode.com/problems/shuffle-the-array/)

### Difficulty

**${\bf{\color\{green}\{Easy}}}$**

### Related Topic

`Array`

### Code


```cpp
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // the shuffled vector 
        vector < int > shuffled_vec;

        // we will devide the vector into two halves and add one element from first one and one element from second one
        for(int i = 0, j = n; i < n; i++, j++)
            shuffled_vec.push_back(nums[i]), shuffled_vec.push_back(nums[j]);

        // the resulted vector
        return shuffled_vec;
    }
};
```
