// author : Omar Sanad
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {

        // declaring the maxNumber of candies
        int maxi = 0, n = candies.size();

        // Get the value of the maxNumber of candies
        for (auto &I : candies) maxi = max(maxi, I);

        // declaring the boolean array ans
        vector <bool> ans(n);

        // check for every kid whether they validate the condition
        for (int i = 0; i < n; i++)
            if (candies[i] + extraCandies >= maxi)
                ans[i] = 1;

        // return the answer
        return ans;
    }
};
