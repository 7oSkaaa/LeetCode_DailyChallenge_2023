// Author: Mina Magdy

class Solution {
public:
    // Function to return the sign of a number: 1 if positive, -1 if negative
    int sign(int v) {
        return (v > 0 ? 1 : -1);
    }

    // Function to simulate asteroid collision and return the resulting vector
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> ans; // Initialize a vector to store the resulting asteroids

        for (int i = 0; i < ast.size(); i++) {
            // If the 'ans' vector is empty, add the current asteroid to it
            if (ans.empty())
                ans.push_back(ast[i]);
            else {
                // While there are asteroids in 'ans' and the current asteroid is moving to the left
                // and has a greater absolute value than the last asteroid in 'ans', remove the last asteroid from 'ans'
                while (!ans.empty() && sign(ans.back()) > sign(ast[i]) && abs(ast[i]) > ans.back()) {
                    ans.pop_back();
                }

                // If 'ans' is empty or the last asteroid in 'ans' is moving to the right or has the same direction as the current asteroid,
                // add the current asteroid to 'ans'
                if (ans.empty() || sign(ans.back()) <= sign(ast[i])) {
                    ans.push_back(ast[i]);
                }
                // If the last asteroid in 'ans' has the same absolute value as the current asteroid, remove the last asteroid from 'ans'
                else if (ans.back() == abs(ast[i])) {
                    ans.pop_back();
                }
            }
        }
        // Return the resulting vector after simulating asteroid collision
        return ans;
    }
};
