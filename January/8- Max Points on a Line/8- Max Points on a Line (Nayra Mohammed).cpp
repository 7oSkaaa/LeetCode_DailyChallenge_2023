//Author : Nayra Mohammed

// First Solution 
#define sz(s) (int(s.size()))
class Solution {
public:
    
    // to know if 3 points are on the same line ,all we need to do is to check if the slope of pair of them(p1,p2) are equal to the other pair(p2,p3)   
    //slope(p1,p2) = (p1_y - p2_y) / (p1_x - p2_x)
  
    bool same_line(vector<int>&p1, vector<int>&p2, vector<int>&p3){ 
        return (p1[0] - p2[0]) * (p2[1] - p3[1]) == (p2[0] - p3[0]) * (p1[1] - p2[1]);
    }

    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;//initialize our answer with 1,there is at least one point can form a line.

        
        for(int i = 0;i < sz(points); i++)
            for(int j = i+1;j < sz(points); j++){
                int same_slope = 2; //any two points can form a line, we use the varible to know how many points are in that same line.
              
                //we need to check if there exsits a point 'k' such it can be on the same line with points 'i' and 'j'
                for(int k = j+1;k < sz(points);k++)
                   same_slope += same_line(points[i],points[j],points[k]); //if so,increase same_slope 
              
                ans = max(ans,same_slope); // for each two points we maximize the answer.
            }
        
        return ans;
    }
};

//**************************************************************************************************************************************
//Faster Solution(in case we have n >= 1000).

#define sz(s) (int(s.size()))
class Solution {
public:
    
    int gcd(int x,int y){
        return (!y ? x : gcd(y,x%y));
    }

    int maxPoints(vector<vector<int>>& points) {

        int ans = 0;
        map<pair<int,int>, int> mp;//to count for each point ,how many points having same slope with it.

        for(int i = 0,same_slope;i < sz(points);i++)
        {
            // same_slope = to take the max number of points having same slope with point 'i'
            //reinitialize
            same_slope = 0,mp.clear(); 

            for(int j = i+1;j < sz(points);j++)
            {
                //here we calculate the slope as seperated, to avoid divide by zero and decimal point.
                int calc_Ys= points[i][1] - points[j][1];
                int calc_Xs= points[i][0] - points[j][0];
              
                int gg = gcd(calc_Xs, calc_Ys);//get gcd to make the slope in the simplest form -- for example: 24/15 --> 8/5
                
                mp[{calc_Ys/gg,calc_Xs/gg}]++;//increase the formed slope as a pair
              
                same_slope=max(same_slope,mp[{calc_Ys/gg,calc_Xs/gg}]);//maximize same_slope
            }
          
            // add one to same_slope for point 'i'
            ans=max(ans,same_slope + 1); // maximize our answer 
        }
        
        
        return ans;
    }
};


