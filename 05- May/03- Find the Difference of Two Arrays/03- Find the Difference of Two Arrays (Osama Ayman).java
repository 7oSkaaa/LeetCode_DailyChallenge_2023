// Author: Osama Ayman
// Time: O(n)
// Space: O(n)
class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        List<List<Integer>> res = new ArrayList<>();
        // Initilaize 2 sets: one for numbers found in nums1 but not nums2
        // and the other is for numbers found in nums2 but not nums1
        Set<Integer> in1Not2 = new HashSet<>(), in2Not1 = new HashSet<>();

        for(int i=0; i<nums1.length; i++){
            // add all numbers in nums1 to first set
            in1Not2.add(nums1[i]);
        }
        for(int i=0; i<nums2.length; i++){
            // add all numbers in nums2 to second set
            in2Not1.add(nums2[i]);
            // remove numbers found in nums2 from first set
            in1Not2.remove(nums2[i]);
        }
        for(int i=0; i<nums1.length; i++){
            // remove numbers found in nums1 from second set
            in2Not1.remove(nums1[i]);
        }
        // copy numbers from the sets to lists
        List<Integer> first = new ArrayList<>(), second = new ArrayList<>();
        for(int n: in1Not2) first.add(n);
        for(int n: in2Not1) second.add(n);
        res.add(first);
        res.add(second);
        return res;
    }
}