

// Author: Mohamed Emara
// leetcode account : https://leetcode.com/MohamedEmara


class Solution {
public:

    // Declare global variables to use them in the rec function
    int n;
    int arr[505];
    int dp[505][505];	// idx, time


    int rec(int idx, int time)
    {
    	// base case: When I'm after the last index
        if(idx == n)
            return 0;
        
        // Memoization:    
        int &ret = dp[idx][time];
        if(~ret)
            return ret;

	// At every index, we have 2 options:
	// 	1- to take it and add the value of this index * the day number to the solution
	//	2- to skip this index so that the time will remain the same
        int leave = rec(idx+1, time);
        int take = time * arr[idx] + rec(idx+1, time+1);
    	
    	// maximize between the two options:
        return ret = max(leave, take);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
    	
        n = satisfaction.size();
        for(int i=0; i<n; i++)
            arr[i] = satisfaction[i];

        // As dishes can be prepared in any order,
        // the max output when the array is sorted in non-decreasing order
        
        sort(arr, arr+n);
           
        memset(dp, -1, sizeof(dp)); 
        return rec(0, 1);
    }
};



