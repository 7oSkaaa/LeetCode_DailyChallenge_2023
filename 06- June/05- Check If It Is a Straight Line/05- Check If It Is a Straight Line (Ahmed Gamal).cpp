// Author: Ahmed Gamal

// we will solve this problem by checking if there is a point that has the same slope with all other points
// if so, then all points are on the same line

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // ok: flag to check if all points are on the same line
        // n: number of points
        // v: vector of points coordinates (to make the code easier to write)
        bool ok = false;
        const int n = int(coordinates.size());
        auto& v = coordinates;

        // check if all points are on the same line
        for(int i = 0; i < n; i++) {
            // st: set to store the slopes of all points with the current point
            set<double> st;
            for(int j = 0; j < n; j++) {
                // skip the current point
                if(j == i) {
                    continue;
                }
                // insert the slope of the current point with the current point
                st.insert(double(v[j][1] - v[i][1]) / double(v[j][0] - v[i][0]));
            }
            // if the size of the set is 1, then all points have the same slope with the current point
            ok |= st.size() == 1;
        }

        return ok;
    }
};