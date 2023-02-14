// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    string addBinary(string a, string b) {
        string ans="";
        // carry => saves the carried value
        // i => to iterate over first string
        // j => to iterate over second string
        int carry=0,i=a.size()-1,j=b.size()-1;
        while(i>=0 || j>=0){
            // add current values
            if(i>=0){
                carry+=a[i]-'0';
                i--;
            }
            if(j>=0){
                carry+=b[j]-'0';
                j--;
            }
            // add current binary digit to the answer
            ans+=to_string(carry%2);
            // update carry
            carry/=2;
        }
        // if there carry left add it
        if(carry>0){
            ans+=to_string(carry);
        }
        // reverse the answer
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
