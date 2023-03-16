// Author: Mohamed Ashraf

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int sz = arr.size(), idx = 0, target = 1;
        while(k){
            // Check if target is equal arr[idx]
            if(idx < sz and arr[idx] == target)
                idx++;  // increase to Check for the next element
            else 
                k--;

            // When k is equal Zero -> Then target is the answer
            if(k==0)
                return target;
            // increased anyway
            target++;
        }
        return -1;
    }
};
