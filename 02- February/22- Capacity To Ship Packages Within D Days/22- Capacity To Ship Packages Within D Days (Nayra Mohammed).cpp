//Author: Nayra Mohammed

class Solution
{
public:
    // All we need is to apply BS "aka. Binary Search" to find the minimum possible maximum weight that our ship can handle to:
                                                                                                                 // - ship all packages within k days, no more !! 
    bool GG(int w, vector<int> &ww, int days)//check whether current weight is valid or not
    {
        int calc = 0; //to keep tracking the sum of packages'weight for each day..
        for (auto el : ww)
        {
            if (el > w)// current package is bigger than the max weight? then it's invalid 
                return 0;

            if (calc + el <= w)// if shipping current package in current day won't exceed our max weight,then we take it
                calc += el;
            else//Otherwise we ship the package next day.
                calc = el, days--;
        }

        return days - (calc > 0) >= 0;//shipped all packages in <= days? valid.Otherwise invalid
    }

    int shipWithinDays(vector<int> &weights, int days)
    {

        int mx = 0; // the maximum possible weight the ship will need is the sum of packages'weight
        
        for (auto el : weights)
            mx += el;
        
        int l = 1, r = mx, ans = -1;

        // Search Space [1,sum of packages'weights] ~ [l,r]
        // ans -> to store our final answer
        while (l <= r)
        {
            int m = l + ((r - l) >> 1);
            
            if (GG(m, weights, days))//Current weight is valid? we consider it as our answer and try to get a smaller one in further search
                ans = m, r = m - 1;
            else // Otherwise, we need to make it bigger to be valid "ship all packages within k days"
                l = m + 1;
        }

        return ans;
    }
};
