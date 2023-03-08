// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum speed that koko can eat all bananas in h hours
    // so we can binary search on the speed and check if it is possible to eat all bananas in h hours
    // if it is possible we will try to find a smaller speed that can also eat all bananas in h hours
    // if it is not possible we will try to find a larger speed that can eat all bananas in h hours
    // we can check if it is possible to eat all bananas in h hours by counting the number of hours it will take to eat all bananas

    // input variables
    int h;
    vector<int> piles;

    // check if it is possible to eat all bananas in h hours with speed m
    bool good(int m){
        // count the number of hours it will take to eat all bananas
        long long cnt = 0;
        
        // loop over piles and count the number of hours to eat all bananas in each with speed m
        for(auto&i: piles)
            cnt += ceil(double (i) / m);

        // return if it is possible to eat all bananas in h hours with speed m
        return cnt <= h;
    }
    
    // binary search on the speed
    int bs(){
        int l = 1, r = 1, best = -1;
        // find the right bound
        while(!good(r)) r *= 2;

        // bs
        while(l <= r){
            int m = l + (r - l) / 2;
            // if it is possible to eat all bananas in h hours with speed m we will try to find a smaller speed that can also eat all bananas in h hours
            if(good(m)) r = m - 1, best = m;
            // if it is not possible we will try to find a larger speed that can eat all bananas in h hours
            else l = m + 1;
        }

        // return the answer
        return best;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        this -> piles = piles;
        this -> h = h;

        return bs();
    }
};
