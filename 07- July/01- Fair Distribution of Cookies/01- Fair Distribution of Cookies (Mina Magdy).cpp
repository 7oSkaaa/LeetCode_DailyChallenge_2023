// Author: Mina Magdy

class Solution {
public:
    // Function to distribute cookies among k children
    int distributeCookies(vector<int>& cookies, int k) {
        // Sort the cookies in ascending order
        sort(cookies.begin(), cookies.end());
        // Initialize ans variable with a large value
        int ans = 1e9;

        // Generate permutations of cookies
        do {
            // Create a min heap priority queue to store the sum of cookies for each child
            priority_queue<int, vector<int>, greater<int>> pq;
            
            // Initialize the priority queue with k zeros
            for (int i = 0; i < k; i++)
                pq.push(0);
            
            // Initialize the current answer variable to 0
            int cur_ans = 0;

            // Distribute cookies among children
            for (int i = 0; i < cookies.size(); i++) {
                // Calculate the new total for the child with the least sum of cookies
                int new_tp = pq.top() + cookies[i];

                // Update the current answer with the maximum sum encountered
                cur_ans = max(cur_ans, new_tp);

                // Remove the child with the least sum of cookies from the priority queue
                pq.pop();

                // Add the child with the updated sum back to the priority queue
                pq.push(new_tp);
            }

            // Update the minimum answer encountered so far
            ans = min(ans, cur_ans);

        } while (next_permutation(cookies.begin(), cookies.end()));

        // Return the minimum answer
        return ans;
    }
};
