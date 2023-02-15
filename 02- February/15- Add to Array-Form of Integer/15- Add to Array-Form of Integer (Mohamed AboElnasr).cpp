/*
    Author: Mohamed AboElnasr
*/
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int size=num.size();
        int sum,carry=0;
        vector<int>ans;
        /*  in every iteration I:
         - add the digit of num + last digit of k
         - save the sumation  
         - push the first digit of sum to the ans
         - save the carry to the next iteration
         - remove the last digit of k 
        */
        for(int i=size-1;i>=0;i--){
            sum=(num[i]+(k%10));
            ans.push_back((sum+carry)%10);
            carry=(sum+carry)/10;
            k/=10;                  
        }
        /*
            after the loop I need to check that the value of carry and K
            are = 0;
            so I add carry to K and save it in k;
            then add all k's digits to the ans 

            then rever the ans :)
        */
         k+=carry;
        while( k){
            ans.push_back(k%10);
            k/=10;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};