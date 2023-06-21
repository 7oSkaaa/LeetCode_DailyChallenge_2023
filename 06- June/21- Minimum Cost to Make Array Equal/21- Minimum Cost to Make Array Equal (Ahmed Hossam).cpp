// Author: Ahmed Hossam

class Solution {
public:
    long long minCost(const vector<int>& nums, const vector<int>& cost) {
        int n = nums.size(); // Get the size of the nums vector
        long long sum = 0, Cost1 = 0, Cost2 = 0;
        
        // Create a vector of pairs to store the corresponding values from nums and cost
        vector < pair < int, int > > vec(n);
        
        // Iterate over the nums and cost vectors and populate the vec vector with pairs
        for(int i = 0; i < n; i++){
            vec[i] = make_pair(nums[i], cost[i]);
            sum += cost[i]; // Calculate the sum of all costs
        }
        
        // Sort the vec vector in ascending order based on the nums values
        sort(vec.begin(), vec.end()); 
        
         // Calculate target1, target2, num1, and num2 to get the median of the costs
        long long target1 = sum / 2, target2 = target1 + 1, num1 = -1, num2 = -1;
        sum = 0; // Reset the sum variable
        
        // Iterate over the vec vector
        for(int i = 0; i < n; i++){
            auto [x, w] = vec[i]; // Destructure the pair into variables x and w
            sum += w; // Calculate the cumulative sum of weights
            
            // Check if the sum is greater than or equal to target1 and num1 has not been assigned a value yet
            if(sum >= target1 && !~num1) num1 = x;
            
            // Check if the sum is greater than or equal to target2 and num2 has not been assigned a value yet
            if(sum >= target2 && !~num2) num2 = x;
        }
        
        // Calculate the costs based on num1 and num2
        for(int i = 0; i < n; i++){
            auto [x, w] = vec[i]; // Destructure the pair into variables x and w
            
            // Calculate the cost1 by multiplying the absolute difference between x and num1 with w
            Cost1 += (1LL * abs(x - num1) * w);

            // Calculate the cost2 by multiplying the absolute difference between x and num2 with w 
            Cost2 += (1LL * abs(x - num2) * w);
        }
        
        // we calculate two median cause if n even the median can be n / 2, n / 2 + 1
        // Return the minimum cost between cost1 and cost2
        return min(Cost1, Cost2);
    }
};
