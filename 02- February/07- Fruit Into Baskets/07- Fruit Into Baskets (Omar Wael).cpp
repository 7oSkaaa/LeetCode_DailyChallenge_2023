// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>baskets;
        // two pointers to select the start and end points
        int l=0,r=0;
        int ans=0,n=fruits.size(),mx=0;
        while(r<n){
            // if you can collect this fruit to check this condition
            // you should check if you have less than two types of fruits 
            // or this is one of types you have collected
            if(baskets.size()<2 || baskets.find(fruits[r])!=baskets.end()){
                // update ans
                ans++;
                // add this fruit
                baskets[fruits[r]]++;
                // update end point
                r++;
            }else{
                if(baskets[fruits[l]]==1){
                    baskets.erase(fruits[l]);
                }else{
                    baskets[fruits[l]]--;
                }
                ans--;
                l++;
            }
            // update max answer
            mx=max(mx,ans);
        }
        return mx;
    }
};