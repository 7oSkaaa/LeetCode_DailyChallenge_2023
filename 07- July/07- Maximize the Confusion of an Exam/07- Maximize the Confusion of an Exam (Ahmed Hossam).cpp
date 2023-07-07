// Author: Ahmed Hossam

class Solution {
public:
    int getMaxConf(const string& answers, int k, char choice) {
        int n = answers.size();
        int maxConf = 0, currChoice = 0;
        int l = 0, r = 0;

        // Iterate through the answer key using two pointers 'l' and 'r'.
        while (r < n) {
            // Increment 'currChoice' if the answer at index 'r' matches the specified 'choice'.
            currChoice += (answers[r] == choice);

            // Adjust the window size by moving the left pointer 'l' if the current number of choices 'currChoice' exceeds the allowed 'k'.
            while (currChoice > k)
                currChoice -= (answers[l++] == choice);

            // Update the maximum consecutive count by comparing the current window size 'r - l + 1' with the previous maximum.
            maxConf = max(maxConf, r - l + 1);
            r++;
        }

        return maxConf;
    }

    int maxConsecutiveAnswers(const string& answerKey, int k) {
        // Return the maximum count between the consecutive 'T' answers and consecutive 'F' answers.
        return max(getMaxConf(answerKey, k, 'T'), getMaxConf(answerKey, k, 'F'));
    }
};
