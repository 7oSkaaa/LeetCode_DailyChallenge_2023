// Author: Mahmoud Aboelsoud

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // to make this binary string monotone increasing we only have 3 cases:
        // 1- make all the string consist of 1's which can be done by flipping all the 0's
        // 2- make all the string consist of 0's which can be done by flipping all the 1's
        // 3- make the first part of the string consist of 0's and the second part consist of 1's 
        //    which can be done by flipping all the 1's in the first part and all the 0's in the second part
        //    and our answer in this case is the sum of number of 1's in the first part and number of 0's in the second part
        //    so we loop over the string and split it into two parts, first part is from the start to i and second part is from i + 1 to the end
        //    and we count the number of 1's in the first part and the number of 0's in the second part
        //    and we update the minimum number of flips we need with the minimum between our ans and the sum of:
        //    the number of 1's in the first part is the number of flips we need to do to make the first part consist of 0's and
        //    the number of 0's in the second part is the number of flips we need to do to make the second part consist of 1's
        
        
        // count the number of 0's and 1's in the string
        int cnt_0 = count(s.begin(), s.end(), '0');
        int cnt_1 = count(s.begin(), s.end(), '1');

        // initialize a variable to count the number of 1's in the first part
        int pre_1 = 0;

        // initialize a variable to store the minimum number of flips we need to do to make the string monotone increasing
        // and initialize it with the minimum number of flips we need to do to make the string consist of 0's or 1's, our first 2 cases
        int ans = min(cnt_0, cnt_1);

        // loop over the string to split it into two parts and test the third case
        // split the string into two parts, first part is from the start to i and second part is from i + 1 to the end
        for(int i = 0; i < s.size() ; i++){
            // if the current character is 1, increment the number of 1's in the first part
            if(s[i] == '1') pre_1++;
            // if the current character is 0, decrement the number of 0's in the second part
            else cnt_0--;
            
            // update the minimum number of flips we need with the minimum between our ans and the sum of:
            // the number of 1's in the first part is the number of flips we need to do to make the first part consist of 0's and
            // the number of 0's in the second part is the number of flips we need to do to make the second part consist of 1's
            ans = min(ans, pre_1 + cnt_0);
        }

        // return the minimum number of flips we need to do to make the string monotone increasing
        return ans;
    }
};
