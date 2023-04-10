// Author: Ahmed Hossam

class Solution {
public:
    bool isValid(const string& s) {
        // Initialize a stack to hold open parenthesis, braces, and brackets
        stack < char > st;
        // Iterate over each character in the string
        for (auto& c : s) {
            // If the character is an open parenthesis, brace, or bracket, add it to the stack
            if (c == '(' || c == '{' || c == '[') st.push(c);
            // If the character is a close parenthesis, brace, or bracket
            else if ((c == ')' || c == '}' || c == ']') && st.empty()) return false;
            // If the stack is empty, the string is invalid, return false
            else {
                // Check if the top element of the stack matches the current character, if so pop the stack
                if (c == ')' && st.top() == '(') st.pop();
                else if (c == '}' && st.top() == '{') st.pop();
                else if (c == ']' && st.top() == '[') st.pop();
                // If the top element of the stack does not match the current character, return false
                else return false;
            }
        }
        // If the stack is empty, the string is valid, return true
        return st.empty();
    }
};
