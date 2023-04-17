// Author: Ahmed Hossam

class Solution {
public:

    vector < bool > kidsWithCandies(vector < int >& candies, int extraCandies) {
        // This variable finds the maximum number of candies any kid has
        int Max = *max_element(candies.begin(), candies.end());

        // This creates a boolean vector with the same size as the candies vector
        vector<bool> can(candies.size());

        // This loop checks if each kid can have the most number of candies
        // after adding the extra candies, and stores the result in the boolean vector
        for(int i = 0; i < candies.size(); i++)
            can[i] = candies[i] + extraCandies >= Max;

        // This returns the boolean vector
        return can;
    }
};
