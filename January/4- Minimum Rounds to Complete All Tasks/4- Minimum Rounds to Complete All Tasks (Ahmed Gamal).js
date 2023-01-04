// Author: Ahmed Gamal

/**
 * @param {number[]} tasks
 * @return {number}
 */

var minimumRounds = function(tasks) {
    // an object to store frequencies
    freq = {}
    
    for(let i of tasks){
        // if there's no key created for this element, then create it and initialize its value to 0
        if(!freq[i])
            freq[i] = 0;
        freq[i]++;
    }

    let ans = 0;
    for(let i of tasks){
        // the only number that can't be represented as a summation of twos and threes is 1
        // once we find a number with a frequency equals to 1, we should know that it's impossible to complete the tasks
        if(freq[i] === 1)
            return -1;
        
        // maximum number of threes we can put in the representation of this frequency
        let cntThree = parseInt(freq[i] / 3);

        // the remaining number of tasks after we group every three elements together
        let rem = freq[i] - cntThree * 3;

        // we want to find the maximum number of groups of size 3 to take so that the remaining number of tasks is divible by 2
        // if the remaining number is not divisible by 2 then, we should subtract 3 (odd number) from the number of tasks that we grouped before
        // if the remaining number is not divisible by 2 and we subtracted 3 from the tasks we grouped, then we should add it to the remaining tasks
        // finally, divide the remaining tasks by 2 to know the number of groups of 2 we can construct
        ans += cntThree - rem % 2 + (rem + rem % 2 * 3) / 2;

        // after calculating the answer for this value for the first time, set the value to 0 to avoid using it again in the future
        freq[i] = 0;
    }

    return ans;
};