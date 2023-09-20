// Author: Ahmed Hossam

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Get the number of distances in the vector
        int n = dist.size();
        
        // Define a lambda function to check if a given speed is good for finishing in time
        auto is_good = [&](double speed){
            double time = 0;
            // Iterate through all distances except the last one
            for(int i = 0; i < n; i++){
                // waiting for the time to become an integer
                time = ceil(time);
                
                // Calculate the time taken for each distance and add it to the total time
                time += dist[i] / speed;
            }
            
            // Check if the total time is less than or equal to the specified hour
            return time <= hour;
        };
        
        // Initialize the search space for the binary search
        int l = 1, r = 1e7, ans = -1;
        
        // Perform binary search to find the minimum speed
        while(l <= r){
            // Calculate the middle speed
            int m = l + (r - l) / 2;
            
            // Update the search space based on whether the current speed is good or not
            (is_good(m) ? r = m - 1, ans = m : l = m + 1);
        }
        
        // Return the minimum speed found
        return ans;
    }
};
