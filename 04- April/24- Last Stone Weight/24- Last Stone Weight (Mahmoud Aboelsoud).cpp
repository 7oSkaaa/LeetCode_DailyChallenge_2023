// Author: Mahmoud Aboelsoud

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // we need to find the last remaining stone weight
        // we can do this by using a max heap (priority queue)
        // we will push all the stones into the priority queue
        // then we will pop the two heaviest stones and check if they are equal
        // if they are equal we will do nothing
        // if they are not equal we will push the difference of them into the priority queue
        // we will repeat this process until we have at most one stone left

        // pq: priority queue
        priority_queue<int> pq;

        // push all the stones into the priority queue
        for(auto&i: stones) pq.push(i);

        // repeat the process until we have at most one stone left
        while(pq.size() > 1){
            // pop the two heaviest stones
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            // check if they are not equal and push the difference of them into the priority queue
            if(x != y) pq.push(x - y);
        }

        // if the priority queue is empty then return 0 otherwise return the last remaining stone weight
        return (pq.empty() ? 0 : pq.top());
    }
};
