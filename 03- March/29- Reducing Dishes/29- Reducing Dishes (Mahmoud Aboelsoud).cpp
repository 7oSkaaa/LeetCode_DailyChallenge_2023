// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to maximize the sum of the products of the satisfaction and the time
    // we can sort the array and then we can go through the array choose to take the current element or not
    // if we take the current element we will multiply it by the time and add it to the sum
    // if we don't take the current element we will just move to the next element and the time will be the same
    // we will use dp to store the maximum sum we can get from the current element and the time
    

    // dp array
    int dp[505][505];
    // the input array (satisfaction array)
    vector<int> v;

    // function to get the maximum sum we can get from the current element and the time
    int get_max(int idx, int ti){
        // if we reached the end of the array we will return 0
        if(idx == v.size()) return 0;

        // if we already calculated the answer we will return it
        if(dp[idx][ti] != -1) return dp[idx][ti];

        // we will take the maximum of the two cases
        // 1- we don't take the current element
        // 2- we take the current element
        int ans = get_max(idx + 1, ti);
        ans = max(ans, v[idx] * ti + get_max(idx + 1, ti + 1));

        // we will store the answer in the dp array and return it
        return dp[idx][ti] = ans;
    }


    int maxSatisfaction(vector<int>& v) {
        // we will sort the array
        sort(v.begin(), v.end()); 
        // we will store the array in the class variable
        this -> v = v;
        // we will initialize the dp array with -1
        memset(dp, -1, sizeof(dp));

        // we will return the maximum sum we can get from the current element and the time (0, 1)
        return get_max(0, 1);
    }
};
