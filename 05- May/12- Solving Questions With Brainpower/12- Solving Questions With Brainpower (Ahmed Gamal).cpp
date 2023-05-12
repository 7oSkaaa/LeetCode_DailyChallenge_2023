// Author: Ahmed Gamal

// for this problem we will use dp to solve it
// we can see that we can take the question or leave it, so we will try to take it and leave it and take the maximum
// we will use dp[i] to be the maximum points we can take from the questions from i to n
// so dp[i] = max(dp[i+1], dp[i+b+1] + p) where p is the points of the question and b is the number of questions we will skip

// dp[i+1] is the maximum points we can take if we skip the current question (move to the next question)
// dp[i+b+1] + p is the maximum points we can take if we take the current question and skip the next b questions (move to the next b+1 question)
// the answer will be dp[0] which is the maximum points we can take from the first question to the last question

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        const int n = int(questions.size());
        vector<long long> dp(n + 5);

        for(int i = n - 1; ~i; --i) {
            int p = questions[i][0], b = questions[i][1];
            dp[i] = max(dp[i + 1], dp[min(i + b + 1, n)] + p);
        }

        return dp[0];
    }
};