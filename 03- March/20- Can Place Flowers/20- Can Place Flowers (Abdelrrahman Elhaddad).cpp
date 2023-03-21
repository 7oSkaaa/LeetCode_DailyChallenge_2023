//Author: Abdelrrahman Elhaddad

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int num) {
        int n = flowerbed.size();
      
      // Checking whether the size is equal to one then there will be to cases to return true:
      // 1- If the the first (and only) element equals to 0 and num is less than or equal to 1
      // 2- If the the first (and only) element equals to 1 and num is equal to 0
      // Otherwise it will return false
        if (n == 1)
            return (flowerbed[0] == 0 && num <= 1) || (flowerbed[0] == 1 && num == 0);
      
      // Initialzie a variable to count valid indexes
        int c = 0;
      
      // Checking whether the first and last elements are valid and could be counted or not
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            c++;
            flowerbed[0] = 1;
        }
        if (flowerbed[n - 2] == 0 && flowerbed[n - 1] == 0) {
            c++;
            flowerbed[n - 1] = 1;
        }

      /* Iterating through all the elments and checking whether the index is valid by confirming that
       its value, the value behind it and the value in front of it all of them are 0,
       If so increment c and convert that index value to 1 */
        for (int i = 1; i < flowerbed.size() - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                c++;
                flowerbed[i] = 1;
            }
        }
      
      // Return true if c >= n, Else return false
        return c >= num;
    }
};
