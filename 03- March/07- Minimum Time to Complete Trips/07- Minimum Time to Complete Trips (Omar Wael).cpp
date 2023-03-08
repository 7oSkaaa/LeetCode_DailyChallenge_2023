// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    // here is function to check if current time can make at least (totalTrips) trips
    bool can(vector<int>& time, int totalTrips,long long mid,long long &n){
        long long canDo=0;
        for(int i=0;i<n;i++){
            canDo+=mid/time[i];
            if(totalTrips<=canDo){
                return true;
            }
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long n=time.size(),ans;
        // binary search in range 1 and 1e14
        long long l=1,r=100000000000000;
        while(l<=r){
            long long mid=(l+r)/2;
            // check if current mid can make totalTrips trips
            if(can(time,totalTrips,mid,n)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
