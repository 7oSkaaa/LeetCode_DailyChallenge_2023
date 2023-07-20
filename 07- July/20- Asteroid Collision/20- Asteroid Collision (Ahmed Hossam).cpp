// Author: Ahmed Hossam

class Solution {
public:
    vector < int > asteroidCollision(vector < int >& ast) {
        int n = ast.size();
        stack < int > s; // Stack to simulate collisions.

        // Iterating through the asteroids.
        for (int i = 0; i <  n;  i++) {
            if (ast[i] > 0 || s.empty()) // If the asteroid is positive or stack is empty, push it onto the stack.
                s.push(ast[i]);
            else {
                // Handling negative asteroids colliding with positive ones.
                while (!s.empty() && s.top() > 0 && s.top() < abs(ast[i]))
                    s.pop(); // Pop the positive asteroids until they're smaller or equal to the negative one.

                if (!s.empty() && s.top() == abs(ast[i]))
                    s.pop(); // If a positive asteroid equals the negative one in size, they both explode.

                else if (s.empty() || s.top() < 0) 
                    s.push(ast[i]); // If the stack is empty or the top asteroid is negative, the negative asteroid survives.
            }
        }

        int sz = s.size();
        vector < int > res(sz);

        // Reconstructing the final result.
        for (int i = sz - 1; ~i; i--) {
            res[i] = s.top();
            s.pop();
        }

        return res;
    }
};
