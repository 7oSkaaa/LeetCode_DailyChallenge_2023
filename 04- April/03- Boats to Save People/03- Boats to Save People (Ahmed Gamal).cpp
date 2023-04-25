// Author: Ahmed Gamal

// for this problem, we want to find the minimum number of boats required to save all the people
// we can think of this problem greedily, we can sort the people array in ascending order
// after that, we can check if the heaviest person can be saved with the lightest person or not
// otherwise, we can save the heaviest person alone in a boat, and then we can check if the next heaviest person can be saved with the lightest person or not
// we can do this until we reach the lightest person

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // sort the people array in ascending order
        sort(people.begin(), people.end());

        // l: index of the lightest person
        // r: index of the heaviest person
        // ans: number of boats required
        int l = 0, r = int(people.size()) - 1;
        int ans = 0;
        // while there are people to save
        while(l <= r) {
            // save the heaviest person
            ans++;

            // if the heaviest person can be saved with the lightest person
            if(l < r and people[l] + people[r] <= limit) {
                l++, r--;
            } else if(people[r] <= limit) {
                // if the heaviest person can be saved alone
                r--;
            } else {
                l++;
            }
        }

        
        return ans;
    }
};