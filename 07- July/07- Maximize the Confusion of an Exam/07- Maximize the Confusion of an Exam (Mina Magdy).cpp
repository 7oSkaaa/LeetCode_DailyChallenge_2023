// Author: Mina Magdy

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size(); // Get the size of the answer key
        int ans = k; // Initialize the answer to k
        // Define a lambda function 'solve' to calculate the maximum consecutive answers for a given character
        auto solve = [&](const char &c) {
            int cnt = 0; // Initialize a counter to count the occurrences of the character
            for (int l = 0, r = 0; r < n; r++) {
                cnt += answerKey[r] == c; // Increment the counter if the current character matches the given character
                while (cnt > k) { // If the counter exceeds k, move the left pointer and decrement the counter until it becomes less than or equal to k
                    cnt -= answerKey[l++] == c;
                }
                ans = max(ans, r - l + 1); // Update the maximum consecutive answers if necessary
            }
        };
        // Call the 'solve' function for 'F' and 'T' characters
        solve('F'), solve('T');
        return ans; // Return the maximum consecutive answers
    }
};
