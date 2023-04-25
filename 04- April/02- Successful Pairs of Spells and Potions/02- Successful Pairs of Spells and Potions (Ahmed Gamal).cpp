// Author: Ahmed Gamal

// for this problem, we want to find the number of pairs that satisfy the condition (spells[i] * potions[j] >= success)
// we can use binary search to solve this problem since we can sort the potions array and then for each spell, we can find the number of potions that satisfy the condition
// to do this, we can search for the smallest number that satisfies the condition, and then all the numbers greater than it will also satisfy the condition

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // pairs[i] = number of potions that satisfy the condition (spells[i] * potions[j] >= success) for each spell
        vector<int> pairs;

        // n: number of spells
        const int n = int(spells.size());

        // sort the potions array in descending order (to use it easily from left to right)
        sort(potions.rbegin(), potions.rend());

        // for each spell, find the number of potions that satisfy the condition (spells[i] * potions[j] >= success)
        for(int i = 0; i < n; i++) {
            int left = -1, right = (int)potions.size();    

            while(left < right - 1) {
                int mid = left - (left - right) / 2;

                if(1ll * potions[mid] * spells[i] >= success) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            // left: the index of the smallest potion that satisfies the condition (-1 if there is no one)
            pairs.emplace_back(++left);
        }

        return pairs;
    }
};