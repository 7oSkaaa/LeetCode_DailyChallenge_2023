// Author: Eslam Ezzat

// Time Complexity: O(N)

// Space Complexity: O(1)



class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if two strings is equal or not.
        if(str1+str2!=str2+str1)
        {
            return "";
        }
        // Check if two strings is equal.
        else if(str1==str2)
        {
            return str1;
        }
        // If the size of str1 is greater than the size of str2
        else if(str1.size()>str2.size())
        {
            // recursive the substr of the size of str2 and str2
            return gcdOfStrings(str1.substr(str2.length()), str2);
        }
        else {
            // Ifthe size of str2 is less than the size of str1
            // Recursive the substr of the size of str1 and str1
            return gcdOfStrings(str2.substr(str1.length()), str1);
        }
    }
};