// Author: Mina Magdy

class Solution {
public:
    // Function to find the largest variance in a given string
    int largestVariance(string s) {
        int n = s.size(); // Length of the string
        int ans = 0; // Variable to store the largest variance

        // Iterate over all possible pairs of characters ('a' to 'z')
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                int a = 0, b = 0; // Counters for occurrences of characters 'a' + i and 'a' + j respectively

                // Sliding window approach to compute variance from left to right
                for (int l = 0, r = 0; r < n; r++) {
                    a += (s[r] == 'a' + i);
                    b += (s[r] == 'a' + j);

                    // Adjust the left pointer of the window to maintain the condition a >= b
                    while (a - b < 0) {
                        a -= (s[l] == 'a' + i);
                        b -= (s[l] == 'a' + j);
                        l++;
                    }

                    // Update the largest variance if both characters 'a' + i and 'a' + j occur at least once
                    if (a > 0 && b > 0) {
                        ans = max(ans, a - b);
                    }
                }

                // Reset the counters for the next iteration (right to left)
                a = 0, b = 0;

                // Sliding window approach to compute variance from right to left
                for (int l = n - 1, r = n - 1; r >= 0; r--) {
                    a += (s[r] == 'a' + i);
                    b += (s[r] == 'a' + j);

                    // Adjust the left pointer of the window to maintain the condition a >= b
                    while (a - b < 0) {
                        a -= (s[l] == 'a' + i);
                        b -= (s[l] == 'a' + j);
                        l--;
                    }

                    // Update the largest variance if both characters 'a' + i and 'a' + j occur at least once
                    if (a > 0 && b > 0) {
                        ans = max(ans, a - b);
                    }
                }
            }
        }

        return ans; // Return the largest variance
    }
};
