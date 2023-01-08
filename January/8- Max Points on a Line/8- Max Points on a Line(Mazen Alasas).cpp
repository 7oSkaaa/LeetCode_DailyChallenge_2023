// Author : Mazen Alasas
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int c = 1;
        if (points.size() == 1) // If points vector has one point
            return c;
        //             x1    x2    x3    x4    x5    x6
        //            0 1   0 1   0 1   0 1   0 1   0 1
        // points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
        for (int i = 0; i < points.size() - 1; i++) {
            map<double, int> mp;
            for(int j = i + 1; j < points.size(); j++) {
                double dif_y = points[j][1]-points[i][1], dif_x = points[j][0]-points[i][0];
                //               y2 - y1
                // slope    =    -------
                //               x2 - x1
                double s = dif_y/ dif_x;    // Calc Slope
                // Then Store frequency of the slope
                if(dif_y < 0 && dif_x == 0)
                    mp[abs(s)]++;
                else
                    mp[s]++;
            }
            // Calc maximum no of points on the same line
            for(auto [k, v] : mp)
                c = max(c, v + 1);
        }
        return c;
    }
};

