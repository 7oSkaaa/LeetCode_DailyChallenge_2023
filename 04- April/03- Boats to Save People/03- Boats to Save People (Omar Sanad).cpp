// author : Omar Sanad
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      
        // sort the vector "people"
        sort(people.begin(), people.end());

        // initializing two pointers l at the begining of the array, and r at the end of the array
        int l = 0, r = people.size() - 1, boats = 0;

        // Two pointers movement
        while (l < r) {
            boats++;
            if (people[l] + people[r] <= limit) // if we can take the person at l with the person at r at the same boat
                l++, r--;                       // then remove them from the array
            else        // If we can't take both of them at the same boat
                r--;    // we take the person at r only, then we remove them from the array
        }

        return boats + (l == r);    // if l == r then there is one person left we have to take them in a single boat
    }
};
