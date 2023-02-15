//Author: Sara Hamza

class Solution {
public:
#include <string>

    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();

        vector<int> ans;
        bool carry = 0;

        for(int i = n - 1; i >= 0; --i){
            //adding
            int digit = k % 10; //get the righttmost digit
            num[i] += digit + carry;

            //if sum is 2 digits => separate them
            carry = num[i] > 9;
            ans.push_back(num[i] % 10);

            k /= 10; //omitting the rightmost digit
        }

        //if there is more digits in k => add them
        while(k){
            int digit = k % 10;
            digit += carry;

            carry = digit > 9;
            ans.push_back(digit % 10);

            k /= 10;
        }

        if(carry)
            ans.push_back(1);


        reverse(ans.begin(), ans.end());

        return ans;

    }
};
