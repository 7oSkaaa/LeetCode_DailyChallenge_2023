// Author: Mahmoud Aboelsoud

class Solution {
public:
    // set of vector to avoid duplicates
    set<vector<int>> ans;
    // temp vector to store the current subsequence, and nums to store the input vector
    vector<int> temp, nums;
    

    // recursive function to generate all non-decreasing subsequences
    // idx is the index of the current element in the input vector  
    void rec(int idx){
        // if we reached the end of the input vector, we check if the current subsequence is valid
        if(idx == nums.size()){
            // if the current subsequence is valid, we insert it into the set of vectors
            if(temp.size() > 1) ans.insert(temp);
            return;
        }


        // we have two choices, either we include the current element in the subsequence or not
        
        // here we don't include the current element in the subsequence 
        rec(idx + 1);
        
        // here we include the current element in the subsequence if it is greater than or equal to the last element in the subsequence or the subsequence is empty
        if(temp.empty() || nums[idx] >= temp.back()){
            // we include the current element in the subsequence
            temp.push_back(nums[idx]);
            // we call the recursive function with the next element
            rec(idx + 1);
            // we remove the current element from the subsequence
            temp.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this -> nums = nums;
        rec(0);
        
        // we convert the set of vectors to a vector of vectors
        vector<vector<int>> res;
        for(auto&i: ans)
            res.push_back(i);

        return res;
    }
};
