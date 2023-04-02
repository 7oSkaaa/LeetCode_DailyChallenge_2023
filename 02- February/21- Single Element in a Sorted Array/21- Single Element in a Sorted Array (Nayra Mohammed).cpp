// Author: Nayra Mohammed

// 1st Solution : Time Complexity = O(n)
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        /*
            - Thinking of bitwise xor:
                a ^ a = 0
                b ^ b = 0
                a ^ b = (a ^ b)
                We can xor all nums's elements to remove all duplicated pairs
                so, the final result will equal to the number that exists exactly once
        */

        int x0r = 0;

        for (auto it : nums)
            x0r ^= it;

        return x0r;
    }
};



// 2nd Solution : Time Complexity = O(lg n)

#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
       - Observation:
            * indices :0 1 2 3 4 5 6 7 8
            * elements:1 1 3 3 2 4 4 5 5

            - We can see that all duplicates existing before our target number starts from even indices
              Otherwise,they starts from odd indices
            - Applying BS,we can get our target by knowing in which side we currently are "before or after thw target"
    */

    bool GG(int m, vector<int> &v)
    {
        if (m & 1) // if we are in an odd index we need to make sure we after the target
            return v[m - 1] != v[m];
        /*
        Otherwise,we need to make sure that current element is not a duplicate of the following element
        that also means either current element is our target or current element is a duplicate after our target
        */
        return m + 1 == sz(v) || v[m + 1] != v[m];
    }

    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = sz(nums) - 1, ans = -1;
        /*
            our search space is [0,sz(nums)-1] ~ [l,r]
            ans -> to store our target element
        */
        while (l <= r)
        {
            int m = l + ((r - l) >> 1);

            if (GG(m, nums)) // if current element is our target or lies after our target ,we minimize and store current element as our answer
                ans = nums[m], r = m - 1;
            else // current element lies before our target ,we maximize to get nearer from our target
                l = m + 1;
        }

        return ans;
    }
};
