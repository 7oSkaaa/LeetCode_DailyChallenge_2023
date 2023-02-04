// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // we need to check if we can find a premutation of s1 in s2
        // so we use a sliding window of size s1.size() and check if the chars in the window are the same as s1
        // we can use a map to count the chars in s1 and the chars in the window
        // if the map of the window is the same as the map of s1 then we found a premutation of s1 in s2
        // if the map of the window is not the same as the map of s1 then we need to move the window to the right
        

        // initalizing the map of s1 and the map of the window
        map<char,int> ma_s1, ma_s2;

        // counting the chars in s1
        for(auto&i: s1) ma_s1[i]++;

        // the left pointer of the window
        int l = 0;

        // looping over s2
        for(int i = 0; i < s2.size(); i++){
            // adding the current char to the map of the window
            ma_s2[s2[i]]++;

            // if the current char is not in s1 then we need to check the windows string form the next char
            if(ma_s1.count(s2[i]) == 0)
                // clearing the map of the window and setting the left pointer to the next char
                ma_s2.clear(), l = i + 1;

            // if the size of the window is equal to the size of s1 then we need to check if the map of the window is the same as the map of s1
            // else we need to move the window to the right
            if(i - l + 1 == s1.size()){
                // if the map of the window is the same as the map of s1 then we found a premutation of s1 in s2 so we return true
                if(ma_s2 == ma_s1) return 1;
                // else we need to move the window to the right
                // so we need to remove the left char from the map of the window
                // and increment the left pointer
                else ma_s2[s2[l++]]--;
            }
        }
        // if we didn't find a premutation of s1 in s2 then we return false
        return 0;
    }
};
