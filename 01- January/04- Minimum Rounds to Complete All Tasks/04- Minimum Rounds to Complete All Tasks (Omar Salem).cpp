// Author : Omar Salem
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0 ;
        map < int , int > freq;
        for(auto &i:tasks)
            freq[i]++; // count frequance  of tasks
        for(auto &[f,s] : freq)
            if(s < 2) // if min freq < 2 then return -1;
                return -1;// The minimum iteration should be 2 or more
            else
                ans += (s / 3) + (s % 3 != 0);
        return ans ;
    }
};