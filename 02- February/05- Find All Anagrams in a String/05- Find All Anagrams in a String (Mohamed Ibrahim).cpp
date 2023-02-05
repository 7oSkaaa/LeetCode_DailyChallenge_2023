//Author: Mohamed Ibrahim

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    // create a vector to store the start indices of p's anagrams in s
    vector<int> ans;
    // create two vectors to store the count of each letter in p and the count of each letter in the current window in s
    vector<int> pv(26), sv(26);
    // if the length of s is less than the length of p, return an empty vector
    if (s.size() < p.size()) return ans;
    // loop through the first window in s and count the letters
    for (int i = 0; i < p.size(); ++i) {
        ++pv[p[i] - 'a'];
        ++sv[s[i] - 'a'];
    }
    // if the count of letters in the first window is the same as the count of letters in p, add 0 to the result vector
    if (pv == sv) ans.push_back(0);
    // loop through the rest of the windows in s
    for (int i = p.size(); i < s.size(); ++i) {
        // move the window in s and update the count of letters
        ++sv[s[i] - 'a'];
        --sv[s[i - p.size()] - 'a'];
        // if the count of letters in the current window is the same as the count of letters in p, add the start index of the current window to the result vector
        if (pv == sv) ans.push_back(i - p.size() + 1);
    }
    // return the result vector
    return ans; 
    }
};