// Author: Ahmed Hossam

class Solution {
public:

    // return the ceiling of the division between a and b 
    inline int ceil(const int& a, const int& b){
        return (a + b - 1) / b;
    }

    int minEatingSpeed(vector<int>& piles, int& h) {
        auto is_good = [&](int k){
            int total_hours = 0;
            /*
                loop over the piles and calculate the total hours needed to eat
                all the bananas such that each hour you will eat number of bananas <= k
            */
            for(auto& p : piles){
                total_hours += ceil(p, k);
                if(total_hours > h)
                    return false;
            }
            
            // if the number of hours less than h so k is valid choice
            return total_hours <= h;
        };

        // make binary search to get the least valid choice
        int l = 1, r = 1, k = -1;

        // make r less power of 2 valid number
        while(!is_good(r)) r *= 2;

        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? r = m - 1, k = m : l = m + 1);
        }

        // the minimum valid k
        return k;
    }
};
