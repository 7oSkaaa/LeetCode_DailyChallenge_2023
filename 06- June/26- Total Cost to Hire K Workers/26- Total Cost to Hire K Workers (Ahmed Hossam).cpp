// Author: Ahmed Hossam

class Solution {
public:
    // Using a template alias to define a priority queue with minimum element at the top
    template < typename T = int > using PQ = priority_queue < T, vector < T >, greater < T > >;

    // Function to calculate the total cost
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // Priority queues to store the lowest k elements from the start and end
        PQ < int > first, last;
        
        // Lambda function to get the top element from a priority queue, returns INT_MAX if empty
        auto get_top = [&](PQ < int >& pq) {
            return pq.empty() ? INT_MAX : pq.top();
        };
        
        // Variables to store the total cost and the number of elements taken
        long long ans = 0, taken = 0;
        
        // Pointers to track the start and end of the costs vector
        int l = 0, r = costs.size() - 1;
        
        // Loop until the required number of elements are taken
        while (taken < k) {
            // Fill the first priority queue with the lowest elements from the start
            while (l <= r && first.size() < candidates)
                first.push(costs[l++]);
            
            // Fill the last priority queue with the lowest elements from the end
            while (l <= r && last.size() < candidates)
                last.push(costs[r--]);
            
            // Get the top elements from both priority queues
            int topF = get_top(first), topL = get_top(last);
            
            // Choose the smaller top element and add it to the total cost
            if (topF <= topL)
                ans += topF, first.pop();
            else
                ans += topL, last.pop();
            
            // Increase the count of taken elements
            taken++;
        }
        
        // Return the total cost
        return ans;
    }
};
