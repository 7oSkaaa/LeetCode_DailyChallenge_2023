// Author: Ahmed Hossam

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
