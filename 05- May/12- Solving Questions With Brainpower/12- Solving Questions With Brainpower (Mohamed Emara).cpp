
// Author: Mohamed Emara


class Solution {
public:
    int n;
    long long a[100005];
    long long b[100005];
    // states of dp ====> at each index whether to take or leave
    long long dp[100005][2];
    

    long long rec(long long idx, bool state)
    {
        if(idx >= n)
            return 0;
        long long &ret = dp[idx][state];
       
        if(~ret)
            return ret;
        
        // if I'll take this item, I won't be able to take the next b[idx] items
        // So, the next item can take is (idx+b[idx]+1)

        long long take = a[idx] + rec(idx+b[idx]+1, 1);
        
        // Or skip this index, and go to the next one without changing the taken value
        long long leave = rec(idx+1, 0);

        // Zero and One (second paramter) is to distinguish between the two states.

        return ret = max(take, leave);
    }


    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();

        // fill the two global arrays with (earn value) and (nex unable item)
        for(int i=0; i<n; i++)
        {
            a[i] = questions[i][0];
            b[i] = questions[i][1];
        }    

        
        memset(dp, -1, sizeof(dp));
        return rec(0, 0);
    }
};


