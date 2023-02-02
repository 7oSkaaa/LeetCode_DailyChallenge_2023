// Author: Eileanora

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map <int , int> freq;   //map to check how many times there is a task of each difficulty
        for(auto& i : tasks)
            freq[i]++; 

        int ans = 0; 
        for(auto& [f , s] : freq)
        {
            // if there is only one task of the same diffculty we cant divide it into 2 or 3 groups
            if(s == 1)
                return -1;

            //otherwise it can be proven that we always can divide it in groups of 2 , 3 or a mix of them
            ans += (s / 3);
            ans += (s % 3 == 0? 0 : 1);     //4 -> (2 , 2) which is also (3 , 1) -> same number of groups so it doesnt matter
        }
        return ans;
    }
};