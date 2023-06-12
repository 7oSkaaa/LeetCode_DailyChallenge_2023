// Author: Ahmed Hossam

class Solution {
public:

    // Function to create a range string representation
    string make_range(int l, int r) {
        if (l == r)
            return to_string(l);
        return to_string(l) + "->" + to_string(r);
    }

    // Function to summarize ranges in a vector of integers
    vector < string > summaryRanges(const vector < int >& nums) {
        // if the nums array is empty
        if(nums.empty()) return {};
        
        vector < string > Ranges; // Vector to store the summarized ranges
        int begin = nums[0]; // Initialize the beginning of the range

        // Iterate through the numbers
        for (int i = 1; i < nums.size(); i++) {
            // If the current number is not consecutive to the previous number
            if (nums[i] != nums[i - 1] + 1) {
                // Add the summarized range to the vector
                Ranges.emplace_back(make_range(begin, nums[i - 1]));
                begin = nums[i]; // Update the beginning of the next range
            }
        }

        // Add the last range to the vector
        Ranges.emplace_back(make_range(begin, nums.back()));

        return Ranges; // Return the summarized ranges
    }

};
