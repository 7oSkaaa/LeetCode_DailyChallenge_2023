// Author: Osama Ayman
// Time & Space: O(n1⋅n2)
class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        Map<Integer, List<Integer>> hm = new HashMap<>();
        for(int i=0; i<nums2.length; i++){
            hm.computeIfAbsent(nums2[i], k -> new ArrayList<>()).add(i);
        }
        return solve(0, nums1, hm, -1);
    }

    Map<String, Integer> memo = new HashMap<>();
    private int solve(int idx, int[] nums1, Map<Integer, List<Integer>> hm, int rightMostLine){
        // if nums1 array is consumed, no more lines can be connected
        if(idx == nums1.length) return 0;

        String key = idx+","+rightMostLine;
        // if already saved, return it
        if(memo.containsKey(key)) return memo.get(key);
        // if no same number exist in nums2, proceed to next index of nums1
        if(!hm.containsKey(nums1[idx])) return solve(idx+1, nums1, hm, rightMostLine);
        int res = 0;

        for(int bro: hm.get(nums1[idx])){
            int connect = 0;
            // if a line can be connected without intersection, try connecting it
            if(rightMostLine < bro){
                connect += 1 + solve(idx+1, nums1, hm, bro);
                // choose the max result among all possible connections
                res = Math.max(res, connect);
            }
            
        }
        // try not connecting
        int leave = solve(idx+1, nums1, hm, rightMostLine);
        // update result
        res = Math.max(res, leave);
        // save the result
        memo.put(key, res);

        return res;
    }
}