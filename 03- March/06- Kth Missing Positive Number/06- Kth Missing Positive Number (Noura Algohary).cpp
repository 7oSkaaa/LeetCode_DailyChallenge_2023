// Author: Noura Algohary
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // the must be number
        // toK is how many of k occurred 
        int num = 1, toK = 0;

        for(int i = 0; i<arr.size();i++)
        {
            if(arr[i] != num)
                {
                    i--; // stay at the same position not to skip a number [4, 8] must return [5, 6, 7]
                    toK ++;
                    if(toK == k)
                        return num;
                }
            num ++;
        }
    
    // if the missing numbers are limited with a last number 
    // return the k position after the last element in the array
    return num + k -1 - toK;
    }
};