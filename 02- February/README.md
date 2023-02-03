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
    string convert(string& s, int n) {
        // if n == 1 there is no change will be
        if(n == 1) return s;

        // vector of string for each row to add the characters
        vector < string > grid(n);

        // r -> index for current row, idx current char of the string
        int r = 0, idx = 0, sz = s.size();
        while(idx < sz){
            // iterate to fill the column down 
            while(idx < sz && r < n) grid[r++] += s[idx++];
            r--;
            // iterate fo fill up the rows except the first and last one
            while(idx < sz && r > 0) grid[--r] += s[idx++];
            r++;
        }

        // the result string will be the concatenation of the all rows
        string conv;
        for(auto& str : grid)
            conv += str;
        return conv;
    }
};
```
