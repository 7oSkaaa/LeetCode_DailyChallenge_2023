// Author: Osama Ayman
class Solution {
    public int addDigits(int num) {
        // if it is a single digit return it
        if(num <= 9) return num;
        // else calculate the sum of digits
        int res = 0;
        while(num > 0){
            // get the last digit of num, add it to res
            res += num%10;
            // remove last digit of num
            num /= 10;
        }
        // do it recursively 
        return addDigits(res);
    }
}