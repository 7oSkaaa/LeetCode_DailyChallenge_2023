// Author: Ahmed Gamal
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
let canCompleteCircuit = function(gas, cost) {
    // the size of the array for the ease of use
    const n = gas.length;

    // we will try to start at each point and complete a circular tour, if we couldn't complete it, we will try to start from the point we are at currently
    // if we came to the current point while having a negative total summation, that means we can't move from the current start we chose to this point
    // so, we will try to start from here and complete another circular tour with a new summation

    // a counter to count how many times we couldn't proceed and restarted our tour to prevent entering in an infinite loop
    // a variable to keep track of the current summation we have (cumulative sum of gas - cumulative sum of cost)
    // a variable to store the length we reached now in the current tour, to know when we complete the tour (n travels)
    // a variable to store the last index we had to start from, if this didn't change until the end of the tour, that means this is a valid starting point
    let cntRestarts = 0, curr = 0, len = 0, ans = 0;

    // we will start from 0 as a starting point and keep moving forward in a circular way until we break the loop
    // i = (i + 1) % n will start from the beginning of the array again after we reach the end of it
    for(let i = 0; ; i = (i + 1) % n){
        len++; // a new step in our tour
        if(curr < 0){ // if we can't reach this point
            curr = 0; // restart the sum
            ans = i; // try to start at this point
            len = 0; // restart the length of the new tour
            cntRestarts++; // now, we have a new restart of the tour
        }
        curr += gas[i] - cost[i]; // add the gas of the current station and subtract the cost to travel to the next one
        if(cntRestarts >= n){ // if we restarted the tour n or more times, this indicates that we can't complete a tour at all
            ans = -1;
            break;
        }
        if(len === n){ // if we completed n steps of our current tour
            // we check if we did the last step correctly (we have a non-negative sum and we can complete the tour)
            // if we can't, we set our answer to -1
            ans = curr < 0 && -1 || ans;
            break;
        }
    }

    return ans;
};