// Author: Osama Ayman
// Time: O(nlogn)
// Space: O(1)
class Solution {
    // sort the array apply the 2 pointers strategy
    // because we want to maximize the load on each boat
    // so, taking the larger weight needs to have a light person
    // if the lightest person cant go with the heaviest person,
    // then the heavy person must go alone.
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int res=0;
        int lo=0, hi=people.length-1;
        while(lo<=hi){
            // only 1 person remaining
            if(lo==hi){
                return res+1;
            }
            if(people[lo]+people[hi] <= limit){
                // take the both
                lo++;
                hi--;
            }
            else{
                // take the heaviest alone
                hi--;
            }
            // add the count of boats
            res++;
        }
        
        return res;
    }
}