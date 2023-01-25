// Author: Eslam Ezzat

// Time Complexity: O(pattern.length * log(pattern.length))

// Space Complexity: O(pattern.length)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Vector is used to store the strings to iterate through it.
        vector <string> sto;

        // Mapping between char and string.
        map<char, string> fre;

        // Mapping is used to check if the string was taken by specific character or not.
        map<string, int> q;

        // Variable is used to store every string separately
        string z = "";

        // Iterate through string
        for (auto &i: s) {
            if (i != ' ') {
                z += i;
            } else {
                sto.push_back(z);
                z = "";
            }
        }
        sto.push_back(z);

        int sz = pattern.size(); // Get the size of pattern

        // iterate through the pattern and vector which include strings
        for (int i = 0; i < sz; i++) {

            // check if the character exists in the map or not.
            if (fre.find(pattern[i]) != fre.end()) {
                if (fre[pattern[i]] != sto[i]) {
                    return false;
                }
            } else {
                if (!q[sto[i]]) {
                    fre[pattern[i]] = sto[i]; // store every character to the opposite every string.
                    q[sto[i]]++; // count the string which is taken by character.
                } else
                    return false;
            }
        }
        return true;
    }
};