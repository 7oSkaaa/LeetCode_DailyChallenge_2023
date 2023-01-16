// Author: Salah Ashraf

class Solution {
    public int maxIceCream(int[] costs, int coins) {
      //sort the array ascendingly
        Arrays.sort(costs);
        int ans=0;
        while (coins !=0 && ans != costs.length){
            //if coins is enough then minus the cost[ans] from coins and  increment the ans  
            if(costs[ans] <= coins){
                coins -= costs[ans];
                ans++;
            }
            //else break
            else break;
        }
        return ans;
    }
}
