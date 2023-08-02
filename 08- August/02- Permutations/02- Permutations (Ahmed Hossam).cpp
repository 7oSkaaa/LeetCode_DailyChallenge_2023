// Author: Ahmed Hossam

class Solution {
public:
    // The permute function takes a vector of integers called "nums" as input and returns a vector of vectors of integers representing all possible permutations.
    vector<vector<int>> permute(vector<int>& nums) {
        // Create a vector of vectors of integers called "permutations" to store the generated permutations.
        vector<vector<int>> permutations;

        // Sort the input vector "nums" in ascending order to ensure that permutations are generated in lexicographic order.
        sort(nums.begin(), nums.end());

        // Generate permutations using the next_permutation function and add them to the "permutations" vector.
        do {
            permutations.emplace_back(nums);
        } while(next_permutation(nums.begin(), nums.end()));

        // Return the vector containing all generated permutations.
        return permutations;
    }
};
