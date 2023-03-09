// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    // function to check if koko can eat mid bananas at each hour and eat all bananas
    bool can(vector<int>& piles, int h,int n,int mid){
        int totalHours=0;
        for(int i=0;i<n;i++){
            if(piles[i]%mid==0){
                totalHours+=piles[i]/mid;
            }else{
                totalHours+=(piles[i]/mid) +1;
            }
            if(totalHours>h){
                return false;
            }
        }
        if(totalHours<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size(),ans;
        // binary search in range 1 and 1e9
        int l=1,r=1000000000;
        while(l<=r){
            int mid=(l+r)/2;
            // check if current mid can koko eat all bananas
            if(can(piles,h,n,mid)){
                r=mid-1;
                ans=mid;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};
