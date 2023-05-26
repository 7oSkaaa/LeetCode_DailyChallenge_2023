// Author: Emad Mohamed
 /*
0 -> Alice’s turn 
1 -> Bob’s turn
We will use dp to try all the possible solutions. 
We are calculating dp relative to Alice only so
If turn is 0 (Alice’s turn) then dp refers to the highest score Alice can get. 
If turn is 1 (Bob’s turn) then dp refers to the lowest score Alice can get from that position. 
So Alice will try to maximize the result because that is her score 
while Bob will try to find the minimum result because it’s Alice’s score. 
Thus we will only add the sum in Alice’s turn.
*/
class Solution {
    int dp[100][1001][2], n;
    int findBest(int idx, int m, bool turn, vector<int>&piles){
        if(idx == n)
            return 0;
        int& ret = dp[idx][m][turn];
        if(~ret) return ret;
        if(!turn){
            //Alice will try to maxmimize
            ret = INT_MIN;
            int sum = 0;
            for(int x = 1; x <= 2 * m && idx + x <= n; x++){
                sum += piles[idx + x - 1];
                ret = max(ret, sum + findBest(idx + x, max(m, x), !turn, piles));
            }
        }else{
            //Bob will try to minimize
            ret = INT_MAX;
            for(int x = 1; x <= 2 * m && idx + x <= n; x++)
                ret = min(ret, findBest(idx + x, max(m, x), !turn, piles));
        }
        return ret;
    }
public:
    int stoneGameII(vector<int>& piles) {
        memset(dp, -1, sizeof(dp));
        n = piles.size();
        return findBest(0, 1, 0, piles);
    }
};
