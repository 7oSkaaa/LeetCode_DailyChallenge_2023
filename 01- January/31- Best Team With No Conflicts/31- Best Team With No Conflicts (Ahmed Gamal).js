// Author: Ahmed Gamal

/**
 * @param {number[]} scores
 * @param {number[]} ages
 * @return {number}
 */

// for this problem, we want to pick the best team with no conflicts (no player is older than another player and has a lower score)
// this is can be seen as a knapsack problem with the constraint that we can't pick a player if he is older than another player with a lower score
// to avoid this, we can sort the players by their score first (to make sure that we are picking the player with the highest score until now)
// then we can sort the players by their age to meet the younger players first (because when we compute the dp, we will only consider the players with a lower or equal age than the current player, and want to guarantee that all the previous states are already computed)
// dp[i][j] = max score of a team with i players and the last picked player is j years old
// for each player, we can either include him or not (knapsack)
// if we pick him, we can only pick players with a lower or equal age than him, so we can only consider the previous states with a lower or equal age than him (because he has the highest score until now)
// if we don't pick him, we can just consider the previous state (because we are not picking him, so we can pick any player with a lower or equal age than him)
// so the transition is dp[i][j] = max(dp[i - 1][j], dp[i - 1][k] + score[i]) for all k <= j
// we can optimize the space complexity to O(n) by using rolling array (we only need the previous state)
// the time complexity is O(n^2) because we are iterating over all the players and for each player we are iterating over all the previous states

var bestTeamScore = function(scores, ages) {
    // dp: dp[i][j] = max score of a team with i players and the last picked player is j years old (but we are using rolling array with only 2 rows (prev and current))
    let dp = [...Array(2)].map(x => Array(1001).fill(0));

    // arr: array of objects with the age and score of each player (sorted by score first and then by age)
    let arr = [];
    scores.forEach((x, idx) => {
        arr.push({age: ages[idx], score: x});
    });

    // sort by score first and then by age
    arr.sort((a, b) => {
        if(a.score === b.score)
            return a.age - b.age;
        return a.score - b.score
    });

    // n: number of players
    const n = scores.length;

    // ans: the answer
    let ans = 0;
    
    // iterate over all the players
    for(let i = 1; i <= n; i++){
        // prev: the previous state
        const prev = 1 - i % 2;

        // age and score of the current player (destructured from the object)
        const {age, score} = arr[i - 1];

        // mx: the maximum score of the previous states with a lower or equal age than the current player
        let mx = 0;

        // iterate over all the previous states (all possible ages)
        for(let j = 1; j <= 1000; j++){
            // if the current player is older than the current age, we can't pick him, so we just consider the previous state
            dp[i % 2][j] = dp[prev][j];

            // if the current player is younger than the current age, we can pick him, so we consider the previous state with a lower or equal age than him
            if(j <= age)
                mx = Math.max(mx, dp[i % 2][j]);
        }

        // pick the current player (add his score to the maximum score of the previous states with a lower or equal age than him)
        dp[i % 2][age] = mx + score;

        // update the answer with the maximum score of the current state
        ans = Math.max(ans, dp[i % 2][age]);
    }

    // return the answer
    return ans;
};