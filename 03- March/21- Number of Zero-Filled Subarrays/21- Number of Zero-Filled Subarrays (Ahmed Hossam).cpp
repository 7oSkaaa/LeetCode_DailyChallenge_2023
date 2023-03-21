// Author: Ahmed Hossam

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        // Define a vector to store the number of zeros between two non-zero numbers
        vector < int > zeros;
        // Define a variable to store the number of consecutive zeros
        int curr_zeros = 0;
        // Loop through the input vector and count the number of consecutive zeros
        for(auto& x : nums){
            // If the current number is not zero and we have counted some consecutive zeros before
            if(x != 0 && curr_zeros)
                // Add the number of consecutive zeros to the zeros vector and reset the counter
                zeros.push_back(curr_zeros), curr_zeros = 0;
            // If the current number is zero, increment the counter
            else if(x == 0)
                curr_zeros++;
        }
        // Add the final count of consecutive zeros to the zeros vector
        zeros.push_back(curr_zeros);
        // Define a variable to store the total number of zero-filled subarrays
        long long subarrays = 0;
        // Loop through the zeros vector and calculate the number of zero-filled subarrays for each count of consecutive zeros
        for(auto& z : zeros)
            subarrays += (1LL * z * (z + 1)) / 2;
        // Return the total number of zero-filled subarrays
        return subarrays; 
    }
};
