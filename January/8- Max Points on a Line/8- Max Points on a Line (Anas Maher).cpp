//Author: Anas Maher

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // since constraints are low, we can do O(n^2) solution using hashmap.
        // mapping each slope with it's number of points.
        // max(slopes) is the answer as max points with the same slope are the max points on the same line.

        if(points.size()==1) return 1;

        int ans=1;
        double slope;

        for(int i=0 ; i < points.size() ; i++)
        {
            unordered_map<double,int>mp; 
            for(int j=0 ; j<points.size() ; j++)
            {
                if(i==j)continue; // if same point skip it.
                
                slope = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                ans = max(ans, ++mp[slope]);
            }
        }
        return ++ans; // answer = ans+1 to include first point.
    }
};
