// Author: Mohamed Ashraf

class Solution {
public:
    // This solution is based on (Binary Search on Answer)
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1, right = 100000000000005, ans = -1, curr = 0;
        while(left <= right){
            long long mid = left + (right - left) / 2;
            // check the current time
            for(auto i : time)
                curr += mid / i;

            // if current time is suitable  -> Check for less answer
            //            else              -> Check for greater answer
            (curr >= totalTrips) ? right = mid - 1, ans = mid : left = mid + 1;
            curr = 0;
        }
        
        return ans;
    }
};
