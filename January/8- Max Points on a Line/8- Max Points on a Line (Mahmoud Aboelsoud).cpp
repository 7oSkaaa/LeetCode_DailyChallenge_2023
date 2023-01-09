// Author: Mahmoud Aboelsoud

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // get the number of points we have
        int n = points.size();

        // initialize our answer with the minumum value we can get wich with 1 if we hade only 1 point on the x-y plane 
        int ans = 1;

        // loop one the points and take the current point as our main
        for(int i = 0; i < n; i++){
            // map to count the frequencies of slopes we can get to see the maximum number of points we have on the same line as the current point i
            map<double, int> ma;
            // variable to store the maximum number of points we have on the same line as the current point i 
            int mx = 0;

            // loop on the other points to get their slope with our point i
            for(int j = i + 1; j < n; j++){
                // get the slope and if our points have the same x we set the slope with INT_MAX to prevent dividing by zero 
                double slope = (points[i][0] - points[j][0] ? (points[i][1] - points[j][1]) / (double)(points[i][0] - points[j][0]) : INT_MAX);
                ma[slope]++;
                // get the maximum number of points on the same slope with our main point
                mx = max(mx, ma[slope]);
            }
            // get the maximum number of points on the same line, we add 1 to mx because we never count our main point i so we add it to the answer
            ans = max(mx + 1, ans);
        }
        
        return ans;
    }
};
