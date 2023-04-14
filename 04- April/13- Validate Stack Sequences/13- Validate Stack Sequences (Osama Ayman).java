// Author: Osama Ayman
// Time O(n)
// Space O(n)

// loop over pushed, push into the stack and while top of stack equals next pop, pop from stack

// when first loop over pushed is done, the only option left is to pop from stack, if at any time the popped is not equal next in popped array , return false
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> st = new Stack();
        int popindex = 0;
        for(int i=0; i<pushed.length; i++){
            
                st.push(pushed[i]);
            
            while (!st.isEmpty() && st.peek() == popped[popindex]) {
                st.pop();
                popindex++;
            }
            
        }
        while(!st.isEmpty()){
            if (st.pop() != popped[popindex]){
                return false;
            }
            popindex++;
        }
        return true;
    }
}