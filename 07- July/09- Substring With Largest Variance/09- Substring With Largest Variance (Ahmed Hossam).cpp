// Author: Ahmed Hossam

class Solution {
public:
    int getDiff(char a, char b, const string& s) {
        int bestDiff = 0;
        int cnt_a = 0, cnt_b = 0;

        // Iterate over each character 'c' in the string 's'.
        for (auto& c : s) {
            // If the character 'c' is equal to 'a', increment the count of 'a' (cnt_a).
            if (c == a) cnt_a++;

            // If the character 'c' is equal to 'b', increment the count of 'b' (cnt_b).
            if (c == b) cnt_b++;

            // Calculate the difference between the counts of 'a' and 'b',
            // and update the best difference if necessary.
            bestDiff = max(bestDiff, cnt_a - max(cnt_b, 1));

            // If the count of 'a' is less than the count of 'b',
            // reset both counts to 0 to start counting again.
            if (cnt_a < cnt_b) {
                cnt_b = cnt_a = 0;
            }
        }

        // Return the maximum difference between the counts of 'a' and 'b' in the string 's'.
        return bestDiff;
    }

    int largestVariance(const string& s) {
        // Initialize a frequency array to count the occurrences of each character in 's'.
        vector<int> freq(26);

        // Iterate over each character 'c' in the string 's'.
        for (auto& c : s) {
            // Increment the count of the character 'c' in the frequency array.
            freq[c - 'a']++;
        }

        // Initialize the best difference as 0.
        int bestDiff = 0;

        // Iterate over each character 'a' from 'a' to 'z'.
        for (char a = 'a'; a <= 'z'; a++) {
            // Iterate over each character 'b' from 'a' to 'z'.
            for (char b = 'a'; b <= 'z'; b++) {
                // Check if the counts of both characters 'a' and 'b' are non-zero and 'a' is not equal to 'b'.
                if (freq[a - 'a'] && freq[b - 'a'] && a != b) {
                    // Calculate the difference between 'a' and 'b' in the string 's'
                    // using the getDiff() function, and update the best difference if necessary.
                    bestDiff = max(bestDiff, getDiff(a, b, s));
                }
            }
        }

        // Return the largest variance found in the string 's'.
        return bestDiff;
    }
};
