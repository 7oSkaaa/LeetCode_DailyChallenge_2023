// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the minimum time to complete all trips
    // we can do this by binary search on the time
    // we can check if we can complete all trips in time m
    // by checking if the number of trips we can complete in time m is >= totalTrips
    // if it is, we can try to find a smaller time
    // if it is not, we can try to find a larger time

    // input variables
    vector<int> time;
    int totalTrips;

    // check if we can complete all trips in time m
    bool good(long long m){
        // the number of trips we can complete in time m
        int tot = 0;
         
        for(auto&i: time)
            // we can complete m / i trips in time m
            tot += m / i;

        // if the number of trips we can complete in time m is >= totalTrips we can return true
        return tot >= totalTrips;
    }

    // binary search on the time
    long long bs(){
        // boundaries
        long long l = 1, r = 1, best = -1;
        // find the right boundary
        while(!good(r)) r *= 2;
        // binary search
        while(l <= r){
            long long mid = l + (r - l) / 2;
            // if we can complete all trips in time mid, we can try to find a smaller time
            if(good(mid)) r = mid - 1, best = mid;
            // if we can not complete all trips in time mid, we can try to find a larger time
            else l = mid + 1;
        } 
        // return the minimum time to complete all trips
        return best;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        // initialize input variables
        this -> time = time;
        this -> totalTrips = totalTrips;

        // return the minimum time to complete all trips
        return bs();
    }
};
