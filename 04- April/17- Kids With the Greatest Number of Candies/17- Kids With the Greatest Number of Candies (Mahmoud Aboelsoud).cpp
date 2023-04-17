// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // find the max number in the vector
        int mx = *max_element(candies.begin(), candies.end());
        // create a vector of bools with the same size of the candies vector and initialize it with false
        vector<bool> ans(candies.size(), 0);

        // loop over the candies vector and check if the current number + extraCandies >= mx
        // if so, set the current index in the ans vector to true
        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= mx) ans[i] = 1;
        }

        // return the ans vector
        return ans;
    }
};
