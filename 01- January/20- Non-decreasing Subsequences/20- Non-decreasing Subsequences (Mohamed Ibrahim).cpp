//Author: Mohamed Ibrahim

class Solution {
public:
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> res;  // vector to store all possible non-decreasing subsequences
    vector<int> cur;         // vector to store current subsequence
    findSubsequencesHelper(nums, 0, cur, res);  // call helper function to find all subsequences
    return res;
 }
/*This function takes a vector of integers as input and returns a vector of vectors of integers,
    where each inner vector represents a non-decreasing subsequence*/
void findSubsequencesHelper(vector<int>& nums, int start, vector<int>& cur, vector<vector<int>>& res) {
    if (cur.size() >= 2) {   // if current subsequence has at least two elements, add it to the result
        res.push_back(cur);
    }
    set<int> visited;  // set to keep track of elements used in the current subsequence
    for (int i = start; i < nums.size(); i++) {
        if ((cur.empty() || nums[i] >= cur.back()) && visited.count(nums[i]) == 0) {  // if the current element is greater or equal to the last element in the current subsequence and has not been visited before
            cur.push_back(nums[i]);     // add the current element to the current subsequence
            findSubsequencesHelper(nums, i + 1, cur, res);  // call helper function recursively to find more subsequences
            cur.pop_back();             // remove the last element from the current subsequence
            visited.insert(nums[i]);    // mark the current element as visited
        }
    }
 }
};