// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    double average(vector<int>& salary) {
        int mn=INT_MAX,mx=0;
        double ave=0;
        for(auto i:salary){
            // get min element
            if(i<mn){
                mn=i;
            }
            // get max element
            if(i>mx){
                mx=i;
            }
            // add current element to the sum
            ave+=i;
        }
        // subtract min and max element from the sum
        ave-=(mx+mn);
        // devide the sum by the number of elements
        ave/=salary.size()-2;
        // return the average
        return ave;
    }
};
