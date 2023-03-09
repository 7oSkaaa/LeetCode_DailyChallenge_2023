//Author: Walaa AbdElhady

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //search space of bs
        int l = 1, r = 1e9, ans = -1;
        while (l <= r) {
            int md = l + (r - l) / 2;
            //if the k is valid to eat all bananas in h hours search for smaller if found
            if (valid(md, piles, h))ans = md, r = md - 1;
            // else  try to search for larger k to eat all bananas
            else l = md + 1;
        }
        // return min numberOfBananas should eat in one hour
        return ans;
    }
    bool valid(int k, vector<int>& piles, int h) {
        long long curHour = 0;
        // loop to calculate total hours to eat all bananas
        for (int i = 0; i < piles.size(); i++) {
            //divide the number of bananas in each pile by k
            curHour += piles[i] / k;
            // if the mod of number of bananas in each pile by k is not zero increase curHour by one
            if (piles[i] % k)curHour++;
        }
        // return true if the number of hours to eat all the bananas is less than or equal to h
        return curHour <= h;
    }

};