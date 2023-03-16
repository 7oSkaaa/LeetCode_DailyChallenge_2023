//Author: Nayra Mohammed
class Solution
{
public:
    
    
    /*
        - Just do Binary Search on the answer "find minimum time to make all trips"
        - We can validate the mid value whether it's suitable or not by finding the total trips each bus can perform during that value "proposed time" 
                                                                   * If the total can cover all the trips we need to do 
                                                                     ,then we can consider it as our answer and try to minimize it in futher search.
                                                                   * Otherwise, this value is too small to make all these trips so we need to maximize it.
    */
  
    bool GG_total(long long t, vector<int> &v, int tot) //to validate whether the given time can fulfil doing all trips
    {
        long long sum = 0;
    
        for (auto it : v)
            sum += (t / it); // total trips one bus can perform = total time we have / the time that bus itself consumes for a trip
    
        return sum >= tot;
    }
  
    long long minimumTime(vector<int> &time, int totalTrips)
    {   
        long long ans = 0, l = 0, r = 1e14;
        /*
            ans -> to store final answer
            our search space [0,1e14].
            Why our max limit is 1e14?
                - think of having only one bus that consumes 1e7 to perform one trip and u need to do total trips 1e7 OwO 
        */
        while (l <= r)
        {
            long long m = l + ((r - l) >> 1);
            (GG_total(m, time, totalTrips) ? r = m - 1, ans = m : l = m + 1);
        }
    
        return ans;
    }
};
