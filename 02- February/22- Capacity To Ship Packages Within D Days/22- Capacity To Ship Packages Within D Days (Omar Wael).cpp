// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search on available values wich is in range max weight and total weights
        int l=1,r=0;
        for(int i=0;i<weights.size();i++){
            r+=weights[i];
            l=max(l,weights[i]);
        }
        while(l<=r){
            int mid=(l+r)/2;
            // if it valid to take current value 
            // then try to get value less than it
            if(valid(weights,mid,days)){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
    bool valid(vector<int>& weights,int mid,int days){
        int sum=0;
        // count how many days needed to ship this weights 
        // if it less than or equal days return true 
        // else return false
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i]>mid){
                sum=0;
                days--;
            }
            sum+=weights[i];
        }
        if(days<=0){
            return false;
        }
        return true;
    }
};

