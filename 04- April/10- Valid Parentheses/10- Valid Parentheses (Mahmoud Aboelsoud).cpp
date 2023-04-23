// Author: Mahmoud Aboelsoud

class Solution {
public:
    bool isValid(string s) {
        // we need to check if the string is valid or not
        // we can use stack to solve this problem
        // we will push the opening brackets and pop the closing brackets
        // if the closing bracket is not the same as the top of the stack
        // then the string is not valid
        // if the stack is not empty at the end then the string is not valid
        // if the stack is empty at the end then the string is valid

        // initialize the stack
        stack<char> st;
        // loop over the string
        for(auto&i: s){
            // if the current character is an opening bracket then push it
            if(i == '(' || i == '{' || i == '[') st.push(i);
            // if the current character is a closing bracket and the stack is empty then return false
            else if(st.empty()) return false;
            // if the current character is a closing bracket and the stack is not empty
            else{
                // check if the top of the stack is the same as the current character
                // if it is the same then pop the top of the stack and continue
                // if it is not the same then return false
                
                if(i == ')'){
                    if(st.top() == '(') st.pop();
                    else return false;
                }

                if(i == ']'){
                    if(st.top() == '[') st.pop();
                    else return false;
                }

                if(i == '}'){
                    if(st.top() == '{') st.pop();
                    else return false;
                }
            }  
        }

        // if the stack is empty at the end then the string is valid
        return st.empty();
    }
};
