// Author: Ahmed Gamal

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        // we can handle grid columns as strings (characters in the first position of each string form a new string)
        // we want to keep the sorted strings formed of columns characters, and delete the others
        vector<string> v(strs.front().size());

        // construct the new strings character by character
        for(auto& s : strs){
            for(int i = 0; i < s.size(); i++){
                v[i].push_back(s[i]);
            }
        }

        // count the sorted ones
        int cnt = 0;
        for(auto& s : v){
            cnt += is_sorted(s.begin(), s.end());
        }

        // delete all of the strings (columns) except for sorted ones 
        return v.size() - cnt;
    }
};