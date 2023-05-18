// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the maximum points we can get from answering the questions
    // we can do that using 0/1 dp
    // we can either answer the question or leave it
    // if we answer the question we will get the points of this question and move to the next question after the brainpower of this question

    // questions: 2d vector of questions (points, brainpower)
    vector<vector<int>> questions;
    // dp: 1d array for memoizing the dp
    vector<long long> dp;

    // function to get the maximum points we can get from answering the questions starting from idx
    long long get_max(int idx){
        // if we have finished all questions return 0
        if(idx >= questions.size()) return 0;

        // if we have already calculated the answer for this state return it
        if(dp[idx] != -1) return dp[idx];

        // we can either answer the question or leave it
        // 1- leave the question and move to the next question
        long long ans = get_max(idx + 1);

        // 2- answer the question and move to the next question after the brainpower of this question
        ans = max(ans, questions[idx][0] + get_max(idx + questions[idx][1] + 1));

        // return the answer
        return dp[idx] = ans;
    }


    long long mostPoints(vector<vector<int>>& questions) {
        // initialize the questions and dp
        this -> questions = questions;
        dp.assign(questions.size() + 5, -1);

        // return the maximum points we can get from answering the questions starting from idx = 0
        return get_max(0);
    }
};
