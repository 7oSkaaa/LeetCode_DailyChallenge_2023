// author: Esraa Syam
class Solution {
public:
/*
    to solve the problem we need to know how to add two binary numbers
    1. we need to add from the last digit to the first digit
    2. add the carry to the sum if existed
    3. if the sum is 2 or 3 we need to carry 1 to the next digit
    4. if the sum is 0 or 1 we need to carry 0 to the next digit
*/
    string addBinary(string a, string b) {
        // to store the result
        string res = "";
        // two pointers to iterate over the two strings
        // from the last digit to the first digit
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        // iterate over the two strings
        while(i >= 0 or j >= 0){
            int sum = 0;
            // add the two digits
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            // add the carry
            sum += carry;
            // transform the sum to binary
            res += to_string(sum % 2);
            // update the carry
            carry = sum / 2;
        }
        // if there is a carry left add it to the result
        if(carry) res += to_string(carry);
        // reverse the result
        reverse(res.begin(), res.end());
        return res;
    }
};