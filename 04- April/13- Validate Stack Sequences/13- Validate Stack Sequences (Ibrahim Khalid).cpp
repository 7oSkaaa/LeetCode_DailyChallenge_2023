// author: Ibrahim Khalid
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // stack to store pushed and at the same time delete it elements 's popped
        stack<int>s;
        int sz=pushed.size();

        // index to vecter popped
        int j=0;

        s.push(pushed[0]);
        for(int i =1;i<sz;i++){
            // check stack. Do it empty ? to aviod runtime when  delete elements 's popped
            while(!s.empty()){
                if(popped[j]==s.top()){
                    s.pop();
                    j++;
                }
                else{
                    break;
                }
            }

            // to push elements 's pushed in the stack
            s.push(pushed[i]);
        }
        // check to last element in stack .do it equal element to popped
        while(popped[j]==s.top()){
            s.pop();
            j++;
            // if stack empty ->true to all elements 's popped deleted
            if(s.empty()){
                return true;
            }
        }
        //else
        return false;
    }
};