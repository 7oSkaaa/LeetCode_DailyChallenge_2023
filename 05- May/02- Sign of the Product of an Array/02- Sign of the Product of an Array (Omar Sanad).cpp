// author : Omar Sanad

class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        // the answer which we will return
        int prod = 1;

        // iterate over the whole array
        for (auto &I : nums)
            if (I < 0)  // if the curr number is negative then multiply the prod by -1
                prod *= -1;
            else if (I == 0) // if the curr number equals zero then multiply the prod by 0
                prod *= 0;

        
        // return the answer
        return prod;
    }
};
