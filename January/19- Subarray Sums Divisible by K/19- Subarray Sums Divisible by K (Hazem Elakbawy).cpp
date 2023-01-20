// Author : Hazem Elakbawy
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res=0,n=nums.size(),sum=0;
        vector<int>rem(k,0);
        rem[0]=1;
        for(int i:nums)
        {
            sum+=i;
            int index=(sum%k+k)%k;
            rem[index]++;
        }
        for(int i:rem)
        res+=(i)*(i-1)/2;
        return res;
    }
};

/*
    Approach:
    * we get the summation of all subarrays using prefix sum (curr_num + previous sum)
    * the prefix sum of a subarray is (pre[i]-pre[j-1]) than subarray from (j to i)
    * if (pre[i]-pre[j-1]) % k == 0   then (pre[i]%k == pre[j-1]%k) 
    * then we count all similar remainders of all subarrays then we get all possible subarrays that is divisible by k
*/
/* 
    proof:
    *  M =  b * k + a
    *  N =  x * k + y
    * then M - N ==>  ( b - x ) * k + ( a - y )
    * (M - N) will be divisible if ( a - y ) == 0 (both remainders are the same)

    25 % 2 = 1
    35 % 2 = 1
    (35-25) ==> 10 % 2 = 0
*/
