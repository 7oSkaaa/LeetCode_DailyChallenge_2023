// Author: Mahmoud Aboelsoud

class Solution {
public:
    // using binary search on the answer you can find the minimum capacity that can ship all the packages in D days
    // the input vector is sorted so we can use binary search on the answer
    
    // the vector of weights which is given in the problem
    vector<int> weights;
    // the number of days which is given in the problem
    int days;

    // this function checks if the capacity m can ship all the packages in how many days
    bool good(int m){
        // the number of days that we need to ship all the packages
        int d = 1, sum = 0;
        // iterate over the weights
        for(auto&i: weights){
            // if the current weight is greater than the capacity then we can't ship it using this capacity so return false
            if(i > m) return 0;
            // if the current weight is greater than the remaining capacity then we need to ship the current weight in the next day
            if(sum + i > m)
                // increase the number of days and reset the sum to the current weight
                d++, sum = i;
            // else add the current weight to the sum
            else sum += i;
        }
        // return true if the number of days is less than or equal to the given number of days
        return d <= days;
    }

    // binary search on the answer to find the minimum capacity that can ship all the packages in D days
    int bs(){
        // the left and right of the binary search and the best answer
        int l = 0, r = 1, best = -1;
        // find the right of the binary search
        while(!good(r)) r *= 2;
        // binary search
        while(l <= r){
            // the mid of the binary search
            int m = l + (r - l) / 2;
            // if the capacity m can ship all the packages in at most D days then we can try to find a smaller capacity
            if(good(m)) r = m - 1, best = m;
            // else we need to increase the capacity
            else l = m + 1;
        }

        // return the best answer which is the minimum capacity that can ship all the packages in at most D days
        return best;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // initialize the weights and days
        this -> weights = weights;
        this -> days = days;

        // return the answer
        return bs();
    }
};
