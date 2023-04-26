// Author: Mahmoud Aboelsoud

class Solution {
public:
    // in this problem we have to add the digits of a number until we get a single digit
    // we can do this by using a while loop and a nested while loop
    // the outer loop will run until the number is less than 9
    // the inner loop will run until the number is 0 to add the digits

    int addDigits(int num) {
        // loop until the number is less than or equal 9 (single digit)
        while(num > 9){
            // x: the sum of the digits
            int x = 0;
            // loop until the number is 0 to add the digits
            while(num){
                // add the last digit to x
                x += num % 10;
                // remove the last digit from the number
                num /= 10;
            }
            // make the number equal to x (the sum of the digits)
            num = x;
        }

        // return the number
        return num;
    }
};
