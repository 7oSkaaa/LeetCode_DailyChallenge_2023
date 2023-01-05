// author: Esraa Syam
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
        // sort in descending order
        sort(v.rbegin() , v.rend()); 
        // we will start from the first balloon and shoot it
        int max_start = v[0][0] , cnt = 1;
        // then we will check if the next balloon is inside the first balloon or not
        for(int i = 0 ; i < v.size() ; i++){
            // if max_start is greater than the end of the next balloon
            // we will shoot it and start from the next balloon
            if(max_start > v[i][1]) cnt++ , max_start = v[i][0];
            // else we will shoot it and start from the max_start of the next balloon
            else max_start = max(max_start , v[i][0]);
        }
        return cnt;

    }
};
/*
example 3 :
  // sort in descending order
        
                   ....... v[0]
              ......  v[1]
        ...... v[2]
    ..... v[3]
 ---1----2----3----4----5-----
    we want to find the minimum number of arrows to shoot all the balloons
    we will sort the balloons in descending order
    we will start from the first balloon and shoot it
    then we will check if the next balloon is inside the first balloon or not
    if it is inside the first balloon we will shoot it
    if it is not inside the first balloon we will shoot it and start from the next balloon
*/