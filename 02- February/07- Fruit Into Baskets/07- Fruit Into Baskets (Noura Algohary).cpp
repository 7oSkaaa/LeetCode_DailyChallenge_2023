// Author: Noura Algohary
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> baskets;  // unordered_map to store fruits by occorrance 
        int left = 0, res = 0;            // left from where to start counting
        
        for (int right = 0; right < fruits.size(); right++) {
            baskets[fruits[right]]++;


            // there are two baskets, each of them can stoer only one type of fruits
            // if there is more than 2 types of fruits, the last two ones stay
            while (baskets.size() > 2) {
                baskets[fruits[left]]--;
                if (baskets[fruits[left]] == 0)
                    baskets.erase(fruits[left]);
                left++;
            }
            
            if(right - left + 1 > res)
                res = right - left + 1;
        }
        
        return res;
    }
};