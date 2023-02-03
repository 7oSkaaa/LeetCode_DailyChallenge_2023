// Author : Hazem Elakbawy
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size(),total_flips=0;

        for(int i=0;i<n;i++)
            s[i]=='0'?total_flips++:total_flips;
        /*
            ==> flip ones from prefix (or) flip zeroes from suffix
            ==> answer will be either flip (zeores from suffix),(ones from prefix) or both
            ==> initially (suffix=n) && (prefix=0)
            ==> on next position suffix-- && prefix++

            ** if   : current bit ('0') ==> decrease #zero_bits on suffix --
            ** else : current bit ('1') ==> increase #one_bits on prefix ++

            ## compare total_flips with past answers to get the (optimal) solution
        */
        int ans=total_flips; 
        for(int i=0;i<n;i++)
            s[i]=='0'?total_flips--,ans=min(total_flips,ans):total_flips++;

        return ans;
    }
};