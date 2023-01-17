//Author: Omar Salem
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_one = 0 , ans = 0;
        for(auto &i : s){
            if(i == '1')  
                count_one++;
            else{
                ans++; //count flip 
                ans = min(ans, count_one);
            }
        }
        return ans;
    }
};