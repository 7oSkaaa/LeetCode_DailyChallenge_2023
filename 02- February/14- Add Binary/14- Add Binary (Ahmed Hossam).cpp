// Author: Ahmed Hossam

class Solution {
public:

    string addBinary(string& a, string& b) {
        string sum;
        // iterate over the two strings from the end
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        // while we have not reached the beginning of the strings
        while(~i || ~j){
            // get the current bit and add the carry to it
            int current_bit = carry;

            // if the index is valid, add the bit to the current bit
            if(~i)
                current_bit += a[i--] - '0';
            
            // if the index is valid, add the bit to the current bit
            if(~j)
                current_bit += b[j--] - '0';
            
            // add the current bit to the sum
            sum += (current_bit % 2) + '0';

            // update the carry for the next iteration
            carry = current_bit / 2;
        }

        // if there is a carry left, add it to the sum
        if(carry)
            sum += '1';

        // reverse the sum to get the correct order
        reverse(sum.begin(), sum.end());

        // return the sum
        return sum;
    }
};
