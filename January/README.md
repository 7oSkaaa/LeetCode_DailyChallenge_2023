# LeetCode Daily Challenge Problems for January

<br><br>

## 1)  Word Pattern

```cpp
class Solution {
public:

    vector < string > splitting(string& s){
        string curr;
        vector < string > ret;
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
        vector < string > words = splitting(s);
        if(words.size() != pattern.size()) return false;
        map < char, string > eq;
        map < string, char > mapping;
        for(int i = 0; i < pattern.size(); i++){
            if(eq[pattern[i]] != words[i] && !eq[pattern[i]].empty()) return false; 
            else if(mapping.count(words[i]) && mapping[words[i]] != pattern[i]) return false;
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
