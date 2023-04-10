// Author: Osama Ayman
// Time: O(n)
// Space: O(n)

// use stack to keep track of the last open-bracket
// if the crrent cosing bracket does not match the top of stack return false
// finally, all opening brackets must have a closing one, so if the stack is not empty return false.

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(char c: s.toCharArray()){
            if(c=='(' || c=='[' || c=='{') st.push(c);
            else{
                if (st.isEmpty()) return false;
                if(c==')' && st.pop()!='(' ) return false;
                if(c==']' && st.pop()!='[' ) return false;
                if(c=='}' && st.pop()!='{') return false;
            }
               
            
        }
        return st.isEmpty();
    }
}