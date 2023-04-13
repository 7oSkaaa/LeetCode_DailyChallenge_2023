// Author: Osama Ayman
// Time: O(n)
// Space: O(n)

// use a stack so when you encouter a back opearion (i.e ..), pop the top of stack

// build your result by popping all from stack into another stack we can reverse and start appending to our result string from root.
class Solution {
    public String simplifyPath(String path) {
        Stack<String> st = new Stack<>();
        StringBuilder cur = new StringBuilder();
        for(int i=0; i<path.length(); i++){
            char c = path.charAt(i);
            if(c=='/'){
                if(cur.isEmpty()) continue;
                // if its 1 dot, this means that it is the cur file/directory -> do nothing
                if(cur.length() == 1 && cur.charAt(0) == '.'){}
                // if back operaion, pop from stack
                else if(cur.length() == 2 && cur.charAt(0) == '.' && cur.charAt(1) == '.'){
                    if(!st.isEmpty()) st.pop();
                    }
                // if cur is file/directory name, push it 
                else {st.push(cur.toString());}
                // clearing the current string
                cur = new StringBuilder();
            }
            else{
                cur.append(c);
            }

        }
        // checking last current string, because if the string soes not end with a '/' the current string will not be processed.
        if(!cur.isEmpty()){
                // if its 1 dot, this means that it is the cur file/directory -> do nothing
                if(cur.length() == 1 && cur.charAt(0) == '.'){}
                // if back operaion, pop from stack
                else if(cur.length() == 2 && cur.charAt(0) == '.' && cur.charAt(1) == '.'){
                    if(!st.isEmpty())st.pop();
                }
                // if cur is file/directory name, push it 
                else {st.push(cur.toString());}
            }

        // another stack so we can reverse the order of files/directories to start from root
        Stack<String> st2 = new Stack<>();
        while(!st.isEmpty()){
           st2.push(st.pop());
        }
        StringBuilder res = new StringBuilder();
        while(!st2.isEmpty()){
            res.append("/");
            res.append(st2.pop());
            
        }
        return res.isEmpty() ? "/" : res.toString();
    }
}