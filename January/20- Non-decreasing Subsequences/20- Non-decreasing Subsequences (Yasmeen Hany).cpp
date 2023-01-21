// Author: Eileanora
class Solution {
public:

    bool non_decreasing(vector <int>& temp)
    {
        // here we check if it is a valid subsequence and if it is non-decreasing
        if(temp.size() < 2)
            return false;
        
        for(int i = 1; i < temp.size(); i++)
            if(temp[i] < temp[i - 1])
                return false;

        return true;
    }

    set < vector <int> > generate_powerset(vector <int>& nums)
    {

        // here we generate the powerset of the given array
        set < vector <int> > save;
        int sz = nums.size();
        for(int mask = 0; mask < (1 << sz); mask++)
        {
            vector <int> temp;
            for(int i = 0; i < sz; i++)
            {
                if(mask & (1 << i))
                    temp.push_back(nums[i]);
            }

            if(non_decreasing(temp)) // if vald push it to my answer
                save.emplace(temp);
        }
        return save;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
    
    // the idea is to generate all the possible subsequences and then check if they are non-decreasing or not
    // to genetate them we will use the powerset
        vector < vector <int> > ans;

        set < vector <int> > save;  // to avoid duplicates we will use a set
        save = generate_powerset(nums); 

        for(auto& i : save)  // to convert the set to a vector
            ans.push_back(i);

        return ans;
    }
    // complixity: O(2^n * n)
};