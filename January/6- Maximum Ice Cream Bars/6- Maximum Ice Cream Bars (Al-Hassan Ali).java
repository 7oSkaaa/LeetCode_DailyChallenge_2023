// Author : Al-Hassan Ali

class Solution {
    public int maxIceCream(int[] costs, int coins) {
        int ans = 0;
        // Sorting Array To Buy ice creams from the minimum cost to the max cost to increase the answer
        Arrays.sort(costs);
        for(int i = 0; i < costs.length && coins > 0; i++) {
            // If there is no enough money we Cannot Buy More!
            if(coins < costs[i]) break;
            // Add Another Ice Cream to Answer
            ++ans;
            // Decrease the Cost of the Ice Cream
            coins -= costs[i];
        }
        return ans;
    }
}
