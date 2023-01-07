class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int ans = 0;
        Arrays.sort(costs);
        for(int i = 0; i < costs.length && coins > 0; i++) {
            if(coins < costs[i]) break;
            ++ans;
            coins -= costs[i];
        }
        return ans;
    }
}