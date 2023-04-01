// Author: Osama Ayman
class Solution {
    public int ways(String[] pizza, int k) {
        // we need to know in constant time is the current cut in row, col is valid.
        // that is it contains at least 1 apple
        // use prefix sum to accomplish this goal
        // prefix[i][j] represents the number of apples from i,j to the bottom right cell
        int rows=pizza.length, cols=pizza[0].length();
        int[][] prefix = new int[rows+1][cols+1];

        for(int i=rows-1; i>=0; i--){
            for(int j=cols-1; j>=0; j--){
                
                // cur = bottom + right - bottomRight
                prefix[i][j]=prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1];

                // if the cur cell has an apple, add 1
                if(pizza[i].charAt(j)=='A') prefix[i][j]++;

            }
        }
        return solve(0,0,prefix,k-1, pizza);
    }
    // map to save calculated results
    Map<String, Integer> mem = new HashMap<>();
    private int solve(int row, int col, int[][] prefix, int k, String[] pizza){
        String key = row+","+col+","+k;
        if(mem.containsKey(key)) return mem.get(key);
        // base case
        if(prefix[row][col]==0) return 0;
        if(k==0) return 1;
        
        
        int res=0;
        for(int i=row+1; i<pizza.length; i++){
            // horizontal cuts
             // if top row has at least 1 apple
            if(prefix[row][col]-prefix[i][col] > 0){
                res += solve(i, col, prefix, k-1, pizza);
                res %= (int)((1e+9)+7);
                
            }
        }
        for(int j=col+1; j<pizza[0].length(); j++){
            // vertical cuts
            // if left col has at least 1 apple
            if(prefix[row][col]-prefix[row][j] > 0){
                res += solve(row, j, prefix, k-1, pizza);
                res %= (int)((1e+9)+7);
            }
        }

        res %= (int)((1e+9)+7);
        mem.put(key, res);
        return res;

    }
}