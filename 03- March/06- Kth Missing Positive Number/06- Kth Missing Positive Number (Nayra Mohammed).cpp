// Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    // Time Complexity: O(max elememnt in arr) such that arr's elements <= 1000

    int findKthPositive(vector<int> &arr, int k)
    {
        // val -> to keep tracking the value, whether it exists or not in arr
        // idx -> to refer to the current element in arr
        int val = 1, idx = 0;

        while (idx < sz(arr) && k) // we stop our searching either we finished all arr's elements or we found the missing value
        {

            if (val == arr[idx]) // if our val equals to current element? then we move to the next element
                idx++;
            else // Otherwise, this value is missing from our array, so we decrease k
                k--;
            val++; // increment current value for the upcoming iteration
        }
       
        /*
         - If our iteration stopped due to finding the missing value, then the answer is val - 1 
         Otherwise, we still didn't find the missing value in the range of arr's elements.
         So for sure, the value is bigger than arr's maximum element,the answer is val + k - 1 
         
         "-1 for the extra increment in the final iteration"
        */

        return val + k - 1;
    }
};
