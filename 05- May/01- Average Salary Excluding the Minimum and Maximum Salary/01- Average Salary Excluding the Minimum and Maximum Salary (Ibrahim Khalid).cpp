// author :- Ibrahim Khalid
class Solution {
public:
    double average(vector<int>& salary) {
        // sort to excluding the minimum and maximum salary
        sort(salary.begin(),salary.end());
        // store summation
        long double sum=0;
        for(int i=1;i<salary.size()-1;i++){
            sum+=salary[i];
        }
        // divide on number salary excluding the minimum and maximum salary
        return sum/(salary.size()-2);
        
    }
};
