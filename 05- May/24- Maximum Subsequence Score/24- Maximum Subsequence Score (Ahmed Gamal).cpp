// Author: Ahmed Gamal

// for this problem, we can use a greedy approach
// we will solve the problem for each element in nums2 separately
// if we choose the ith element in nums2 as the minimum of the subsequence, how can we choose the maximum score for the subsequence?
// we can do this by choosing the maximum k - 1 elements from nums1 that have a higher nums2 value than the ith element
// so, we will sort the elements in nums1 according to their nums2 value in a descending order
// then we will start from the first element and we will put it in a priority queue, and keep the sum of the elements in the priority queue
// we will try to keep the largest sum possible, by keeping the largest k elements in the priority queue as we go through the elements

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // p: a vector of pairs to store the elements of nums1 and nums2 together
        // pq: a priority queue to store the k largest elements in nums1
        // sum: the sum of the elements in the priority queue
        // ans: the answer
        vector<pair<int, int>> p(nums1.size());
        priority_queue<int> pq;
        long long sum = 0, ans = 0;

        // putting the elements of nums1 and nums2 together in p
        // notice that we will put the elements of nums2 in the first element of the pair and the elements of nums1 in the second element
        // this is because we want to sort the elements according to their nums2 value
        for(int i = 0; i < p.size(); i++) {
            p[i] = {nums2[i], nums1[i]};
        }

        // sorting the elements in p according to their nums2 value in a descending order
        sort(p.rbegin(), p.rend());

        // go through the elements in p with assuming that the ith element is the minimum of the subsequence
        for(auto& [mn, x] : p) {
            // putting the element in the priority queue and updating the sum
            // notice that we will put the elements in the priority queue as negative numbers to make it a min heap
            pq.push(-x);
            sum += x;

            // if the size of the priority queue is larger than k, we will remove the smallest element from the priority queue and update the sum
            if(pq.size() > k) {
                // notice that we will remove the smallest element from the priority queue as a negative number
                // so we will add it to the sum (sum += -pq.top() = sum -= +pq.top())
                sum += pq.top();
                pq.pop();
            }

            // if the size of the priority queue is equal to k, we will update the answer
            if(pq.size() == k) {
                ans = max(ans, sum * mn);
            }
        }

        return ans;
    }
};