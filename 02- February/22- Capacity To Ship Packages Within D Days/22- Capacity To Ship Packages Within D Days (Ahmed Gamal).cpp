// Author: Ahmed Gamal

// we want to find the minimum weight capacity of the ship to ship all the packages in D days
// if we looked at the range that the answer can be in, we can see that it is between the maximum weight of the packages and the sum of all the weights
// and if we looked from a closer view, we can see that this range is sorted by default 
// we can't have a weight capacity that is less than the maximum weight of the packages (because we can't ship a package with a weight greater than the capacity of the ship)
// and we can't have a weight capacity that is greater than the sum of all the weights (because the minimum number of days we would wish to have is one day (we can ship all the packages in one day) and this will not require a weight capacity greater than the sum of all the weights)
// so we can use binary search to find the minimum weight capacity that can ship all the packages in D days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // left: the first invalid answer (the maximum weight of the packages - 1)
        // right: the last valid answer (the sum of all the weights) with some additional space (1e9)
        int left = *max_element(weights.begin(), weights.end()) - 1, right = int(1e9);


        // this function checks if we can ship all the packages in D days with a weight capacity of w
        auto good = [&](int w){
            // cnt: the number of days we have used so far
            // curr: the current weight we have shipped in the current day
            int cnt = 0, curr = 0;

            // we iterate over all the packages
            for(auto& i : weights){
                // if the current weight we have shipped in the current day + the weight of the current package is greater than the weight capacity of the ship
                // then we need to ship the current package in a new day
                if(curr + i > w){
                    // we increase the number of days we have used so far by one
                    cnt++;

                    // we start shipping the current package in a new day
                    curr = i;
                }else{
                    // we can ship the current package in the current day
                    curr += i;
                }
            }
            
            // we return if we can ship all the packages in D days with a weight capacity of w
            // notice that we add (curr > 0) to the number of days we have used so far because we may have used the current day to ship some packages that didn't exceed the weight capacity of the ship
            return cnt + (curr > 0) <= days;
        };

        // basid binary search
        while(left < right - 1){
            int mid = left - (left - right) / 2;

            if(good(mid))
                right = mid;
            else
                left = mid;
        }

        //                                      l r
        // we return the first valid answer (0000(1)111)
        return right;
    }
};