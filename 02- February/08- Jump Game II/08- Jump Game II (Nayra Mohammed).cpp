//Author :  Nayra Mohammed
#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
        - For Each position we need to find the minimum jumps it can be performed to reach position n-1    
        - As we need to try all valid postion's jumps that would be with a high time complexity,
        We gonna memorize for each position it's best answer "minimum jumps to reach n - 1"  
    */

    vector<int> dp; // our memorization vector 
    
    int Path(int idx, vector<int> &v)
    {

        if (idx == sz(v) - 1) // if we reached our desired distination no more jumps is needed "base case"
            return 0;

        if (dp[idx] != -1) // if we already have been in that state before return it's memorized answer
            return dp[idx];

        int ok = 1e9; // to store the minimum jumps needed from current position till reaching our destination n-1 

        for (int i = 1; i <= v[idx] && i + idx < sz(v); i++) // for each valid steps
            ok = min(ok, 1 + Path(idx + i, v));//we calculate the required jumps to reach n-1 using that step
                                               // and store the minimum overall answer between all tried steps

        return dp[idx] = ok; // memorize the best answer for current state
    }

    int jump(vector<int> &nums)
    {
        dp.resize(sz(nums), -1); // update our memorization vector's size & it's initial answer for every position
        
        return Path(0, nums); 
    }
};
