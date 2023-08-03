// Author: Ahmed Hossam

class Solution {
public:
    // Vector to store the mapping of digits to corresponding letters
    vector<string> mapping, ans;

    // Recursive function to build all possible combinations of letters
    // for a given set of digits
    void build(const string& digits, int idx, string comb) {
        // If the combination's length matches the digits' length, add it to the answer vector
        if (comb.size() == digits.size())
            ans.push_back(comb);

        // If we have processed all the digits, return from the function
        if (idx == digits.size())
            return;

        // For each letter corresponding to the current digit, recurse and add the letter to the combination
        for (char& c : mapping[digits[idx] - '2'])
            build(digits, idx + 1, comb + c);
    }

    // Function to get all possible letter combinations for a given set of digits
    vector<string> letterCombinations(const string& digits) {
        // Define the mapping of digits to letters
        mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        // If the input digits are not empty, start building the combinations
        if (!digits.empty())
            build(digits, 0, "");

        // Return the vector containing all possible letter combinations
        return ans;
    }
};
