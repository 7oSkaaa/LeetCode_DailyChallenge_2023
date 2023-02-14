// Author: Mahmoud Aboelsoud

class Solution {
public:
    string addBinary(string a, string b) {
        // adding two binary numbers is the same as adding two numbers in base 10
        // so we can use the same algorithm we use to add two numbers in base 10
        // we sum the two numbers from the right to the left
        // and we keep track of the carry
        // and at each point we store the sum % 2 in the result
        // and the carry is the sum / 2


        // the result of adding two binary numbers
        string res = "";
        // i is the index of the last digit in a, j is the index of the last digit in b, carry is the carry
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        // while we haven't reached the end of both a, b, and carry is not 0
        // we keep adding the two numbers
        while(i >= 0 || j >= 0 || carry > 0){
            // if we haven't reached the end of a, we add the digit to the carry
            if(i >= 0)
                carry += a[i--] - '0';
            
            // if we haven't reached the end of b, we add the digit to the carry
            if(j >= 0)
                carry += b[j--] - '0';

            // we add the carry % 2 to the result
            res += (carry % 2) + '0';
            // we update the carry to be the carry / 2
            carry /= 2;
        }

        // we reverse the result because we added the digits from the right to the left but we stored them from the left to the right
        reverse(res.begin(), res.end());

        return res;
    }
};
