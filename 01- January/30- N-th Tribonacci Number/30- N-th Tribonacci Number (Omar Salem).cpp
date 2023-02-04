// Author: Omar Salem
class Solution {
public:
    int tribonacci(int n) {
        //creat a vector of three initial value 0,1,1
        vector < int > ans{0,1,1};
        // add a summation of last three value 
        for(int i = 3 ; i <= n ; i++)
            ans.push_back(ans[i-1] + ans[i-2] +ans[i-3]);
        // return the N-th tribonacci number
        return ans[n];
    }
};

