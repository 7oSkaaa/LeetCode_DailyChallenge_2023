// Author: Ahmed Hossam

class Solution {
public:

    int lastStoneWeight(vector<int>& stones) {
        //Creates a priority queue with integers
        priority_queue<int> pq;

        //Inserts each stone in the priority queue
        for(auto& stone : stones)
            pq.push(stone);

        //Lambda function to get the top 2 elements from the priority queue and remove them
        auto get_top = [&](){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            return make_pair(x, y);
        };

        //Loops while there are more than 1 stone in the priority queue
        while(pq.size() > 1){
            //Gets the top 2 stones and removes them from the priority queue
            auto [x, y] = get_top();
            
            //If the 2 stones are different, it inserts the difference into the priority queue
            if(x != y)
                pq.push(x - y);
        }

        //Returns the weight of the last stone or 0 if the priority queue is empty
        return (pq.empty() ? 0 : pq.top());
    }
};
