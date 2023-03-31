// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0;i<flowerbed.size();i++){
            // check if current plot is empty
            // and last(if there) plot is empty
            // and next(if there) plot is empty
            if(flowerbed[i]==0 && (i+1>=flowerbed.size() || flowerbed[i]==flowerbed[i+1]) && (i==0 || flowerbed[i]==flowerbed[i-1])){
                flowerbed[i]=1;
                n--;
            }
            // return true if all needed plots are planted
            if(n<1){
                return true;
            }
        }
        return false;
    }
};
