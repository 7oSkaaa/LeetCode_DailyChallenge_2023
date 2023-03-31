//Author: Abdelrrahman Elhaddad

// We are going to use DP technique called MCM (Matrix Chain Multiplication)
/*
  Links that I think may be helpful about MCM:
    - https://www.youtube.com/watch?v=XrB_MWPjHHc&t
    - https://www.youtube.com/watch?v=zQrR8t7urEE
  */

class Solution {
private:
int n;
unordered_map<string, bool> dp; // For memoization

public:
bool rec(string s1, string s2) {
    if (s1.length() == 1 || s1 == s2) // If we reached substring with length equal to 1, then we will return the output of the condition s1 == s2
        return s1 == s2;

    n = s1.length();

    unordered_map<char, int> f1, f2; // Initializing frequency unordered map for each string to mark the letters in each substring
    for (int i = 0; i < n; i++) {
        f1[s1[i]]++;
        f2[s2[i]]++;
    }
    if (f1 != f2) // If the two substrings do not have the same letters and the same number of these of these letters return False (There is no way these two strings will be equal to eachother)
        return false;

    if (dp.count(s1 + '+' + s2)) // Check whether I have checked these two substrings before
        return dp[s1 + '+' + s2]; // If I have, return the stored value
    bool &ans = dp[s1 + '+' + s2]; // If not Initialize a ans variable as a refrence to the location of these two substrings in our memoization container

    for (int i = 0; i < s1.length() - 1 && !ans ; i++) { // Iterating through the length of two substrings to split them in all possible ways
        n = s1.length();

        // Split first substring
        string s1_firstHalf = s1.substr(0, i + 1);
        string s1_secondHalf = s1.substr(i + 1, n);

        // Split second substring
        string s2_firstHalf = s2.substr(0, i + 1);
        string s2_secondHalf = s2.substr(i + 1, n);

        // Continue splitting recursively
        ans |= rec(s1_firstHalf, s2_firstHalf) && rec(s1_secondHalf, s2_secondHalf); // Without swapping

        n = s1.length();

        // Splitting second substring but the first half length is equal to the second half length of the first substring so we continue recuesion with these two
        // and the second half of the second substring is equal to the first half of the first substring
        // So for example if the first substring is 'ABCDE' and the second is 'CDBAE':
        // first substring -->  first half = 'AB'   second half = 'CDE'
        // second substring --> first half = 'CDB'  second half = 'AE'
        // Then I will take 'AB' with 'AE' and 'CDE' with 'CDB'
        s2_firstHalf = s2.substr(0, s1_secondHalf.length());
        s2_secondHalf = s2.substr(s2_firstHalf.length(), n);

        ans |= rec(s1_firstHalf, s2_secondHalf) && rec(s1_secondHalf, s2_firstHalf); // With swapping
    }
    return ans;
}

bool isScramble(string s1, string s2) {
    return rec(s1, s2);
}
};
