// Author: Ahmed Hossam

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Get the size of nums1
        int n = nums1.size();
        
        // Create a vector of indices from 0 to n - 1
        vector < int > idx(n);
        iota(idx.begin(), idx.end(), 0);
        
        // Sort the indices based on the corresponding values in nums2
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return nums2[i] < nums2[j];
        });
        
        // Create a min-heap priority queue
        priority_queue < int, vector < int >, greater < int > > pq;
        
        // Variables to keep track of the current sum and maximum sequence
        long long curr_sum = 0, max_seq = 0;
        
        // Lambda function to add an element to the current sum and the priority queue
        auto add = [&](int x){
            curr_sum += x;
            pq.push(x);
        };
        
        // Lambda function to remove the smallest element from the current sum and the priority queue
        auto remove = [&](){
            curr_sum -= pq.top();
            pq.pop();
        };
        
        // Iterate over the indices in reverse order
        for(int i = n - 1; i >= 0; i--){
            // Add the corresponding element from nums1 to the current sum and the priority queue
            add(nums1[idx[i]]);
            
            // If the size of the priority queue reaches k, update the maximum sequence and remove the smallest element
            if(pq.size() == k){
                max_seq = max(max_seq, curr_sum * nums2[idx[i]]);
                remove();
            }
        }
        
        // Return the maximum sequence
        return max_seq;
    }
};
