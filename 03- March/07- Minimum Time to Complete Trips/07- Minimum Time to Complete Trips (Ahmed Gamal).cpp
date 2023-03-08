// Author: Ahmed Gamal

// for this problem, we can use binary search to to implement what it asked for
// why binary search? because we want to find the minimum x (any value of time) that satisfies the condition (number of complete trips >= totalTrips)
// if we look at the search space, we can see that if we have a number x, which is not enough to complete totalTrips trips, then we can say that all numbers less than x are not enough to complete totalTrips trips (because less time will decrease the number of complete trips)
// and if we have a number x, which is enough to complete totalTrips trips, then we can say that all numbers greater than x are enough to complete totalTrips trips (because more time will increase the number of complete trips)

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        // if we have a number x, we can find the number of complete trips by dividing the number of hours in each trip by x and rounding down (floor)
        auto good = [&](long long mid) -> bool {
            // cnt: number of complete trips
            long long cnt = 0;
            for(auto& i : time){
                // divide the number of hours in each trip by x and round down (floor)
                cnt += mid / i;
            }

            // return true if the number of complete trips is greater than or equal to totalTrips
            return cnt >= totalTrips;
        };
        
        // left: the greatest x that does not satisfy the condition (number of complete trips >= totalTrips)
        // right: the smallest x that satisfies the condition (number of complete trips >= totalTrips)
        long long left = 0, right = 1;

        // because we are not sure about the suitable value of right, we can start with a small number and double it until we get a large enough number that is not valid (or valid depending on the problem)
        // this loop will run at most log2(max_answer) times
        // this also is a good way to avoid overflow
        while(not good(right))
            right <<= 1;
        

        while(left < right - 1){
            long long mid = left - (left - right) / 2;

            if(good(mid))
                right = mid;
            else
                left = mid;
        }

        return right;
    }
};