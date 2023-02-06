// Author: Eslam Ezzat

// Time Complexity: O(NlogN)

// Space Complexity: O(N)

class Solution {
public:
   vector<int> findAnagrams(string s, string p) {
    vector<int> result;
    int szOfP = p.size();
    int szOfS = s.size();
    // if the size of string is greater than the size of pangram, the result is empthy.
    if(szOfP>szOfS)
    {
        return {};
    }
    // Making two frequency arrays that one of each count the string and the other count the other string (pangram)
    vector<int> fre(26, 0);
    vector<int> fre1(26, 0);
    // itearate through the size of pangram (The second string).
    for (int i = 0; i < szOfP; i++) {
        fre[s[i] - 'a']++;
        fre1[p[i] - 'a']++;
    }
    if (fre == fre1) {
        result.push_back(false);
    }
    // Using Sliding Window Techinque that it shows how a nested for loop can be converted to a single forloop and reduce the time complexity.
    for (int i = szOfP; i < szOfS; i++) {
        fre[s[i - szOfP] - 'a']--;
        fre[s[i] - 'a']++;
        if (fre == fre1) {
            result.push_back(i - szOfP + 1);
        }
    }
    return result;
}
};