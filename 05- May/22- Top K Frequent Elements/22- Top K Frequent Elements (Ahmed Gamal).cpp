// Author: Ahmed Gamal

// for this problem we will use bucket sort to sort the elements according to their frequency (we will use counting sort to count the frequency of each element)
// we can use counting sort because the elements are in a range from -10^4 to 10^4 so we can use an array of size 2*10^4+1 to count the frequency of each element

// after counting the frequency of each element we will put each element in a bucket according to its frequency
// then we will start from the end of the buckets (the bucket with the highest frequency) and we will put the elements in the answer vector until we reach the k elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // sf: shift factor (to shift the elements to the right to make them non-negative)
        // freq: array to count the frequency of each element
        const int sf = 1e4;
        vector<int> freq(sf << 1 | 1);

        // counting frequency of each element
        for(auto& i : nums) {
            freq[i + sf]++;
        }

        // c: buckets to put the elements in according to their frequency
        vector<vector<int>> c(sf + 1);

        // putting the elements in the buckets according to their frequency
        // remember that the elements are shifted to the right by sf so we need to shift them back to the left
        for(int i = 0; i < freq.size(); i++) {
            c[freq[i]].emplace_back(i - sf);
        }

        // ans: the answer vector
        // i: the index of the bucket we are currently in
        vector<int> ans;
        int i = c.size() - 1;

        // putting the elements in the answer vector until we reach the k elements
        while(ans.size() < k) {
            // if the bucket is empty we will move to the previous bucket, otherwise we will put the elements in the answer vector
            while(not c[i].empty() and ans.size() < k) {
                ans.emplace_back(c[i].back());
                c[i].pop_back();
            }
            if(c[i].empty()) {
                --i;
            }
        }

        return ans;
    }
};