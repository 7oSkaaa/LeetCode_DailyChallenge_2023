// Author: Mazen Alasas
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result; // The answer vector
        // To get the maximum number of candies 
        int maximum = *max_element(candies.begin(), candies.end());
        // or
        /*
          for(auto candy : candies)
              maximum = max(candy, maximum);
        */
        for(auto candy : candies)
            /*
              If after giving the each kid an extraCandies(each kid's candy + extraCandies) 
              they will have the greatest number of candies among all the kids (>= maximum) push "true 1" otherwise push "false 0"
            */
            result.push_back(candy + extraCandies >= maximum ? 1 : 0);
        // Return the answer vector
        return result;
    }
};
