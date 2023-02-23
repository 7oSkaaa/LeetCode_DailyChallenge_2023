// Author: Ahmed Gamal

// for this problem, we want to maximize the capital, but we can only invest in projects that have capital less than or equal to the current capital.
// in other words, we want to maximize the profit, but we can only invest in projects that have capital less than or equal to the current capital.
// so, we can use a greedy approach, where we invest in the project that has the maximum profit and capital less than or equal to the current capital.
// to do this, we can use two priority queues, one for the projects that have capital less than or equal to the current capital, and the other for the projects that have capital greater than the current capital.
// the first priority queue will be a max heap, and the second priority queue will be a min heap.
// we will push all the projects into the second priority queue, and then we will start investing in projects.
// but before investing in a project, we will check if the capital of the project is less than or equal to the current capital, if it is, we will push it into the first priority queue.
// and we will pick the project with the maximum profit from the first priority queue, and invest in it.

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // first priority queue is a max heap, and the second priority queue is a min heap. gpq = greater priority queue, lpq = less priority queue
        priority_queue<pair<int, int>> gpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> lpq;

        // push all the projects into the second priority queue (sorted by capital in ascending order)
        for(int i = 0; i < profits.size(); i++){
            lpq.push({capital[i], profits[i]});
        }

        // for the each one of the k investments
        for(int i = 0; i < k; i++){
            // push all the projects that have capital less than or equal to the current capital into the first priority queue (sorted by profit in descending order)
            // make sure that the priority queue is not empty, and the capital of the project is less than or equal to the current capital
            while(not lpq.empty() and lpq.top().first <= w){
                auto [x, y] = lpq.top();
                lpq.pop();
                gpq.push({y, x});
            }

            // if the first priority queue is not empty, that means that we can invest in a project, so we will pick the project with the maximum profit
            if(not gpq.empty()){
                auto [x, y] = gpq.top();
                gpq.pop();

                // invest in the project and add the profit to the current capital
                w += x;
            }
        }

        // return the current capital
        return w;
    }
};