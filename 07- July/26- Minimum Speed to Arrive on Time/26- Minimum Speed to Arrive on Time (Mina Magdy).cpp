// Author: Mina Magdy

class Solution {
public:
    // Function to find the minimum speed needed to complete the journey on time
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l = 1, r = 1e7; // Initialize left and right pointers for binary search
        // Lambda function 'good' to check if the given speed is sufficient to complete the journey on time
        auto good = [&](int speed) {
            double hours_taken = 0; // Initialize the total hours taken to complete the journey
            // Loop over all the distances in 'dist'
            for (auto& d : dist) {
                hours_taken = ceil(hours_taken); // Round up the hours taken to reach the next destination
                hours_taken += double(d) / speed; // Calculate the additional hours taken to reach the next destination at the given speed
            }
            return hours_taken <= hour; // Return 'true' if the total hours taken is less than or equal to the given 'hour'
        };
        int best = -1; // Initialize the variable 'best' to store the best speed found so far
        // Perform binary search to find the minimum speed needed
        while (l <= r) {
            int mid = l + (r - l) / 2; // Calculate the mid point of the current range
            // If the speed 'mid' is sufficient to complete the journey on time,
            // update 'best' and adjust the right pointer 'r' to find a lower speed
            (good(mid) ? r = mid - 1, best = mid : l = mid + 1);
        }
        return best; // Return the minimum speed needed to complete the journey on time
    }
};
