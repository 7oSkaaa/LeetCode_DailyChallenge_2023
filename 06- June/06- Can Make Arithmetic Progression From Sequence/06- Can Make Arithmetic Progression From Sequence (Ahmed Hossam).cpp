// Author: Ahmed Hossam

class Solution {
public:

    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        // Sorting the vector in ascending order
        sort(arr.begin(), arr.end());
        
        // Checking the difference between consecutive elements
        // If the difference is not the same for all elements, return false
        for(int i = 1; i < arr.size() - 1; i++) {
            if(arr[i] - arr[i - 1] != arr[i + 1] - arr[i])
                return false;
        }
        
        // If the difference is the same for all elements, return true
        return true;
    }

};
