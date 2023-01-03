// Author: Ahmed Gamal

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // actually, we don't need to store the whole string (if we decided to check the column as a string)
        // we just need to remember the last character and check if the order of the current and previous characters violates what we want
        
        vector<char> last(strs.front().size(), char(int('a') - 1)); // to store the last character
        vector<bool> ok(strs.front().size(), true); // to check if this column is good or not

        int cnt = 0;
        for(auto& s : strs){
            for(int i = 0; i < s.size(); i++){
                if(s[i] < last[i] and ok[i]){ // if the current and previous characters are not in non-decreasing order
                    ok[i] = false;
                    cnt++;
                }
                last[i] = s[i]; // we set the last character in the column until now
            }
        }

        return cnt;
    }
};