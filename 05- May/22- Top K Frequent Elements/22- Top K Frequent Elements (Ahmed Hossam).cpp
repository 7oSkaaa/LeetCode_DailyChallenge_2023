// Author: Ahmed Hossam

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Create a frequency map to count the occurrences of each number
        unordered_map < int, int > freq;
        for (auto& i : nums)
            freq[i]++;
        
        // Sort the numbers based on their frequency in descending order
        // If two numbers have the same frequency, sort them in ascending order
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return freq[a] > freq[b] || (freq[a] == freq[b] && a < b);
        });
        
        // Create a vector to store the top k frequent elements
        vector < int > ans = { nums.front() };
        
        // Add unique elements to the vector until it reaches size k
        for (int i = 1; i < nums.size(); i++) {
            // If the vector has already reached size k, break the loop
            if (ans.size() == k) break;
            
            // Add the current element to the vector if it is different from the previous one
            if (nums[i] != nums[i - 1])
                ans.push_back(nums[i]);
        }
        
        // Return the vector containing the top k frequent elements
        return ans;
    }
    
};
