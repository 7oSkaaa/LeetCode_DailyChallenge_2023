// Author: Lama Salah

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // Create a priority queue to store selected elements from nums1.
        priority_queue<long long> pq;
        
        // Create a vector of pairs to store elements from nums1 and nums2.
        vector<pair<long long, long long>> v;

        // Create pairs of elements from nums1 and nums2.
        for (int i = 0; i < nums1.size(); i++) {
            v.push_back({nums2[i], nums1[i]});
        }

        // Sort the vector in descending order based on elements from nums2.
        sort(v.rbegin(), v.rend());
        
        // Initialize variables for sum and maximum score.
        long long sum = 0, maximum_score = 0;
        
        // Select the k largest elements from nums1.
        for (int i = 0; i < k; i++) {
            pq.push(-v[i].second);  // Push the negative of the ith element from nums1 into the priority queue.
            sum += v[i].second;  // Add the ith element from nums1 to the sum.
        }

        // Calculate the initial maximum score.
        maximum_score = sum * v[k - 1].first;

        // Iterate from the kth pair to the last pair in the vector.
        for (int i = k; i < v.size(); i++) {
            // Check if the current pair's second element is greater than the negative of the top element in pq.
            if (v[i].second > -pq.top()) {
                // Update sum by removing the top element and adding the current second element.
                sum -= -pq.top();
                pq.pop();
                sum += v[i].second;
                
                // Add the current second element to pq.
                pq.push(-v[i].second);
                
                // Update the maximum score.
                maximum_score = max(maximum_score, sum * v[i].first);
            }
        }

        // Return the maximum score.
        return maximum_score;
    }
};