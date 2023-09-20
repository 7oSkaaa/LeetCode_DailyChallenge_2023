// Author: Mina Magdy

class Solution {
public:
    // Variables
    int full, n;
    vector<vector<int>> dp;
    vector<int> people_mask, ans;
    
    // Recursive function to calculate the minimum team size
    int min_team_size(int idx = 0, int mask = 0) {
        // Base cases
        if (mask == full)
            return 0;
        if (idx == n)
            return 1e9;
        
        // Memoization
        int &ret = dp[idx][mask];
        if (~ret)
            return ret;
        
        // Recursive calls
        ret = min_team_size(idx + 1, mask);
        return ret = min(ret, 1 + min_team_size(idx + 1, mask | people_mask[idx]));
    }
    
    // Recursive function to build the answer
    void build_ans(int idx = 0, int mask = 0) {
        // Base case
        if (mask == full)
            return;
        
        int &ret = dp[idx][mask];
        int op1 = min_team_size(idx + 1, mask);
        int op2 = 1 + min_team_size(idx + 1, mask | people_mask[idx]);
        
        // Check which option was chosen and proceed accordingly
        if (ret == op1) {
            build_ans(idx + 1, mask);
        }
        else {
            ans.push_back(idx);
            build_ans(idx + 1, mask | people_mask[idx]);
        }
    }
    
    // Helper function to convert skills to binary representation
    void convertSkillsToBinary(const vector<string>& req_skills, const vector<vector<string>>& people, vector<int>& masks) {
        unordered_map<string, int> mp;
        
        // Assign unique indices to each required skill
        for (int i = 0; i < req_skills.size(); i++) {
            mp[req_skills[i]] = i;
        }
        
        // Convert people's skills into binary representation
        for (int i = 0; i < people.size(); i++) {
            int mask = 0;
            for (int j = 0; j < people[i].size(); j++) {
                mask |= (1 << mp[people[i][j]]);
            }
            masks.emplace_back(mask);
        }
    }
    
    // Main function to find the smallest sufficient team
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // Initialize variables
        n = people.size();
        full = (1 << req_skills.size()) - 1;
        dp = vector<vector<int>>(n, vector<int>(full, -1));
        
        // Convert skills to binary representation
        convertSkillsToBinary(req_skills, people, people_mask);
        
        // Calculate the minimum team size
        min_team_size();
        
        // Build the answer
        build_ans();
        
        // Return the answer
        return ans;
    }
};
