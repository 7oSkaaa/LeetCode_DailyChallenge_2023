//Author: Nayra Mohammed 

#define sz(s) (int(s.size()))
class Solution
{
public:
 
    /*  
        We need to find the longest subarray having at most 2 distinct elements
        So we basically can use sliding window technique again OwO but using "Dynamic size"
        Starting our window from index 0 to index 0 "[0,0]"  we gonna move its end as much as it's possible
        and thats means if we still have the number of distinct elements in that window it's a valid one so we extends it from the end.
        Once the number of distinct elements exceeds 2 ,then we need to decrease our window from the left "start" till balancing our window again.. and so on.
    */
    int totalFruit(vector<int> &fruits)
    {
        map<int, int> mp; 
        /*  
            mp -> to store the frequencies of each element and to know how many distinct elements we have in current window
            mx -> to store the longest subarray applying the required rules
            l -> pointer to our window's start
            r -> pointer to our window's end
        */
        int mx = 0, l = 0, r = 0;
        
        while (r < sz(fruits)) // as we still did not reach the end of our elements
        {
            mp[fruits[r++]]++; // adding the frequency of current element "extending current window size"
            
            while (sz(mp) > 2) // while our window is not valid "the number of distinct elements exceeds 2" 
            {
                mp[fruits[l]]--; // we decrease window's size from left  "changing our start to start + 1" 
                if (!mp[fruits[l]])
                    mp.erase(fruits[l]);
                l++;
            }
            mx = max(mx, r - l); // maximize between our current final answer and  window's current size
        }

        return mx; // return the required answer
    }
};
