
// Author: Mohamed Emara

class Solution {
public:
    vector<long long>v;
    long long n;

    bool can(long long x)
    {
        // to save the original vector after performing some operations.
        vector<long long>tmp;
        tmp = v;

        for(int i=n-1; i>0; i--)
        {
            // has to perform operation on index i to make the result = x
            if(v[i] > x)
            {
                long long diff = v[i] - x;
                v[i] = x;
                v[i-1] += diff;
            }
        }

        // if after modifying the vector, there is no element greater than x
        // so, X is a valid solution
        int ok = 0;
        if(*max_element(v.begin(), v.end()) <= x)
            ok = 1;
        else ok = 0;
  
        // restore the original vector.
        v = tmp;
        return ok;
    }

    int minimizeArrayValue(vector<int>& nums) {
        // Fill the global vector "v" to access it in 'can' function.
        for(auto it : nums)
            v.push_back(it);

        n = nums.size();

        // The result is some value between 1 and max element in the original vector
        long long l = 1, r = *max_element(nums.begin(), nums.end());
        long long ans = r;
        
        while(l <= r)
        {
            long long mid = l + (r-l) / 2;
            // at every mid, if it's a valid ans ===> see a better one
            // otherwise, search in the larger side for a valid ans
            if(can(mid)){
                r = mid-1;
                ans = mid;
            }
            else 
                l = mid+1;
        }

        return ans;
    }
};

