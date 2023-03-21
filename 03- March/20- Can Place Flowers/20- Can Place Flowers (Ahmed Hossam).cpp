// Author: Ahmed Hossam

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // insert 0 at the back of the vector
        flowerbed.push_back(0);

        // insert 0 at the front of the vector
        flowerbed.insert(flowerbed.begin(), 0);

        // check every subarray with size 3 if all of them = 0
        for(int i = 1; i < flowerbed.size() - 1; i++){
            if(!flowerbed[i] && !flowerbed[i - 1] && !flowerbed[i + 1]){
                // if is valid subarray so make the middle of them equal 1
                flowerbed[i] = 1, n--;
            }
        }

        // if we can put n flowers in the array
        return n <= 0;
    }
};
