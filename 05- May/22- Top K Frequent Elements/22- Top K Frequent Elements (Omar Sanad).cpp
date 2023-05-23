// author : Omar Sanad

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // declare the maximum value that can be found in the array
        const int MAX_NUM = 10000;

        // declare a frequency array to calc the occurence of all elements in the array
        vector < int > fq(MAX_NUM * 2 + 5);

        // iterate over the given array nums, update the frequency of the elements in the array
        for (auto &I : nums)
            fq[I + MAX_NUM]++;  // we add the value "MAX_NUM", to avoid accessing negative numbers

        // declare an array to store all unique elements in the given array "nums"
        vector < int > unq_nums;

        // iterate over the frequency array, and add the numbers that appeared in the given array "nums" to "unq_nums"
        for (int i = -MAX_NUM; i <= MAX_NUM; i++)
            if (fq[i + MAX_NUM])
                unq_nums.emplace_back(i);

        // sort the "unq_nums" according to the freq of each element using the lamda expression
        sort(unq_nums.begin(), unq_nums.end(), [&](const int& a, const int& b){
            return fq[a + MAX_NUM] > fq[b + MAX_NUM];
        });

        // declare an array to store the anwer to the problem
        vector < int > Ans;

        // add the answer to the problem in the array, the k most frequent elements
        for (int i = 0; i < k; i++)
            Ans.emplace_back(unq_nums[i]);

        // return the answer to the problem
        return Ans;
    }
};
