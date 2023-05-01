// Author: Osama Ayman
// Time: O(n)
// Space: O(1)
class Solution {
    public double average(int[] salary) {
        int max = -1, min = Integer.MAX_VALUE;
        double res = 0;
        for(int sal: salary){
            // updating max
            max = Math.max(max, sal);
            // updating min
            min = Math.min(min, sal);
            // adding all salaries
            res += sal;
        }
    // removing the max
    res -= max;
    // removing the min
    res -= min;
    // calculating the average
    res /= (salary.length-2);
    return res;
    }
}