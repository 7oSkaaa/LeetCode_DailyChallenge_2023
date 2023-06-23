// Author: Ahmed Gamal

// for this problem, we need to find the maximum altitude of a point after a series of changes in the altitude
// we can do this by adding the changes to the previous altitude and then find the maximum altitude after all the changes until this point
// note that the altitude in the beginning is 0, so we need to find the maximum between the maximum altitude and 0

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // mx: maximum altitude
        int mx = -2e9;
        for(int i = 0; i < gain.size(); i++) {
            // check if we are not in the first point (to avoid accessing the -1 index)
            if(i) {
                gain[i] += gain[i - 1];
            }
            // find the maximum altitude
            mx = max(mx, gain[i]);
        }
        
        // return the maximum altitude after all the changes
        return max(mx, 0);
    }
};