// Author: Ahmed Gamal

class Solution {
public:

    // we want to split the string into 4 parts such that each part is a valid number (0 <= num <= 255)
    // since we have 4 parts, we can use only 3 dots to separate them
    // we can use backtracking to try all possible combinations since the number of combinations is small


    // we will use a string tmp to store the current combination
    // we will use a vector<string> ans to store all valid combinations
    vector<string> ans;
    string s, tmp;
    
    // add a string to tmp and return true if we added a dot before it
    bool add(string& str){
        bool dot = not tmp.empty();
        tmp += (dot ? "." : "") + str;
        return dot;
    }

    // remove a string from tmp
    void remove(string& str, bool dot){
        tmp.erase(tmp.size() - str.size() - dot, str.size() + dot);
    }

    // check if a string is a valid number
    bool valid(string& str){
        if(str.empty())
            return true;
        if(str.front() == '0' and str.size() > 1)
            return false;
        int val = stoi(str);
        return val >= 0 and val <= 255;
    }

    // idx is the current index in s
    // cnt is the number of dots we have added to tmp
    // curr is the current string we are trying to add to tmp
    void rec(int idx, int cnt, string curr){
        // if the current string is not valid, we can't add it to tmp
        if(not valid(curr))
            return;
        
        // if we reached the end of s, we can add the current string to tmp
        // if tmp is a valid combination, we add it to ans
        if(idx >= int(s.size())){
            // add the last string to tmp
            bool dot = add(curr);

            // if tmp is a valid combination, add it to ans
            if(tmp.size() == s.size() + 3)
                ans.emplace_back(tmp);

            // remove the last string from tmp before returning to the previous call in the stack
            return void(remove(curr, dot));
        }

        // if we have less than 3 dots, we can add a dot before the current string (if it's not empty) and create a new part
        if(cnt < 3 and not curr.empty() and valid(curr)){
            bool dot = add(curr);
            // start a new part
            rec(idx + 1, cnt + dot, string(1, s[idx]));
            remove(curr, dot);
        }

        // add the current character to the current string and continue constructing it
        rec(idx + 1, cnt, curr + s[idx]);
    }

    vector<string> restoreIpAddresses(string s) {
        this -> s = s;
        tmp.clear();
        rec(0, 0, "");

        return ans;
    }
};