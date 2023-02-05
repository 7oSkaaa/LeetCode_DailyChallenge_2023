//Author: Sara Hamza
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), m = s.size();

        if(m < n) return vector<int>();

        vector<int> ans;
        //freq -> for p
        //freq2 -> for s
        //freq to mark letters in the string regardless the order
        int freq[26] = {0}, freq2[26] = {0};
        //building freq of p
        for(int i = 0; i < n; ++i) freq[p[i]-'a']++;

        //building the freq of the first sliding window of s except for the last letter
        int i = 0;
        for(; i < n-1; ++i) freq2[s[i]-'a']++;

        for(; i < m; ++i) {
            //add the last letter of the sliding window to the freq
             freq2[s[i]-'a']++;

            //anagram check -> if both freqs are equal
             int flag = 0;
             for(int j = 0; j < 26; ++ j){
                 if(freq[j] != freq2[j]){
                     flag = 1;
                     break;
                 }
             }
             //anagram case? append the 1st index of the sliding window
             if(!flag) ans.push_back(i - n + 1);

            //remove the first letter of the sliding window from the freq
             freq2[s[i - n + 1]-'a']--;


        }
        return ans;

    }
};
