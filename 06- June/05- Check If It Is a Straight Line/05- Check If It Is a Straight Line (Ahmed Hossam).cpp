// Author: Ahmed Hossam

class Solution {
public:

    // Define a struct for the coordinates of a point
    struct Point {
        int x, y;

        // Constructor to initialize a point from a vector of integers
        Point(const vector < int >& p) : x(p[0]), y(p[1]) { }
    };

    // Function to check if three points are on the same line
    bool is_same_line(const Point& p1, const Point& p2, const Point& p3){
        // Use slope formula to determine if the points are on the same line
        return (p2.y - p1.y) * (p3.x - p1.x) == (p3.y - p1.y) * (p2.x - p1.x);
    }
    
    bool checkStraightLine(const vector < vector < int > >& coordinates) {
        for(int i = 1; i < coordinates.size() - 1; i++) {
            // Check if the current point, its previous point, and the next point are on the same line
            if(!is_same_line(Point(coordinates[i]), Point(coordinates[i - 1]), Point(coordinates[i + 1])))
                return false;
        }

        // If all points are on the same line, return true
        return true;
    }
};
