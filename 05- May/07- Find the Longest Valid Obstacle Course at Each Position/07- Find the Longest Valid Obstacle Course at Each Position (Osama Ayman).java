// Author: Osama Ayman
// Time: O(nlogn)
// Space: O(n)
class Solution {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length;
        int[] res = new int[n];
        // ending[i] stores the last number of the sequence of length i
        int[] ending = new int[n];
        
        // the real size of ending array
        int size = 0;
        for(int i=0; i<n; i++){
            int insertIdx = find(ending, obstacles[i], size);
            // if the cur number should be inserted at the end, increaase 
            // the size
            if(insertIdx == size){
               size++;
            }
            // insert the number
            ending[insertIdx] = obstacles[i];
            // res is the idx+1
            res[i] = insertIdx+1;
        }
        return res;
    }
    // find where the target should be placed
    private int find(int[] ending, int target, int right){
        if (right == 0) return 0;
        int left = 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (ending[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
}