// Author: Eileanora
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int sz = fruits.size();
        // first is fruit type and second is how many fruits of this type
        map <int , int> freq;
        // we will use sliding window technique
        /*
            we will keep track of how many types of fruits we have using a map
            1- we will move right pointer until we have 2 types of fruits
            2- when we exeed 2 types, we will move left pointer until we have 2 types of fruits
            3- with every step we will take the max between ans and r - l
        */
        int l = 0 , r = 0; 
        while(r < sz)
        {
            while(r < sz && int(freq.size()) <= 2) // case 1
            {
                freq[fruits[r]]++;
                r++;
            }
            ans = max(ans , r - l - 1); 
            while(int(freq.size()) > 2) // case 2
            {
                freq[fruits[l]]--;
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                l++;
            }
        }
        ans = max(ans , r - l); // take the max after we are done to make sure we take the last window
        return ans;
    }
};