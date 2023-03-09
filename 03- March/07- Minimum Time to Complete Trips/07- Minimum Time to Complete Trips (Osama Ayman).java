// Author: Osama Ayman
class Solution {
    public long minimumTime(int[] time, int totalTrips) {
        // binary search on time needed to complete totalTrips
        // O(nlog(m)) n:time.length <= 10^5, m:time <= 10^7
        long lo=1, hi=(long)1e+14, mid;
        long res=0;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            long tripsCompleted = getTrips(time, mid);
            if(tripsCompleted >= totalTrips){
                res=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return res;
    }
    private long getTrips(int[] time, long mid){
        long res=0;
        for(int t: time){
            res+= mid/t;
        }
        return res;
    }
}