// Author: Ahmed Gamal

// for this problem we can use priority queue and two pointers to solve it
// we will use two pointers to define the range of the candidates (or point that we can hire from)
// we will use priority queue to get the minimum cost in the range of the candidates

// we will start with the first candidates workers and the last candidates workers and we will add them to the priority queue
// then we will hire the minimum cost worker and we will use the index to know if this worker is from the first candidates or the last candidates
// if the worker is from the first candidates we will add the next worker to the priority queue and we will increase the left pointer
// if the worker is from the last candidates we will add the previous worker to the priority queue and we will decrease the right pointer

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // n: number of workers
        // l: left pointer
        // r: right pointer
        // pq: priority queue to get the minimum cost (we will use negative cost to get the minimum cost)
        const int n = int(costs.size());
        int l = 0, r = n - 1;
        priority_queue<pair<int, int>> pq;

        // add the first candidates workers and the last candidates workers to the priority queue
        // note that we will use negative cost and index to sort them ascendingly
        while(l <= r and l < candidates) {
            pq.emplace(-costs[l], -l);
            l++;
        }
        while(r > l and r + candidates >= n) {
            pq.emplace(-costs[r], -r);
            r--;
        }

        long long ans = 0;
        while(k--) {
            // get the minimum cost worker
            auto [c, i] = pq.top();
            pq.pop();

            // convert the negative cost and index to positive
            i = -i;

            // add the cost to the answer
            ans -= c;

            // add the next worker if the worker is from the first candidates
            if(i < l) {
                if(l <= r) {
                    pq.emplace(-costs[l], -l);
                    l++;
                }
            } else {
                // add the previous worker if the worker is from the last candidates
                if(r >= l) {
                    pq.emplace(-costs[r], -r);
                    r--;
                }
            }
        }

        return ans;
    }
};