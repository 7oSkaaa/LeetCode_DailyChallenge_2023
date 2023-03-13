// Author: Mahmoud Aboelsoud

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // by looking at the constraints you find that the answer is between 1 and 2000
        // so you can loop from 1 to 2000 and check if the current number is in the array or not
        // if it is not in the array then you decrement k
        // if k becomes 1 then you return the current number

        // loop from 1 to 2000
        for(int i = 1, j = 0; i <= 2000; i++){
            // if the current number is in the array then increment j (the index of the array)
            if(j < arr.size() && arr[j] == i) j++;
            else{
                // if the current number is 1 return the current number
                if(k == 1) return i;

                // decrement k
                k--;
            }
        }

        // we will never reach this line because the answer is always between 1 and 2000
        // but if you want to remove the warning you can return 0 here
        return 0;
    }
};
