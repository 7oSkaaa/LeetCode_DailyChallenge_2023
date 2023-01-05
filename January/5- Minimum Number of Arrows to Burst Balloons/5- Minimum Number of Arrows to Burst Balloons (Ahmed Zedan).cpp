//author : ahmed zedan
class Solution {
public:
    /*
        [[10,16],[2,8],[1,6],[7,12]]
        1 6
        2 8 
        7 12
        10 16
        -----------------------------------------------------
        [[3,9],[7,12],[3,8],[6,8],[9,10],[2,9],[0,9],[3,9],[0,6],[2,8]]
        0 6
        0 9
        2 8
        2 9
        3 8
        3 9
        3 9
        6 8
        7 12
        9 10
    */
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end()) ; // sort points
        int s = points[0][1] ;              // start with minimum end point
        int ans = 1 ;                       // star answer with 1 because select first arrows already 
        for(int i=1 ; i<points.size() ; i++){ 
            if(points[i][0]>s){    // check if arrow out of the range
                ans++ ;            // if true select another arrow
                s = points[i][1] ;      
            } 
            s=min(s,points[i][1]) ; // select minimum ends for a current arrow because it already in previous ranges
        }
        return ans ; 
    }
};