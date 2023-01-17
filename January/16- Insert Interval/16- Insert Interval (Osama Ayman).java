// Author: Osama Ayman
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        // As the size of the merged intervals is not known, use a 
        // list & convert it to array at the end
        List<int[]> merged = new ArrayList<>();
        int strt = 0;
        boolean added = false;
        if(intervals.length == 0 || intervals[0][0] >= newInterval[0]) {
            merged.add(newInterval);
            added = true;
            }
        else {
            merged.add(intervals[0]); 
            strt=1;
            }

        int[] lastAdded = merged.get(merged.size()-1);
        for(int i=strt; i<intervals.length; i++){
            
            if(!added && newInterval[0] < intervals[i][0]){
                
                if(newInterval[0] <= lastAdded[1]){
                    lastAdded[1] = Math.max(lastAdded[1], newInterval[1]);
                }
                else {
                    merged.add(newInterval);
                    lastAdded = newInterval;
                }
                added=true;
                i--;
            }
            else{
                if(intervals[i][0] <= lastAdded[1]){
                    lastAdded[1] = Math.max(lastAdded[1], intervals[i][1]);
                }
                else {
                    merged.add(intervals[i]);
                    lastAdded = intervals[i];
                }
            }
        }
        // checking if newInterval is not added after looping over 
        // all intervals
        if(!added){
            if(newInterval[0] <= lastAdded[1]){
                    lastAdded[1] = Math.max(lastAdded[1], newInterval[1]);
            }
            else merged.add(newInterval);
        }

    // Just converting list to array
    int[][] res = new int[merged.size()][2];
    for(int i=0; i<merged.size(); i++){
        res[i] = merged.get(i);
    }
    return res;

    }
}