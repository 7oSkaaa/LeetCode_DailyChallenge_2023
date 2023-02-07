// author: Esraa Syam
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // use sliding window to find the longest subarray with at most 2 different elements
        // use unordered_map to store the frequency of each element
        // not map because it's sorted and we don't need it to be sorted
        // use two pointers l and r to represent the sliding window
        // use maxi to store the maximum length of the subarray
        unordered_map < int , int > mp;  
        int l = 0 , r = 0 , maxi = 0;
        while(r < fruits.size()){
            // while the size of the map is smaller than 2
            // we can add the current element to the map
            mp[fruits[r]]++;
            // if the size of the map is bigger than 2
            // we need to remove the first element from the map
            // to make the size of the map equal 2
            while(mp.size() > 2){
                mp[fruits[l]]--;
                // if the frequency of the first element is 0
                // we need to remove it from the map
                // to remove it from our calculation
                if(!mp[fruits[l]]) mp.erase(fruits[l]);
                l++;
            }
            // update the maximum length of the subarray
            maxi = max(maxi , r - l + 1);
            r++;
        }
        return maxi;
    }
};