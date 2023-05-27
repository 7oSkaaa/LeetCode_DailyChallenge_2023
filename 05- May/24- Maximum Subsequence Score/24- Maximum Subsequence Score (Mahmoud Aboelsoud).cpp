// Author: Mahmoud Aboelsoud

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        // we need to find the maximum score subsequence of size of k
        // we caclulate the score by selecting k indexes adn calculate the sum of them from nums1 adn multiply the sum by the minimum value of the selected indexes from nums2
        // we can use a greedy approach to select the k indexes
        // we can store the values of nums1 and nums2 in a vector of pairs and sort them in a decreasing order based on the values of nums2
        // after sorting we will to make the second element of the pair as the minimum value of the selected indexes from nums2
        // and multipy it by the smmaion of the max sum of k elements from the first element of the pair in indeces smaller than or equal to i (the selected pos of the min second element of the pair) 


        // v: vector of pairs to store the values of nums1 and nums2
        vector<pair<int,int>> v;

        // store the values of nums1 and nums2 in v
        for(int i = 0; i < nums1.size(); i++){
            v.emplace_back(nums1[i], nums2[i]);
        }

        // sort v in a decreasing order based on the values of nums2
        sort(v.begin(), v.end(), [](pair<int,int>&p1, pair<int,int>&p2){
            if(p1.second == p2.second) return p1.first > p2.first;

            return p1.second > p2.second;
        });

        // pq: priority queue to store the first element of the pair in a decreasing order
        priority_queue<int, vector<int>, greater<int>> pq;
        // sum: the sum of the max sum of k elements from the first element of the pair in indeces smaller than or equal to i (the selected pos of the min second element of the pair)
        // ans: the answer
        long long sum = 0, ans = 0;

        for(int i = 0; i < v.size(); i++){
            // add the first element of the pair to the sum and push it to the priority queue
            sum += v[i].first;
            pq.push(v[i].first);

            // if the size of pq is equal to k, update the answer by the max of the current answer and the sum multiplied by the second element of the pair
            if(pq.size() == k){
                ans = max(ans, sum * v[i].second);
                // subtract the top element of the priority queue from the sum
                sum -= pq.top();
                pq.pop();
            }
        }

        // return the answer
        return ans;
    }
};
