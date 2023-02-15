// Author: Mahmoud Aboelsoud

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        // we turn the two numbers to strings for the ease of manipulation
        // then we sum the two numbers from the right to the left
        // and we keep track of the carry
        // and at each point we store the sum % 10 in the result
        // and the carry is the sum / 10

        string s1 = "";
        string s2 = to_string(k);
        for(auto&i: num)
            s1 += i + '0';

        // i is the index of the last digit in s1, j is the index of the last digit in s2, carry is the carry
        int i = s1.size() - 1, j = s2.size() - 1, carry = 0;
        string res = "";

        // while we haven't reached the end of both s1, s2, and carry is not 0
        while(i >= 0 || j >= 0 || carry > 0){
            // if we haven't reached the end of s1, we add the digit to the carry
            if(i >= 0)
                carry += s1[i--] - '0';

            // if we haven't reached the end of s2, we add the digit to the carry
            if(j >= 0)
                carry += s2[j--] - '0';

            // we add the carry % 10 to the result
            res += (carry % 10) + '0';
            // we update the carry to be the carry / 10
            carry /= 10;
        }

        // we turn the result to a vector of integers and reverse it because we added the digits from the right to the left but we stored them from the left to the right
        vector<int> ans(res.size());
        for(i = 0, j = res.size() - 1; i < ans.size(); i++, j--)
            ans[i] = res[j] - '0';

        return ans;
    }
};
