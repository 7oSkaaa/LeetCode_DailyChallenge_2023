// Author: Ahmed Gamal

// for this problem we can check the max number of flowers we can plant in the flowerbed and compare it with n
// we can plant a flower in the flowerbed if the current position is empty and the previous and next positions are empty
// we just need to consider the first and last positions to avoid out of bounds errors

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // the size of the flowerbed
        const int sz = int(flowerbed.size());

        for(int i = 0; i < sz; i++) {
            // if the previous position is not empty, we can't plant a flower here
            if(i and flowerbed[i - 1])
                continue;

            // if the next position is not empty, we can't plant a flower here
            if(i < sz - 1 and flowerbed[i + 1])
                continue;
            
            // if the current position is empty, we can plant a flower here (decrease n)
            if(not flowerbed[i]) {
                flowerbed[i] = 1;
                n--;
            }            
        }

        // if n is not positive, we can plant all flowers, otherwise we can't because we ran out of empty positions before planting all flowers
        return n <= 0;
    }
};