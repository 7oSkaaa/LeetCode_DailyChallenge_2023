// author : Omar Sanad

// In this problem we can say that at each idx what is the number of valid subsequences,
// that this nums[idx] is the smallest number in it
class Solution {
public:
    
    // define some macros for easy use
    #define ll long long
    #define MOD int(1e9 + 7)

    // A binary power function that works in O(log(POWER))
    // We implemented this function to calculate the power and taking the mode
    ll fastpower(ll base, ll po, ll md) {
        ll ANS = 1;
        while (po){
            if (po & 1)
                ANS = (ANS * base) % md;
            base *= base, base %= md;
            po >>= 1;
        }
        return ANS;
    }

    
    int numSubseq(vector<int>& nums, int target) {

        // we sort the vector
        sort(nums.begin(), nums.end());

        // declare a variable to store the answer
        int Answer = 0;

        // iterate over all the elements
        for (int i = 0, idx; i < nums.size(); i++) {

            // to avoid time limit in the binary search 
            // we have to search for an element that is bigger than me
            if (nums[i] > target - nums[i])
                continue;

            // get the maximum element that meet the codition with nums[i]
            // where nums[i] + nums[idx] <= target
            idx = upper_bound(nums.begin() + i, nums.end(), target - nums[i]) - nums.begin();
            idx--;

            // then we count the number of subsequences that start from this number
            // every element except v[i]
            // we two possiblities for it, either take or leave
            Answer = (Answer + fastpower(2, idx - i, MOD)) % MOD;
        }

        // return the answer to the problem
        return Answer;
    }
};
