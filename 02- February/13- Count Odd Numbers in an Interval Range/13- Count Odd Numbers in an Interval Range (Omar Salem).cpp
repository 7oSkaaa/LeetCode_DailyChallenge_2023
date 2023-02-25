//Author: Omar Salem
class Solution {
public:
    int countOdds(int low, int high) {
       //count all numbers between high , low 
       int diff = high - low;
       // count odd numbers between high , low
        int ans = diff / 2;
        // check if high or low odd number 
        if(low & 1 or high & 1)
            ans++;

        //return answer 
        return ans;
    }
};