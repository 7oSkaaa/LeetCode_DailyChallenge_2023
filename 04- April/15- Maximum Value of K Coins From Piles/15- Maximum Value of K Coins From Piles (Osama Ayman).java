// Author: Osama Ayman
// let P = number of coins in all the piles
// Time: O(P*k)
// Space: O(n*k)
class Solution {
    public int maxValueOfCoins(List<List<Integer>> piles, int k) {
        return solve(0,k, piles);
    }
    // map to save the computed results
    Map<String, Integer> hm = new HashMap<>();
    private int solve(int pile, int coinsRemaining, List<List<Integer>> piles ){
        // if we reached the end of piles, return 0
        if(pile == piles.size()) return 0;
        
        String key = pile+","+coinsRemaining;
        // if we already calculated the result, return it
        if(hm.containsKey(key)) return hm.get(key);
        
        // skip this pile
        int res = solve(pile+1, coinsRemaining, piles);
        // take from this pile
        int take = 0;
        // we can take 1 coin from this pile or we can take 2 or 3 or 4 or etc... 
        for(int i=0; i<piles.get(pile).size() && i<coinsRemaining; i++){
            take += piles.get(pile).get(i);
            res = Math.max(res, take + solve(pile+1, coinsRemaining - i - 1, piles));
        }
        // save the result
        hm.put(key, res);
        return res;
    }
}
