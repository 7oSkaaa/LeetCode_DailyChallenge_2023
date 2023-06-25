// Author: Ahmed Hossam

class Solution {
public:
    // Constant variables
    static constexpr int MOD = 1e9 + 7;   // Modulo value
    static constexpr int N = 100;         // Maximum number of locations
    static constexpr int F = 200;         // Maximum fuel capacity

    // Member variables
    int n;                               // Number of locations
    int finish;                          // Destination location
    int dp[N][F];                        // Dynamic programming table
    vector < int > locations;               // Vector to store the locations

    // Function to add a value to another value and handle modulo
    void add(int& ret, int to_add) {
        ret += to_add;
        if (ret >= MOD)
            ret -= MOD;
    }

    // Function to count the number of ways to reach the destination with given fuel
    int cnt_ways(int curr, int fuel) {
        // Base case: If fuel is negative, no more moves can be made
        if (fuel < 0)
            return 0;

        // Check if the result is already computed
        int& ret = dp[curr][fuel];
        if (~ret)
            return ret;

        ret = 0;  // Initialize the result

        // If the current location is the destination, increment the result
        if (curr == finish)
            ret++;

        // Iterate through all possible next locations
        for (int nxt = 0; nxt < n; nxt++) {
            // Skip the current location
            if (curr != nxt)
                // Recursively count the ways by subtracting the fuel consumed
                add(ret, cnt_ways(nxt, fuel - abs(locations[nxt] - locations[curr])));
        }

        return ret;  // Return the result
    }

    // Function to initialize the member variables
    void init(vector<int>& locations, int finish) {
        this -> n = locations.size();
        this -> finish = finish;
        this -> locations = locations;
        memset(dp, -1, sizeof(dp));  // Initialize the dp table with -1
    }

    // Function to count the number of routes
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        init(locations, finish);  // Initialize the member variables
        return cnt_ways(start, fuel);  // Count the number of ways to reach the destination
    }
};
