// Author: Ahmed Hossam

class Solution {
public:
    string mergeAlternately(const string& s, const string& t) {
        // Initialize indices and sizes of s and t
        int i = 0, j = 0, n = s.size(), m = t.size();
        
        // Initialize the merged string
        string merged;
        
        // Merge s and t alternately while there are still characters in both strings
        while(i < n && j < m) {
            merged += s[i++];
            merged += t[j++];
        }

        // If there are still characters in s, add them to the merged string
        while(i < n)
            merged += s[i++];

        // If there are still characters in t, add them to the merged string
        while(j < m)
            merged += t[j++];

        // Return the merged string
        return merged;
    }

};
