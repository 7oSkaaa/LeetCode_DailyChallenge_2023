// Author : Abdelrehman Mamdouh

class Solution {
public:
    // is_good fucntion to see if the capacity works and can carry all within days
    bool is_good(vector <int> v, int cap, int days)
    {
        int sum = 0, d = 1;
        for (auto &i : v)
        {
            // if one element is bigger the capacity, it's invalid since it cannot be carried
            if (i > cap)
                return false;

            // if the current element with the previos elements exceeds elements we need a new day
            if (i + sum > cap)
                sum = 0, d++;

            // adding the current elemnet
            sum += i;
        }
        return (d <= days);
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
        int l = 1, r = 1, m, ans;

        // to caculate the upper bound for our search if it's valid we know there is an awnser
        // so no need to go further since we want the lower bound (least capacity valid)
        while (!is_good(weights, r, days))
            r *= 2;

        // implementing binary search on answer to get the least valid capacity
        while (l <= r)
        {
            // caculate the middle without getting overflow
            m = l + (r - l) / 2;

            // if it's valid consider it and go to the left side becase we need a smaller element
            // if not valid hence we need a bigger capacity so shift right
            (is_good(weights, m, days) ? ans = m, r = m - 1 : l = m + 1);
        }
        
        return ans;        
    }
};
