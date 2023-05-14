
// Author: MohamedEmara

class Solution {
public:
   
    int n;
    int dp[20][20000];
    int arr[20];

    int rec(int idx, int mask)
    {
        // the base case WHEN all bits are set to one
        if(mask == (1<<(2*n))-1)
            return 0;

        int &ret = dp[idx][mask];
        if(~ret)
            return ret;
        

        ret = 0;

        for(int i=0; i<2*n; i++)
        {
            for(int j=i+1; j<2*n; j++)
            {
                // if the two bits i , j not taken yet in the mask
                // try to take them and maximize the value.
                if(!(mask & (1 << j)) && !(mask & (1 << i)))
                {
                    // set two bits of one ie: add the value of these two bits
                    int tmp = mask + (1 << j) + (1 << i);
                    ret = fmax(ret, idx * __gcd(arr[i], arr[j]) + rec(idx+1, tmp));
                }
            }
        }

        return ret;
    }


    int maxScore(vector<int>& nums) {
         ios_base::sync_with_stdio(false);
cin.tie(NULL);


        n = nums.size() / 2;
        
        // At every idx(ith operation)
        // We will try to choose two distinct numbers
        // An save the taken elements in a mask that is intially all zeros
        // the two taken element --> set their bits to one and continue trying other elements
        // till the mask becoms all ones of lenght 2*N  -->  (1 << (2*n) - 1)

        memset(dp, -1, sizeof(dp));
        for(int i=0; i<2*n; i++)
            arr[i] = nums[i];

        return rec(1, 0);
    }
};


