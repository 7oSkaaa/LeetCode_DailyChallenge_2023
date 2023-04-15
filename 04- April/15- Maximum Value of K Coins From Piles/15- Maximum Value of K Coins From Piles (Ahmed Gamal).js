// Author: Ahmed Gamal

// for this problem we will use dp to find the maximum value of k coins from piles
// dp[i][j]: the maximum value of j coins from piles starting from pile i (i: pile index, j: number of coins)
// and since we can only take coins from the end of the pile, we will use the prefix sum array to find the maximum value of j coins from piles starting from pile i
// because the maximum value of choosing j coins from the end of the pile is the sum of the last j coins in the pile

// we can do this prefix sum inplace by iterating over the piles array and updating the current element with the sum of the current element and the previous element
// then we can iterate over the possible number of coins we can take from the end of the pile and find the maximum value of choosing j coins from the end of the pile

/**
 * @param {number[][]} piles
 * @param {number} k
 * @return {number}
 */
var maxValueOfCoins = function(piles, k) {
    // prefix sum
    piles.forEach(pile => {
        for(let i = 1; i < pile.length; i++) {
            pile[i] += pile[i - 1];
        }
    });

    // memo: memoization array
    // n: number of piles
    let memo = [];
    const n = piles.length;

    // dp: dp function
    // idx: pile index
    // rem: number of coins remaining
    let dp = (idx, rem) => {
        // if we reached the end of the piles array
        if(idx >= n) {
            // if we took all the coins return 0 else return -1e10 (negative infinity)
            return rem ? -1e10 : 0;
        }

        // if this state is undefined, initialize it
        if(!memo[idx]) {
            memo[idx] = [];
        }
        // if we already calculated this state return the result
        if(memo[idx][rem]) {
            return memo[idx][rem];
        }

        // ret: the maximum value of choosing rem coins from piles starting from pile idx

        // try to take 0 coins from the end of the pile
        let ret = dp(idx + 1, rem);

        // try to take 1..min(rem, piles[idx].length) coins from the end of the pile
        for(let i = 1; i <= rem; i++) {
            // if we reached the end of the pile break
            if(i - 1 >= piles[idx].length) {
                break;
            }
            // update ret with the maximum between ret and the maximum value of choosing rem - i coins from piles starting from pile idx + 1 plus the sum of the last i coins in the pile
            ret = Math.max(ret, piles[idx][i - 1] + dp(idx + 1, rem - i));
        }

        // memoize the result
        memo[idx][rem] = ret;

        // return the result
        return memo[idx][rem];
    };

    // return the maximum value of choosing k coins from piles starting from pile 0
    return dp(0, k);
};