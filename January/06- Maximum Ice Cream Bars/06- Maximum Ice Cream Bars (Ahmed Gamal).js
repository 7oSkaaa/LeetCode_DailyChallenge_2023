// Author: Ahmed Gamal
/**
 * @param {number[]} costs
 * @param {number} coins
 * @return {number}
 */
var maxIceCream = function(costs, coins) {
    // to make sure that we are going to buy the maximum number of ice cream bars, we need to take the cheapest bar possible at each step until we run out of money
    // sort the costs of bars in ascending order
    costs.sort((a, b) => a - b);

    // iterate over the costs from cheapest to the most expensive one, and pick as many bars as you can
    for(let i = 0; i < costs.length; i++){
        // if you can't buy the cheapest bar available, you can't buy any other bar you will encounter
        // because the next bars' costs will be at least equal to the current cost, so you can return the answer immediately
        if(costs[i] > coins)
            // by reaching this bar, that means you bought all of the previous bars you encountered, so you can just return the index if the current bar
            // and because the array is 0-indexed, the current index will indicate that you have encountered i elements before
            return i;
        // by subtracting the current cost from the total coins, you are calculating the remaining coins after you buy this bar
        coins -= costs[i];
    }
    // if you finished the loop without returning and exiting the function, that means you could buy all of the bars you encountered
    return costs.length;
};