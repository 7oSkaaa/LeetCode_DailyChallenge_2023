// author : Ibrahim khalid
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // create priority_queue to store stones in the order
        priority_queue<int>q;

        for(auto i:stones){
            q.push(i);
        }

        int x,y;

        while(!q.empty()){
            // if size ==1 print the single element
            if(q.size()==1){
                return q.top();
            }
            // x assin to first greater element 
            x=q.top();
            q.pop();
            // y assin to second greater element 
            y=q.top();
            q.pop();

            if(x==y){
                // because you delete them (x,y)
                continue;
            }
            else{
                // store The difference between them
                q.push(x-y);
            }

        }
        // if queue is empty and hasn't single element
        return 0;

    }
};
