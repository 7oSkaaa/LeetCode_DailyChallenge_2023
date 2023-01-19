//Author: Mohamed Ibrahim

class Solution {
public:
// This function returns the smallest equivalent string of the base string using the mapping of characters in s1 and s2.
string smallestEquivalentString(string s1, string s2, string baseStr) {
// Initializing an empty string to store the final result
    string ans= "";
// Creating an array to store the mapping of characters
    char c[26];
// Initializing the array with the lowercase alphabets
    for(int i=0;i<26;i++){
        c[i] = i+'a';
    }
// Iterating through the characters of s1 and s2 and updating the mapping in the array
    for(int i=0;i<s1.size();i++){
    char replace = max(c[s1[i] - 'a'],c[s2[i] - 'a']);
    char put = min(c[s1[i] - 'a'],c[s2[i] - 'a']);
    for(int i=0;i<26;i++){
        if(c[i] == replace)
            c[i] = put;
        }
    }
// Iterating through the characters of baseStr and updating the final result with the mapped characters
    for(int i=0;i<baseStr.size();i++){
        ans += c[baseStr[i] - 'a'];
    }
// Returning the final result
    return ans;
    }
};