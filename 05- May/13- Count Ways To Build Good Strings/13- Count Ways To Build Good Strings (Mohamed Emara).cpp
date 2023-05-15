
// Author: Mohamed Emara

class Solution {
public:
    int dp[100005];
    int mod = 1e9 + 7;

    // global variables.
    int nZero, nOne;
    int hi, lo;


    int rec(int len)
    {
        // base case ---> if length exceeds the high limit --> return 0 (don't include it as a solution)
        if(len > hi)
            return 0;

        // memoization   
        int &ret = dp[len];
        if(~ret)
            return ret;

        // if the current length is exactly equals high limit --> add 1 as a valid solution
        // but can't increase lenght any more --> so return 1
        if(len == hi)
            return 1;

        // if the current length is in the range (low, high) --> Add 1 as it's a valid solution
        // & continue to other states
        if(len >= lo && len < hi)
            return ret = (1 + (rec(len+nZero)%mod + rec(len+nOne)%mod))%mod;
        
        
        // if the current lenght is below low limit --> go to the next states but as it's not
        // a valid solution we don't add 1 here.
        return ret = ((rec(len+nZero)%mod + rec(len+nOne)%mod))%mod;
    }
 

    int countGoodStrings(int low, int high, int zero, int one) {
        /* ======== IDEA =======*/
        /*
            Trace the lenght of the current segment of zeros and ones
            We only interested in the lenght, No need to construct the segment
            As every segment is unique --> whether add '1' one times 
            o                              or add '0' zeros times
            there is no overlaps
            Continue increaing the length in the two different ways 
            Until the lenght enters the range (low, high)
                start adding 1 to the result and continue till the end of the range (high)
        */
        hi = high;
        lo = low;
        nZero = zero;
        nOne = one;
        
        memset(dp, -1, sizeof(dp));
        return rec(0);
    }
};

