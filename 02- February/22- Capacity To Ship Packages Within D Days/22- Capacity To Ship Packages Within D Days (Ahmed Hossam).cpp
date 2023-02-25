// Author: Ahmed Hossam

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {

        // functions is_good to check the current capacity
        auto is_good = [&](int max_cap){
            // days to ship all weights and the current capacity
            int days_to_use = 1, curr_cap = 0;
            for(auto& w : weights){
                // if any wieght is greater than max_cap this max_cap isn't good
                if(w > max_cap) return false;

                // add current weight to current cap
                curr_cap += w;

                // if the current cap is greater than max_cap we will use another day to ship it
                if(curr_cap > max_cap)
                    curr_cap = w, days_to_use++;
            }

            // current_max_cap will be good if the number of days to move all weights smaller than number of allowed days
            return days_to_use <= days;
        };

        // we will make binary search to get the maximum capacity
        int l = 1, r = 1e9, ans = -1;
        while(l <= r){
            int m = l + (r - l) / 2;
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        // the answer will be the minimum good capacity to use
        return ans;
    }
};
