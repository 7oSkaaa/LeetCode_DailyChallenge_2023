# LeetCode Daily Challenge Problems for January

<br><br>

## Contribution

***These steps to how to make a contribution to this Repo***

- Follow the same style in the repo
    1. Fork the repo first
    1. Follow the following guidelines:
        1. Open the folder of the month of the problem
        1. Open the folder of the day of the problem
        1. **if there is no folder for one of the previous steps... please create it.**
        1. Make a file of your solution and follow this pattern `<day>- <name of problem> (<your name>).<file extension>`
            - For example `1. Word Pattern (Ahmed Hossam).cpp`
        1. Put this line as a comment on the top of your file: ``// Author: <your name>``
        1. Try to write comments to explain your solution
        1. Redundant solutions will be rejected
    1. Create pull request here after that
    1. I will pin the best solution in the README.md file to be viewed by all users.


<br><br>

## 1)  Word Pattern

```cpp
class Solution {
public:

    // splitting the string into vector of string based on spaces
    vector < string > splitting(string& s){
        string curr;
        vector < string > ret;
        // adding space in the word to split the last word
        s += ' ';
        for(auto& c : s){
            if(c != ' ') curr += c;
            else {
                if(!curr.empty())
                    ret.push_back(curr);
                curr.clear();
            }
        }
        return ret;
    }

    bool wordPattern(string pattern, string s) {
        
        // words seperated by spaces
        vector < string > words = splitting(s);
        
        // check if they are not the same size
        if(words.size() != pattern.size()) return false;

        // character mapping to word and viceversa
        map < char, string > eq;
        map < string, char > mapping;

        for(int i = 0; i < pattern.size(); i++){
            // check if they aren't mapping each other will return false
            if(eq[pattern[i]] != words[i] && !eq[pattern[i]].empty()) return false; 
            else if(mapping.count(words[i]) && mapping[words[i]] != pattern[i]) return false;
            
            // mapping them to each other
            mapping[words[i]] = pattern[i], eq[pattern[i]] = words[i];
        }
        return true;
    }
};
```

<hr>

<br><br>

## 2)  Detect Capital

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        // count capital letters
        int CapitalLetters =  count_if(word.begin(), word.end(), [&](char c){ 
            return isupper(c); 
        });
        
        // check the three conditions if there is anyone valid
        bool isCapital = false;
        isCapital |= (CapitalLetters == word.size());
        isCapital |= (CapitalLetters == 0);
        isCapital |= CapitalLetters == 1 && isupper(word.front());
        
        // return the answer
        return isCapital;
    }
};
```

<hr>

<br><br>

## 3)  Delete Column to Make Sorted

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // number of columns that aren't sorted
        int deleted_columns = 0;
        
        // dimension of the grid
        int n = strs.size(), m = strs[0].size();
        
        for(int col = 0; col < m; col++){
            
            bool is_current_column_sorted = true;
            // check if the current column is sorted or not
            
            for(int row = 1; row < n; row++)
                is_current_column_sorted &= (strs[row][col] >= strs[row - 1][col]);
            
            // add one to the answer if the current columns isn't sorted
            deleted_columns += !is_current_column_sorted;
        }
        
        // the answer of the problem
        return deleted_columns;
    }
};
```

<hr>

<br><br>

## 3)  Delete Column to Make Sorted

```cpp
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        // the frequency of each level
        unordered_map < int, int > freq;

        // make frequency array of tasks -> using map because number in range 10^9
        for(auto& task : tasks)
            freq[task]++;

        // the rounds it takes to complete the tasks
        int rounds = 0;

        // iterate over the map l -> level, f -> frequency of the level
        for(auto& [l, f] : freq){
            // if f = 1 so we can do the missions so will return -1
            if(f == 1)
                return -1;

            // rounds += ceil(f / 3)
            rounds += ((f + 2) / 3);
        }

        // the minimum rounds;
        return rounds;
    }
};
```
