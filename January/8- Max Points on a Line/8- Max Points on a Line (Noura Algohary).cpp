// Author: Noura Algohary
class Solution {
public:
// A function to get the max value out of a map
template<typename K, typename V>
std::pair<K,V> getMaximumValue(const std::map<K,V> &map) {
    return *std::max_element(map.begin(), map.end(), [](std::pair<K,V> const &x, std::pair<K,V> const &y) {
        return x.second < y.second;
    });
}
    int maxPoints(vector<vector<int>>& points) {
        // A map that stores slopes as keys and the frequency of occurrence as value
        map<float, int> slopes;

        int max_points = 0, vertical=0;
        float slope = 0.0;

        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                if(i==j) continue; // The same point, then skip it
                // When the denominator is equal to 0, the points are vertical and slope is not defined. 
                // "vertical" counts vertical points.
                if(points[i][0] == points[j][0]) {vertical++; continue;}

                // point1(x1, y1), point2(x2, y2) --> slope = (y2 - y1) / (x2 - x1)
                slope = float(points[i][1] - points[j][1]) / float(points[i][0] - points[j][0]);

                if(slopes.find(slope)!=slopes.end())  // slope is already a key on the map
                    slopes[slope]++;
                else
                    slopes.insert(make_pair(slope, 1));  // add slope to the map with a 0 frequency. 
                
            }

            pair <float,int> pair = getMaximumValue(slopes);
            if (pair.second > max_points)
                max_points = pair.second;
            

            // if vertical > 0, then there are some vertical points counted
            if(vertical>0)
            {
                if(vertical>max_points)
                    max_points = vertical;
            }
            // clearing is important for the next loop 
            slopes.clear();
            vertical=0;
        }
        return ++max_points;
    }
};