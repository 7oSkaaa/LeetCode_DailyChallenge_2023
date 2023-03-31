// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find if there is a way to make s2 from s1 by scrambling
    // so we will try all possible ways to scramble s1 and check if we can make s2 from it
    // we will try all possible ways to split s1 into two parts and try to swap them or not and check if we can make s2 from it
    // we will use dynamic programming to avoid re-computing the same sub-problems
    

    // memoization array
    int dp[35][35][35][35];
    // s1 and s2
    string s1, s2;

    // check if we can make s2 from s1
    // we will have 4 parameters to represent the range of s1 and s2 we are checking
    int check(int st, int ed, int st2, int ed2){
        // if the range have length 1, we will check if the characters are equal
        if(st == ed) return s1[st] == s2[st2];

        // if we have already computed the answer, we will return it
        if(dp[st][ed][st2][ed2] != -1) return dp[st][ed][st2][ed2];

        // we will try all possible ways to split s1 into two parts and try to swap them or not and check if we can make s2 from it
        // ans variable will hold the answer
        int ans = 0;
        // loop and try to split s1 into two parts
        for(int i = st; i < ed; i++){
            // first way to split s1 into two parts and check if we can make s2 from it
            ans |= (check(st, i, st2, st2 + i - st) && check(i + 1, ed, st2 + i - st + 1, ed2));
            // second way to split s1 into two parts and swap them and check if we can make s2 from it
            ans |= (check(st, i, ed2 - (i - st), ed2) && check(i + 1, ed, st2, st2 + ed - i - 1));
        }

        // return the answer
        return dp[st][ed][st2][ed2] = ans;
    }

    bool isScramble(string s1, string s2) {
        // set s1 and s2
        this -> s1 = s1, this -> s2 = s2;
        // fill the memoization array with -1
        memset(dp, -1, sizeof(dp));

        // return the answer
        return check(0, s1.size() - 1, 0, s2.size() - 1);
    }
};
