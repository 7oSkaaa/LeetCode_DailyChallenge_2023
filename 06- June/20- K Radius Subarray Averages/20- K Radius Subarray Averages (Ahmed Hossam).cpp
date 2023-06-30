// Author: Ahmed Hossam

class Solution {
public:
    // This function takes a vector of integers and an integer 'k' as input and returns a vector of averages.
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(); // 'n' stores the size of the input vector
        int len = 2 * k + 1; // 'len' calculates the length of the subarray
        vector < int > avg(n); // 'avg' is a vector to store the averages of subarrays
        vector < long long > prefix(n); // 'prefix' is a vector to store the prefix sum of the input vector
        
        for(int i = 0; i < n; i++)
            prefix[i] = (i ? prefix[i - 1] : 0) + nums[i]; // Calculate the prefix sum
        
        // Create a lambda function 'sum' to calculate the sum of elements in a given range
        auto sum = [&](int l, int r) {
            return prefix[r] - (l ? prefix[l - 1] : 0);
        };
        
        for(int i = 0; i < n; i++) {
            int L = i - k; // Calculate the left index of the subarray
            int R = i + k; // Calculate the right index of the subarray
            bool isIn = (L >= 0 && R < n); // Check if the subarray is within the bounds of the input vector
            avg[i] = (isIn ? sum(L, R) / len : -1); // Calculate the average of the subarray or assign -1 if it is out of bounds
        }
        return avg; // Return the vector of averages
    }
};
