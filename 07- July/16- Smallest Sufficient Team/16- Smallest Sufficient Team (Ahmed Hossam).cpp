// Author: Ahmed Hossam

class Solution {
public:
    int n, m, req_skills_mask; // Variables to store the number of people, number of required skills, and the bitmask for required skills
    map<string, int> mapping; // Mapping of skills to their indices
    vector<vector<int>> dp; // Dynamic programming table
    vector<int> people_masks, people_ans; // Bitmasks for each person's skills and the answer vector

    // Function to build the mapping of skills to indices
    void build(const vector<string>& req_skills) {
        int idx = 0;
        // Iterate through the required skills and assign indices
        for (auto& skill : req_skills)
            mapping[skill] = idx++;
    }

    // Function to build the bitmask for a person's skills
    int build_mask(const vector<string>& people_skill) {
        int mask = 0;
        // Iterate through the person's skills and set the corresponding bits in the bitmask
        for (auto& skill : people_skill)
            mask |= (1 << mapping[skill]);
        return mask;
    }

    // Function to initialize the variables and data structures
    void init(const vector<string>& req_skills, const vector<vector<string>>& people) {
        req_skills_mask = 0; // Initialize the bitmask for required skills to 0
        n = people.size(); // Store the number of people
        m = req_skills.size(); // Store the number of required skills
        people_masks = vector<int>(n); // Initialize the bitmask for each person's skills
        // Build the bitmask for each person's skills
        for (int i = 0; i < n; i++)
            people_masks[i] = build_mask(people[i]);
        // Build the bitmask for required skills
        for (auto& skill : req_skills)
            req_skills_mask |= (1 << mapping[skill]);
        dp = vector<vector<int>>(n, vector<int>(1 << m, -1)); // Initialize the dynamic programming table with -1
    }

    // Function to calculate the minimum number of people needed
    int get_min_people(int idx, int mask) {
        // Return a large value if the bitmask doesn't satisfy the required skills
        if (idx == n) return ((mask & req_skills_mask) == req_skills_mask ? 0 : 1e9);

        int& ret = dp[idx][mask]; // Reference to the corresponding entry in the dynamic programming table
        if (~ret) return ret; // Return the stored value if it has been calculated previously

        // Recursively calculate the minimum number of people needed
        ret = get_min_people(idx + 1, mask);
        ret = min(ret, get_min_people(idx + 1, mask | people_masks[idx]) + 1);

        return ret;
    }

    // Function to build the answer vector
    void build_ans(int idx, int mask) {
        if (idx == n) return; // Base case: reached the end of the people

        int& ret = dp[idx][mask]; // Reference to the corresponding entry in the dynamic programming table

        // Check if the current person is included in the minimum team
        if (ret == get_min_people(idx + 1, mask))
            build_ans(idx + 1, mask);
        else {
            people_ans.push_back(idx); // Add the current person to the answer vector
            build_ans(idx + 1, mask | people_masks[idx]);
        }
    }

    // Function to find the smallest sufficient team
    vector<int> smallestSufficientTeam(const vector<string>& req_skills, const vector<vector<string>>& people) {
        build(req_skills); // Build the skill mapping
        init(req_skills, people); // Initialize the variables and data structures
        get_min_people(0, 0); // Calculate the minimum number of people needed
        build_ans(0, 0); // Build the answer vector
        return people_ans; // Return the answer vector
    }
};
