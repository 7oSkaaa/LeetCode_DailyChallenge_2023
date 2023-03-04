// Author: Mahmoud Aboelsoud

class Solution {
public:
    int strStr(string haystack, string needle) {
        // we use sliding window technique to solve this problem
        // we use two maps to store the frequency of each character in the needle and the current window of the haystack
        // we use two pointers to keep track of the current window
        // we move the right pointer until the window size is equal to the needle size
        // then we check if the two maps are equal, if they are equal then we check if the current window is equal to the needle
        // if they are equal then we return the left pointer
        // if they are not equal then we move the left pointer to the right and remove the character at the left pointer from the map
        // we repeat the process until the right pointer reaches the end of the haystack
        // if we didn't find the needle then we return -1



        // store the size of the needle
        int sz = needle.size();
        
        // the two maps to store the frequency of each character in the needle and the current window of the haystack
        map<char,int> ma1, ma2;
        
        // store the frequency of each character in the needle
        for(auto&i: needle) ma1[i]++;
        
        int l = 0;
        // loop over the haystack
        for(int i = 0; i < haystack.size(); i++){
            // add the current character to the map
            ma2[haystack[i]]++;

            // if the window size is bigger than the needle size then we move the left pointer to the right
            if(i - l + 1 > sz){
                // remove the character at the left pointer from the map
                ma2[haystack[l]]--;
                // if the frequency of the character at the left pointer is 0 then we remove it from the map
                if(ma2[haystack[l]] == 0) ma2.erase(haystack[l++]);
            }

            // if the two maps are equal then we check if the current window is equal to the needle
            if(ma1 == ma2)
                if(haystack.substr(l, sz) == needle) return l;   
        }
        // if we didn't find the needle then we return -1
        return -1;
    }
};
