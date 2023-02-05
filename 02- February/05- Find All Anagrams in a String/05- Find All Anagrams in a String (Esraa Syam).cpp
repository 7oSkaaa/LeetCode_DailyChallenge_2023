// author: Esraa Syam
class Solution {
public:
vector<int> findAnagrams(string s, string p) {
    vector < int > freq_s(26) , freq_p(26) , idx;
    int n = s.size() , m = p.size();
    if (n < m) return idx;
    for(auto & i : p) freq_p[i - 'a']++;
    int l = 0 , r = 0;
    // use sliding window
    // to iterate over all the substrings of length m in s
    // and check if they are anagrams of p
    // if yes, then push the starting index of that substring in idx
    while(r - l + 1 != m) freq_s[s[r++] - 'a']++;
    for( ; r < n ; r++) {
        // add the last character of the current window
        freq_s[s[r] - 'a']++;
        // check if the current window is an anagram of p
        if(freq_s == freq_p) idx.push_back(l);
        // remove the first character of the current window
        freq_s[s[l++] - 'a']--;
    }
    // check for the last window
    if(freq_s == freq_p) idx.push_back(l);
    return idx;
}
};