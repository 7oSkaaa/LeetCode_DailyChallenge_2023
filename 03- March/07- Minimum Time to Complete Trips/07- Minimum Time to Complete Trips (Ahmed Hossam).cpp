// Author: Ahmed Hossam

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // check the current time
        auto is_good = [&](long long t){
            // to store number of trips can make with this time
            long long ach_trips = 0;
            for(auto& bus : time)
                ach_trips += t / bus;
            // if the number of trips greater than totalTrips so it's good time
            return ach_trips >= totalTrips;
        };
        
        // search for the minimum time to make total trips with buses
        long long l = 1, r = 1, min_time = -1;

        // to get best r
        while(!is_good(r)) r *= 2;

        while(l <= r){
            long long m = l + (r - l) / 2;
            // if the time m can acheive so try number less than it to achieve best time
            (is_good(m) ? r = m - 1, min_time = m : l = m + 1);
        }

        // the minimum time for all buses to complete totalTrips
        return min_time;
    }
};
