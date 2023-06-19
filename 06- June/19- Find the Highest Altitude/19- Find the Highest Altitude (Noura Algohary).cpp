// Author: Noura Algohary
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, altitude = 0;

        for(int i = 0;i<gain.size();i++)
        {
            // each altitude's height is the summation of the previous altitude 
            // and the net gain between i and the previous altitude
            altitude += gain[i];


            // store the highest one in highest 
            if(altitude > highest)
                highest = altitude;

            
        }
        return highest;
    }
};