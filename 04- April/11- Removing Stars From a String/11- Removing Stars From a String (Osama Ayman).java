// Author: Osama Ayman
// Time: O(n)
// Space: O(n)
class Solution {
    public String removeStars(String s) {
        // use a stack to keep track of the last char
        Stack<Character> st = new Stack<>();
        for(int i=0; i<s.length(); i++){
            char cur = s.charAt(i);
            // if star, remove top of stack
            if(cur=='*') st.pop();
            // else push the current char
            else st.push(cur);
        }
        // result will be all chars remaining in the stack
        StringBuilder sb = new StringBuilder();
        // pop all in String 
        while(!st.isEmpty()){
            sb.append(st.pop());
        }
        // chars popped will be reversed, so reverse the string to obtain the result
        return sb.reverse().toString();
    }
}