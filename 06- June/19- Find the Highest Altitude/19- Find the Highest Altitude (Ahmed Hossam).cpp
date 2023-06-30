// Author: Ahmed Hossam

class Solution {
public:
    // This function takes a vector of altitude gains as input and returns
    // the largest altitude reached.
    int largestAltitude(vector<int>& gain) {
        // Initialize variables for maximum altitude and current altitude.
        int maxAltitude = 0, currAltitude = 0;
        
        // Iterate over each altitude gain in the vector.
        for(auto& x : gain){
            // Update the current altitude by adding the current gain.
            currAltitude += x;
            
            // Update the maximum altitude if the current altitude is higher.
            maxAltitude = max(maxAltitude, currAltitude);
        }
        
        // Return the maximum altitude reached.
        return maxAltitude;
    }
};
