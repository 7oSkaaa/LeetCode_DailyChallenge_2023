// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to find the number of potions that can be used with each spell
    // we can use binary search to find the number of potions that can be used with each spell
    // we just need to sort the potions and for each spell we need to find the first potion that can be used with it
    // then we can find the number of potions that can be used with it by subtracting the index of the first potion from the size of the potions vector
    // if the first potion that can be used with the spell is not found then we can't use any potion with this spell
    // so we will add 0 to the answer vector

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // size of the spells vector
        int n = spells.size();
        // sort the potions vector
        sort(potions.begin(), potions.end());
        // answer vector
        vector<int> ans(n);

        // for each spell
        for(int i = 0; i < n; i++){
            // find the first potion that can be used with this spell
            int l = 0, r = potions.size() - 1, best = potions.size();
            while(l <= r){
                int m = l + (r - l) / 2;
                // if the product of the spell and the potion is greater than or equal to success
                // then we can use this potion with this spell and every potion after it
                if(spells[i] * (long long)potions[m] >= success) r = m - 1, best = m;
                else l = m + 1;
            }
            // add the number of potions that can be used with this spell to the answer vector
            ans[i] = potions.size() - best;
        }
        // return the answer vector
        return ans;
    }
};
