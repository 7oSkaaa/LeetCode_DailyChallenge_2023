// Author: Mahmoud Aboelsoud

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // we use sliding window technique to find the maximum length of subarray with at most 2 distinct elements
        // we use an unordered_map to store the number of occurences of each element in the subarray
        
        // initialize the map and the answer and the left pointer
        unordered_map<int,int> ma;
        int ans = 0, l = 0;
        // loop over the array
        for(int i = 0; i < fruits.size(); i++){
            // add the current element to the map
            ma[fruits[i]]++;

            // if the map size is greater than 2, we need to remove elements from the left of the subarray
            while(ma.size() > 2){
                ma[fruits[l]]--;
                // if the number of occurences of the element is 0, we remove it from the map
                if(!ma[fruits[l]])
                    ma.erase(fruits[l]);
                l++;
            }

            // update the answer
            ans = max(ans, (i - l + 1));   
        }

        return ans;
    }
};
