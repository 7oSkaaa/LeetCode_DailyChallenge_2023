// Author: Mina Magdy

class Solution {
public:
    // mapping existance of each word in words
    unordered_map<string, bool> exist;
    // dp 2D of m * m, Where m is the length of a word (Maximum = 30)
    vector<vector<int>> dp;
    /**
     * @brief dp recursive function "concate" to check 
     * if the current word consistes of at least 2 words concatenated
     * 
     * in dp you are trying to continue getting the next character in the current substring 
     * OR
     * if the current substring exist in words we get it ans calculate for the remain character the substrings
     * 
     * special case when j == 0 && i == n - 1 (the whole string) we return false avoiding return true in exist map
     * 
     * @param s : current word
     * @param i : end of interval
     * @param j : start of interval
     * @return int : 0 -> false, 1 -> true 
     */
    int concate(string& s, int i = 0, int j = 0) {
        if (i == s.size() - 1) {
            if (j == 0) return false;
            return exist[s.substr(j, i - j + 1)];
        }
        int& ret = dp[i][j];
        if (~ret) return ret;
        ret = 0;
        if (exist[s.substr(j, i - j + 1)]) {
            ret = concate(s, i + 1, i + 1);
        }
        ret = (ret || concate(s, i + 1, j));
        return ret;
    }
    /**
     * @brief for each word in words labeling the word as true in 'exist' map
     * ans for each word we are applying the dp function concatenate after initializing the dp vector with -1's
     * 
     * @param words 
     * @return vector<string> : 'ans' concatenated words 
     */
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& word : words) exist[word] = true;
        vector<string> ans;
        vector<vector<int>> temp(30, vector<int>(30, -1));
        for (auto& word : words) {
            dp = temp;
            if (concate(word)) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};