// Author: Ahmed Gamal

// for this problem we will use sliding window technique
// this problem is similar to the problem of finding the longest substring of 1s with at most k 0s
// we can solve this problem by just changing the 0s and 1s with T and F and then do it twice (one for T and one for F)
// and then take the maximum of the two answers

class Solution {
    // this function will return the maximum length of a substring of s with at most k values of val
    int get_max(int k, string& s, bool val) {
        // l: left pointer
        // r: right pointer
        // n: size of the string
        int l = 0, r = 0;
        const int n = int(s.size());

        // idx: string of the values we want to count
        // F is false and found in the string at index 0 (treating it as false)
        // T is true and found in the string at index 1 (treating it as true)
        string idx = "FT";

        // cnt: number of unwanted values in the current window
        // ans: maximum length of a substring of s with at most k values of val
        int cnt = 0, ans = 1;
        for(; r < n; r++) {
            // if the current character is not the wanted value then we will increase the cnt
            cnt += idx.find(s[r]) != val;

            // if the cnt is greater than k then we will move the left pointer to the right until the cnt is less than or equal to k
            while(cnt > k) {
                cnt -= idx.find(s[l++]) != val;
            }

            // update the answer with the maximum length of the current window
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // we will solve the problem twice (one for T and one for F)
        int ans = get_max(k, answerKey, true);
        ans = max(ans, get_max(k, answerKey, false));

        return ans;
    }
};