// Author: Ahmed Gamal

// for this problem, we want to check if the given string is a valid parentheses string
// to solve this problem, we can use a stack to keep track of the opening parentheses and check if the current closing parentheses matches the top of the stack
// if the current closing parentheses doesn't match the top of the stack, then the string is not a valid parentheses string
// if the stack is empty and we encounter a closing parentheses, then the string is not a valid parentheses string
// if the stack is not empty at the end, then the string is not a valid parentheses string

class Solution {
public:
    bool isValid(string s) {
        // stack to keep track of the opening parentheses
        stack<char> st;
        
        // lambda function to check if the current closing parentheses matches the top of the stack
        auto match = [&](char a, char b) -> bool {
            return (a == '(' and b == ')') or (a == '{' and b == '}') or (a == '[' and b == ']');
        };

        // lambda function to check if the current character is an opening parentheses
        auto open = [&](char a) -> bool {
            return a == '(' or a == '{' or a == '[';
        };

        // traverse the string
        for(auto& i : s) {
            // if the current character is an opening parentheses, push it to the stack
            if(open(i)) {
                st.push(i);
            } else {
                // if the stack is empty or the current closing parentheses doesn't match the top of the stack, return false
                if(st.empty() or not match(st.top(), i))
                    return false;
                // otherwise, pop the top of the stack
                st.pop();
            }
        }

        // if the stack is not empty at the end, return false
        return st.empty();
    }
};