// Author: Nayra Mohammed

#define ceil(x, y) ((x + y - 1) / y) // calculate the celling of value "x/y"

class Solution
{
public:
    // - Perform BS to find the minimum suitable k such that it allows us to collect all piles'value within 'h' hours

    bool GG(vector<int> &v, int &k, int h) // to know whether current k is suitable or not
    {

        for (auto it : v)//iterate through piles and find how many hours current pile value needs to be collected
        {
            //the needed time =  pile value / k and as that value may be real value, so we take the ceil of it "pile value isn't divisable by k and we will take its reminder in a single hour"
            
            if (ceil(it, k) <= h)// if needed time is less than or equal to h then we decrease h by time.
                h -= ceil(it, k);
            else // otherwise we can't collect all piles within h hours , so k isn't suitable. return false
                return 0;
        }
        //we successfully collected them all within h
        return 1;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int l = 1, r = 1e9, ans = -1;
        /*
         Search Space [l,r] = [1,1e9], in worst case k can't exceed the maximum possible value in piles "piles[i] <= 1e9"
         ans -> store minimum possible k
        */

        while (l <= r)
        {
            int m = l + ((r - l) >> 1);
            /* 
                - if our mid value is suitable then we consider it as our answer and minimize our search space
                - Otherwise, we couldn't collect all piles' values then we need to make it bigger,so we maximize our search space
             */
            (GG(piles, m, h) ? ans = m, r = m - 1 : l = m + 1);
        }

        return ans;
    }
};
