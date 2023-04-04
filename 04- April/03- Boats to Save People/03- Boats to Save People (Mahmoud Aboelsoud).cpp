// Author: Mahmoud Aboelsoud

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // each boat can carry at most 2 people at the same time, provided the sum of the weight of those people is at most limit
        // so we need to sort the people and start from the lightest and the heaviest and try to put them in the same boat
        // if the sum of their weights is less than or equal to the limit, then we can put them in the same boat
        // otherwise, we put the heaviest person in a boat and move to the next heaviest person

        // sort the people
        sort(people.begin(), people.end());
        // l is the index of the lightest person, r is the index of the heaviest person, ans is the number of boats
        int l = 0, r = people.size() - 1, ans = 0;

        // while there are still people to put in boats
        while(l <= r){
            // if the sum of the weights of the lightest and the heaviest people is less than or equal to the limit
            // then we can put them in the same boat and move to the next lightest and the previous heaviest people
            if(people[l] + people[r] <= limit) l++, r--, ans++;
            // otherwise, we put the heaviest person in a boat and move to the previous heaviest person
            else ans++, r--;
        }
        
        // return the number of boats
        return ans;
    }
};
