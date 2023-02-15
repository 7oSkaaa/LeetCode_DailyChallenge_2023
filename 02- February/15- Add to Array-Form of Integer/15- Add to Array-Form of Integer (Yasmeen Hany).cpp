// Author: Eileanora
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        /*
        approach:
        1. add the last digit of k to the last digit of num
        2. if the sum is greater than 10, then carry sum / 10 to the next digit
            num[i] value can never be greater than 9 so we take it as sum % 10
        3. repeat the process until k is 0
        4. if k is 0 and carry is not 0, then add the carry to the front of the vector
        */
        int carry = 0;
        for(int i = num.size()-1; i >= 0; i--) { 
            int sum = num[i] + k%10 + carry; 
            num[i] = sum%10;
            carry = sum/10;
            k /= 10;
        }
        // if k is not 0, then add the remaining digits of k to the front of the vector
        while(k){
            int sum = k%10 + carry;
            num.insert(num.begin(), sum%10);
            carry = sum/10;
            k /= 10;
        }
        // if carry is not 0, then add the remaining carry to the front of the vector
        while(carry){
            num.insert(num.begin(), carry%10);
            carry /= 10;

        }
        return num;            
    }
};