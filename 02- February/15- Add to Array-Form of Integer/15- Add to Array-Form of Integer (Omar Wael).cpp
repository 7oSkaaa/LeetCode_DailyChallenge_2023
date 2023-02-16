// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            // add current digit from k and num to carry
            carry+=num[i]+(k%10);
            ans.push_back(carry%10);
            // update k
            k/=10;
            // update carry
            carry/=10;
        }
        // check if there are any more digits in k
        while(k>0){
            carry+=k%10;
            ans.push_back(carry%10);
            k/=10;
            carry/=10;
        }
        // check if there are any more digits in carry
        if(carry>0){
            ans.push_back(carry%10);
        }
        // reverse the answer
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
