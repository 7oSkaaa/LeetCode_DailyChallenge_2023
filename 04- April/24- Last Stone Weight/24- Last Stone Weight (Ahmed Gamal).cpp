// Author: Ahmed Gamal

// for this problem, we need to find the last stone after all the operations
// we can use a priority queue to solve it (max heap)
// at first, we push all the stones into the priority queue
// then, we try to get the two heaviest stones and break them
// if the two stones are equal, then we don't need to push anything into the priority queue
// otherwise, we need to push the difference between the two stones into the priority queu

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // initialize the priority queue
        priority_queue<int> pq;
        for(auto& i : stones) {
            pq.push(i);
        }

        // get the top element from the priority queue
        auto get = [&]() -> int {
            int x = pq.top();
            pq.pop();
            return x;
        };

        // try to get the two heaviest stones and break them
        while(pq.size() > 1) {
            int y = get();
            int x = get();

            // if the two stones are equal, then we don't need to push anything into the priority queue
            if(y - x) {
                pq.push(y - x);
            }
        }

        // return the answer
        return pq.empty() ? 0 : pq.top();
    }
};