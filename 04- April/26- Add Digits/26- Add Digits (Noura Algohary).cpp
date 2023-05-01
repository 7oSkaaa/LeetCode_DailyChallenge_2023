// Author: Noura Algohary
// beats 100% in runtime 

class Solution {
public:
    int recursiveAddition(string num)
    {
        // the ending contidion is reaching a one digit number
        if(num.size() == 1)
            return (num[0] - '0');

        // to store the summation of digits of num
        int sumInt = 0;

        for(int i=num.size() - 1; i>=0; i--)
        {
            // convert the digit num[i] from char to int, then sum it
            sumInt += num[i] - '0';
        }
        
        return recursiveAddition(to_string(sumInt));
    }
    int addDigits(int num) {
        return recursiveAddition(to_string(num));
    }
};