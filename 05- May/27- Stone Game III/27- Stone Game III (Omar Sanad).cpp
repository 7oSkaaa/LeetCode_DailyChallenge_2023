// author : Omar Sanad

/* We can solve this problem using dynamic programming
we will try for each player to take 1, 2, or 3 stones,
To mark who will win, we can take the sum of Alice's stones as positive, and sum of Bob's stones as negative,
In Alice's turn she will try to maximize the result, as if the final result is positive she wins
In Bob's turn he will try to minimize the resutl, as if the final result is negative he wins
If the final result is zero, it's a tie
 */
class Solution {
public:
    // declaring a dp table for memoization
    // declaring n (the size of the stones array)
    int dp[50005][2], n;

    // declare the stones array inside the class itself, to use it anywhere inside the class
    vector<int> stoneValue;

    // the recursion function
    int rec(int idx, bool Alice_turn) {
        // if we have no stones, we end the game
        if (idx >= n)
            return 0;
        
        // initializing a variable ret to store the dp of the current state by reference to it, for ease use
        int &ret = dp[idx][Alice_turn];

        // if we have already calculated this state, then no need to calc it again, we just return its stored value
        if (~ret)   return ret;

        // else we initialize the ret with either one of the two values
        // If this is Alice's turn, we initialize it to INT_MIN, as Alice wants to maximize
        // else if this Bob's turn, we initialize it to INT_MAX, as Bob wants to minimize
        ret = Alice_turn ? INT_MIN : INT_MAX;

        // declare a variable to store the curren sum which we will store the sum of 1st element, then 1st and 2nd, then 1st,2nd, and 3rd stones
        int curSum = 0;

        // if this is Alice's turn, we would like to maximize the answer, and we will add the sum as positive
        if (Alice_turn) {   // I need to maximize
            for (int i = 0; i < 3 && i + idx < n; i++) {
                curSum += stoneValue[idx + i];
                ret = max(ret, curSum + rec(i + idx + 1, !Alice_turn));
            }
        }
        // else if it's Bob's turn, we would like to minimize the answer, and we will add the sum as negative
        else{  // I need to minimize
            for (int i = 0; i < 3 && i + idx < n; i++) {
                curSum -= stoneValue[idx + i];
                ret = min(ret, curSum + rec(i + idx + 1, !Alice_turn));
            }
        }

        // return the answer of this state
        return ret;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        // fill the dp table with -1, mark as not yet calculated
        memset(dp, -1, sizeof(dp));

        // assign the given stoneValue to the stoneValue which is declared inside the class itself
        this->stoneValue = stoneValue;

        // assign the size of the given array to n
        n = stoneValue.size();

        // return the answer to the problem
        // if the answer is "positive" -> "Alice"
        // if "negative" -> "Bob"
        // if "ZERO" -> "Tie"
        return rec(0, true) > 0 ? "Alice" : rec(0, true) < 0 ? "Bob" : "Tie";
    }
};
