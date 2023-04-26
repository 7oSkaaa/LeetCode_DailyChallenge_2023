// Author: Ahmed Hossam

class Solution {
public:

    // A function to find the sum of digits of a given number
    int sumDigits(int num){
        // Initialize the sum variable to zero
        int sum = 0;
        
        // Convert the number to a string and iterate over each character
        for(auto& c : to_string(num))
            // Subtract the ASCII value of '0' from the character and add it to the sum
            sum += c - '0';

        // Return the sum of digits
        return sum;
    }

    int addDigits(int num) {
        // Repeat the process until the number is a single digit
        while(num > 9)
            // Sum the digits of the number
            num = sumDigits(num);
            
        // Return the resulting single digit
        return num;
    }
};
