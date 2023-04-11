// Author: Ibrahim Khalid
class Solution {
public:
    bool isValid(string s) {
        // to put character ,and store (,{,[
        stack<char>t;
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                // to avoid runtime
                if(t.size()==0){
            return false;
                }
                // check Every close bracket has a corresponding open bracket of the same type.
                if(t.top()=='('){
                    t.pop();
                }
            
            else{
                return false;
            }
            }

            else if(s[i]=='}'){
                // to avoid runtime
                if(t.size()==0){
                    return false;
                }
                // check Every close bracket has a corresponding open bracket of the same type.
                if(t.top()=='{'){
                    t.pop();
                }
            
            else{
                return false;
            }
            }
            else if(s[i]==']'){
                // to avoid runtime

                if(t.size()==0){
                    return false;
                }
                // check Every close bracket has a corresponding open bracket of the same type.
                if(t.top()=='['){
                    t.pop();
                
            }
            
            else{
                return false;
            }
            }
            else{
            t.push(s[i]);
            }
        }
        // if exist other character in stack after delate same type whether false
        if(t.size()!=0){
            return false;
        }
        return true;
    
    }
};