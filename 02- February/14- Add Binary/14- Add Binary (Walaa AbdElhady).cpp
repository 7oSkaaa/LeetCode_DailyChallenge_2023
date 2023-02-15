// Author: Walaa AbdElhady

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size(), tmpA = 0, tmpB = 0, carry = 0;
        int maxSz = max(n, m);
        string ans;
        // iterate until maximum size of two strings
        for (int i = 0; i < maxSz; i++) {
            // if string a is not over put his value in TmpA
            if (i < n)tmpA = a[n - i - 1] - '0';
            // if string a is over put his value => 0
            else tmpA = 0;
            // if string b is not over put his value in TmpB
            if (i < m)tmpB = b[m - i - 1] - '0';
            // if string b is over put his value => 0
            else tmpB = 0;
            // add two values and carry(if there exist)
            int total = tmpA + tmpB + carry;
            // update the carry for the next iteration
            carry = total / 2;
            char sum = (total % 2) + '0';
            ans.insert(0, 1, sum);
        }
        // if there is a carry left, add it to the ans
        if (carry)ans.insert(0, 1, '1');
        // return the ans
        return ans;
    }
};