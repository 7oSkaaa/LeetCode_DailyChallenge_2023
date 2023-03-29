// Author: Osama Ayman
class Solution {
    // map to save our result, so we don't recalculate things.
    HashMap<Integer, Integer> dp = new HashMap<>();
    public int mincostTickets(int[] days, int[] costs) {
        return dfs(0, days, costs);
    }
    private int dfs(int idx, int[] days, int[] costs){
        // we reached the end so return
        if(idx==days.length) return 0;
        // if calculated before, return the saved result
        if(dp.containsKey(idx)) return dp.get(idx);
        
        // try purchasing all 3 different tickets on this day

        // buy 1-day pass
        int day1 = costs[0] + dfs(idx+1, days, costs);
        
        // buy 7-day pass
        int day7 = costs[1];
        int newIdx = days.length;
        for(int i=idx+1; i<days.length; i++){
            // the last valid day to travel with 7-day pass is cur day plus 6
            if(days[i] > days[idx]+6){
                newIdx = i;
                break;
            }
        }
        day7 += dfs(newIdx, days, costs);

        // buy 30-day pass
        int day30 = costs[2];
        newIdx = days.length;
        for(int i=idx+1; i<days.length; i++){
            // the last valid day to travel with 7-day pass is cur day plus 29
            if(days[i] > days[idx]+29){
                newIdx = i;
                break;
            }
        }
        day30 += dfs(newIdx, days, costs);
        int res = Math.min(day1, Math.min(day7, day30));
        dp.put(idx, res);
        return res;

    }
}