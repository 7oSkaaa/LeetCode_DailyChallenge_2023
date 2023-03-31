// Author: Ahmed Hossam

class Solution {
public:

    int maxSatisfaction(vector < int >& a) {                
        // size of the satisfaction vector
        int n = a.size();
        
        // sorting the satisfaction vector in non-decreasing order
        sort(a.begin(), a.end());

        // initializing variables for storing maximum satisfaction, current sum, and total sum
        int MaxAns = 0, currSum = 0, Sum = 0;
        
        // iterating over the dishes in reverse order
        for(int i = n - 1; i >= 0; i--){
    
            // adding the satisfaction of the current dish to the current sum
            currSum += a[i];
    
            // adding the current sum to the total sum
            Sum += currSum;
    
            // updating the maximum satisfaction with the maximum of current and previous satisfactions
            MaxAns = max(MaxAns, Sum);
        }

        // returning the maximum satisfaction for cooking the dishes with minimum time 1
        return MaxAns;
    }
};
