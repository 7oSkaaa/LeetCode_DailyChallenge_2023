//Author : Omar Salem
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> ans; // Create a stack to simulate the push and pop operations
        int i = 0, j = 0; // Initialize two pointers i and j to track the indices of pushed and popped arrays
        while (i < pushed.size()) // Loop through the pushed array
        {
            ans.push(pushed[i]); // Push the current element of pushed array onto the stack
            i++; // Increment the pointer i
            while(!ans.empty() && ans.top() == popped[j]) // While the stack is not empty and the top element of the stack is equal to the current element of popped array
            {
                ans.pop(); // Pop the top element from the stack
                j++; // Increment the pointer j
            }
        }
        return ans.empty(); // If the stack is empty, it means that all push and pop operations are valid. Otherwise, return false.
    }   
};