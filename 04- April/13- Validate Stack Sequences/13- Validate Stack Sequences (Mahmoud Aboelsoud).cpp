// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // we need to check if the popped sequence is a valid sequence of the pushed sequence
        // we can do this by pushing the pushed sequence into a stack and then poping the stack when the top of the stack is equal to the current element in the popped sequence
        // if the stack is empty at the end then the popped sequence is a valid sequence of the pushed sequence

        // j : index to keep track of the current element in the popped sequence
        int j = 0;
        // st : stack to push the pushed sequence into it
        stack<int> st;
        // loop over the pushed sequence
        for(auto&i: pushed){
            // push the current element into the stack
            st.push(i);

            // while the stack is not empty and the top of the stack is equal to the current element in the popped sequence
            while(st.size() && st.top() == popped[j]){
                // pop the top of the stack
                st.pop();
                // move to the next element in the popped sequence
                j++;
            }
        }

        // if the stack is empty at the end then the popped sequence is a valid sequence of the pushed sequence
        return st.empty();
    }
};
