// Author: Osama Ayman
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        if(n==0) return true;
       int cnt=0;
       // For each index just check the prev, current and next.
       // If all 3 indxes are empty then you can plant a flower here. 
       // But, you can NOT in the next index. So, don't forget to increease the iterator, so that you skip the next idx.
        for(int i=0; i<flowerbed.length; i++){
            if((i-1==-1 || flowerbed[i-1]==0) && flowerbed[i]==0 && (i+1==flowerbed.length || flowerbed[i+1]==0)){
                cnt++;
                i++;
            }
        }
        return cnt >= n;
    }
}