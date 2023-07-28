// Author: Mina Magdy

class Solution {
public:
    // Function to check if the first player can predict the winner
    bool PredictTheWinner(vector<int>& nums) {
        // Call the recursive 'solve' function with initial parameters
        return solve(nums, 0, nums.size() - 1);
    }
    
    // Recursive function to determine if the first player can win
    bool solve(vector<int>& nums, int l, int r, bool turn = true, int player1 = 0, int player2 = 0) {
        // Base case: If left pointer exceeds right pointer, return true if player1 score is greater or equal to player2 score
        if (l > r) {
            return player1 >= player2;
        }
        
        bool flag; // A flag to determine the current player's turn and potential win outcome

        if (turn) {
            flag = false; // Initialize the flag for player1 (turn=true)
            
            // Try selecting the left element and recurse with updated scores and turn
            flag |= solve(nums, l + 1, r, !turn, player1 + nums[l], player2);
            
            // Try selecting the right element and recurse with updated scores and turn
            flag |= solve(nums, l, r - 1, !turn, player1 + nums[r], player2);
        }
        else {
            flag = true; // Initialize the flag for player2 (turn=false)
            
            // Try selecting the left element and recurse with updated scores and turn
            flag &= solve(nums, l + 1, r, !turn, player1, player2 + nums[l]);
            
            // Try selecting the right element and recurse with updated scores and turn
            flag &= solve(nums, l, r - 1, !turn, player1, player2 + nums[r]);
        }
        
        return flag; // Return the final result of the current turn and selections
    }
};
