class Solution
{
public:
    long long totalCost (vector<int>& costs, int k, int candidates)
    {
        // initializing two priority queues to take the first condidates costs from left
        // and to take the first condidates costs from right
        // then every time we take the least and if least was from the left side
        // we add the next candidate from left and check that it's not added in the right side
        // by making sure that l <= r
        int n = costs.size (), l = 0, r = n - 1;
        long long sum = 0;
        priority_queue <int, vector <int>, greater <int> > pq1, pq2;

        // add the frist candidate elements from left and right to the priorty queues
        while (l < candidates)
            pq1.push (costs[l++]);

        while (r > max (l, n - 1 - candidates))
            pq2.push (costs[r--]);

        // we loop k times to take k elements
        while (k--)
        {
            int x;
            // if the left side is smaller we add it and remove it from the pq1
            if (pq2.empty () || (!pq1.empty () && pq1.top () <= pq2.top ()))
            {
                x = pq1.top (), pq1.pop ();
                // here the next element to add is the l so we add it and increse l by 1 
                if (l <= r)
                    pq1.push (costs[l++]);
            }
            else
            {
                x = pq2.top (), pq2.pop ();
                // here the next element to add is the r so we add it and decrease r by 1 
                if (r >= l)
                    pq2.push (costs[r--]);
            }

            // add the smallest element
            sum += x;
        }

        return sum;
    }
};