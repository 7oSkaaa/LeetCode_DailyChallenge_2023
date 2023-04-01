// Author: Abdelrrahman Elhaddad

// We will use Take or Leave DP approach
// We will build our DP vector based on 2 dimenstions

class Solution {
public:
vector<vector<int>> dp; // To store the visited nodes based on the satisfaction vector index and the time available for this index
int n;

int rec(int i, int time, vector<int> &satisfaction) {
    if (i == n) // IF reched the end of the vector, return zero
        return 0;

    int &ans = dp[i][time]; // make a refrence in the dp vector to check whether it is visited
    if (~ans)
        return ans; // If not equal to -1, that means it is visited so return the value

    ans = max(ans, time * satisfaction[i] + rec(i + 1, time + 1, satisfaction)); // Add the current index and increment the time by one (Take)
    ans = max(ans, rec(i + 1, time, satisfaction)); // Do not add the current index and pass the same time (Leave)

    return ans;
}

int maxSatisfaction(vector<int> &satisfaction) {
    n = satisfaction.size();
    dp.assign(n + 5, vector<int>(n + 5, -1)); // Filling dp vector with -1
  
    sort(satisfaction.begin(), satisfaction.end()); // Sorting so larger indexes will be multiplied by larger time values and smaller indexes will be multiplied by smaller time values
  
    return rec(0, 1, satisfaction);
}
};
