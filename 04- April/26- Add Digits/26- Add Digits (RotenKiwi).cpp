// Author: RotenKiwi
class Solution {
public:
    int addDigits(int num) {
        if(num<10)return num;      // If  number is less than 10, retrn it.
        int curr=0;               //  Variable to store the digit sum.
        while(num){              // Calculation of digit sum.
            curr=curr+(num%10);
            num=num/10;
        }
        return addDigits(curr);       // Recurse the same for the new number
    }
};
