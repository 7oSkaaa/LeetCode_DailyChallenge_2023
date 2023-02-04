// Author: Eileanora

class Solution {
public:

/* we will use sliding window technique
    first we map the freq of charachters in string a to make it easier to track it's possible permutations
    then we will use two pointers l and r to make the window
    we have 3 cases
    1- if the charachter at r is not in the map then the entire substring is invalid so we will move l , r to the next charachter  and reset the map
    2- if the charachter at r is in the map but it's freq is 0 
        here we will discard the char at l and move l to the next char
        add it back to the map
        check again if the frequency of the character at r is still 0
        this loop withh go on until the frequency of the charachter at r (possible at l == r) so we make a new window
    3- if the charachter at r is in the map and it's freq is not 0 we operate normally and increase the window

    if the window size is equal to the size of string a then we have found a permutation
*/
    bool checkInclusion(string a, string b) {

        map <char , int> freq_a , save;
        for(auto i : a)
            freq_a[i]++;
        save = freq_a;  // save the freq of a to reset it later
        int sz = b.size();
        int l = 0 , r = 0;
        while(r < sz)
        {
            bool flag = false;
            while(r < sz && freq_a.find(b[r]) == freq_a.end())  // case 1
            {
                l = ++r; 
                flag = true;
            }
            if(flag)  // if we moved l and r to the next charachter then we need to reset the map
                freq_a = save;

            while(freq_a[b[r]] == 0)  // case 2
            {
                freq_a[b[l++]]++;
            }
            freq_a[b[r]]--;
            r++;
            if(r - l == int(a.size()))  // case 3
                return true;
        }
        return false;
    }
};