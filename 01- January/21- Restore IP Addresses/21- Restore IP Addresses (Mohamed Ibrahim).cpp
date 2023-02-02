//Author: Mohamed Ibrahim

class Solution {
public:
bool isValid(string s) {
    // Check if the string has a length greater than 3 or is empty or starts with a 0 but has a length greater than 1 or has a value greater than 255
    if (s.length() > 3 || s.length() == 0 || (s[0] == '0' && s.length() > 1) || stoi(s) > 255) {
        return false;
    }
    return true;    
 }
    vector<string> restoreIpAddresses(string s) {
    // Initialize an empty vector to store the valid IP addresses
    vector<string> res;
    // Three nested loops to generate all possible combinations of 3 dots
    for (int i = 1; i < 4 && i < s.length(); i++) {
        for (int j = i + 1; j < i + 4 && j < s.length(); j++) {
            for (int k = j + 1; k < j + 4 && k < s.length(); k++) {
                // Divide the input string into 4 parts using the substr function
                string s1 = s.substr(0, i), s2 = s.substr(i, j - i), s3 = s.substr(j, k - j), s4 = s.substr(k);

                // Check if all four parts are valid integers between 0 and 255
                if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                    // Concatenate the parts with dots and add the IP address to the output vector
                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                }
            }
        }
    }
    return res;
 }

};