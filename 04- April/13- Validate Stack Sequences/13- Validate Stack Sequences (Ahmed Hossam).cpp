// Author: Ahmed Hossam

class Solution {
public:

    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // Define a vector to store the current state
        vector < int > state;
        
        // Initialize variables i, j, and n
        int i = 0, j = 0, n = pushed.size();
        
        // Initialize variables last_i and last_j
        int last_i = i, last_j = j;
        
        // Loop through pushed vector
        while(i < n){
            // Save current i and j values
            last_i = i, last_j = j;
            
            // Loop through pushed vector until we find the value of popped[i]
            while(j < n && pushed[j] != popped[i]) {
                // Add current value to the state vector
                state.push_back(pushed[j++]);
            }
            
            // If we found the value of popped[i], add it to the state vector
            if(j < n) {
                state.push_back(pushed[j++]);
            }
            
            // Loop through state vector and remove elements that match popped[i]
            while(!state.empty() && state.back() == popped[i]) {
                state.pop_back();
                i++;
            }
            
            // If we haven't made any progress, return false
            if(i == last_i && j == last_j) {
                return false;
            }
        }
        
        // If we have looped through the entire pushed vector and there are no elements left in state, return true
        return (i == n && j == n);
    }
};
