// Author: Mina Magdy

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<int> idx(n); // initialy all n element is zeros
        iota(idx.begin(), idx.end(), 0); // after this it will be {0, 1, 2, ... , n - 1}
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return capital[a] < capital[b]; // sorting idx with capital in ascending order 
        });
        priority_queue<int> pq;
        for (int j = 0; j < n; j++) {
            int i = idx[j]; // i is the i'th sorted element
            // if our capital 'W' is less than the current project's capital, add the maximum profit to our capital 'W'
            while (w < capital[i] && !pq.empty() && k) { 
                w += pq.top();
                k--;
                pq.pop();
            }
            // if our capital 'W' greater than the current project's capital, it means that we can take this project, so we will push it to priority queue
            if (w >= capital[i]) pq.push(profits[i]);
        }
        // if there are remain projects to take get the maximum profit from them
        while (!pq.empty() && k) {
            k--;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};

/*
Intuation:
let 'W' be the current capital 
1- the idea is simply to take a project with the biggest profit 'P' where its minimum capital 'C' needed to start it is 'C' <= 'W', after that update the capital 'W' to be 'W' = 'W' + 'P'
it's guaranteed that there will be available as more projects as possible for the next project 
repeat step 1 k times to maximize the final capital

Algorithm:
first let's sort the profits with its capital in ascending order
manage priority queue to get the maximum profits until now
if the current profit has a capital <= 'W' push it to the priority queue
else do the following while 'W' < capital:
    while priority queue not empty
    get the top of the priority queue (which is the maximum profit where 'W' >= capital)
    add it to the 'W'

*/
