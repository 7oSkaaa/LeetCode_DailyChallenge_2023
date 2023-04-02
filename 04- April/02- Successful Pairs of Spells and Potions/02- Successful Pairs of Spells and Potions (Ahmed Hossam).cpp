// Author: Ahmed Hossam

class Solution {
public:

    // Inline function to calculate the ceil value
    inline long long ceil(long long a, long long b){
        return (a + b - 1) / b;
    }

    // Function to calculate successful pairs
    vector < int > successfulPairs(vector < int >& spells, vector < int >& potions, long long success) {
        // Get the sizes of vectors
        int n = spells.size(), m = potions.size();
        
        // Sort potions vector
        sort(potions.begin(), potions.end());
        
        // Vector to store successful pairs
        vector < int > successful_pairs;
        
        for(auto& x : spells){
            // Calculate target value for a spell that will make it greater than success
            long long target = ceil(success, x);
            
            // Get the index of first potion having value greater or equal to target
            int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            
            // Calculate number of successful pairs
            successful_pairs.push_back(m - idx);
        }

        // Return the vector containing number of successful pairs for each spell
        return successful_pairs;
    }
};
