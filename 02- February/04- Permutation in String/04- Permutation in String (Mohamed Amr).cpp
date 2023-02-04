// Author: Mohamed Amr
// Topic: sliding window, frequency array
class Solution {
public:

    // function that compares two maps, each map represents a frequency array.
    bool equal(unordered_map<char,int>&first, unordered_map<char,int>&second){
        for(char c='a'; c<='z'; c++){
            if(first[c]!=second[c])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        // first string is bigger than second string, it is impossible to include all the first in the second.
        if(s1.size()>s2.size())
            return false;

        // carrys the count of each character in the first string
        unordered_map<char,int>first;
        for(auto& c: s1)
            first[c]++;

        // carrys the count of each character in the initial window (windows size = s1.size())
        unordered_map<char,int>second;
        for(int i=0; i<s1.size(); i++)
            second[s2[i]]++;

        // check if the initial window frequency is equal to the first string (s1)
        if(equal(first, second))
            return true;

        // slide the window till we reach the end of s2, updating the second map with each step (adding the next element, and removing the very first element of the previous window)
        for(int i=s1.size(); i<s2.size(); i++)
        {
            second[s2[i]]++;                // add new element to the window
            second[s2[i-s1.size()]]--;      // remove the very first element of the old window

            if(equal(first, second))        // check if window freq == first string freq
                return true;        
        }
        return false;
    }
};