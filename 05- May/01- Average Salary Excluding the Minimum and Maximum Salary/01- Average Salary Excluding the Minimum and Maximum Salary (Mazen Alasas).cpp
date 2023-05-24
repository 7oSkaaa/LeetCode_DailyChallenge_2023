// Author: Mazen Alasas
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());   // Sort the salary vector so that it's easy to neglect the largest and smallest value
        int sum = 0;  // To carry the total
        for (int i = 1; i < salary.size() - 1; i++)   
          /* start in index 1 to avoid the smallest value 
             and end the loop before the last element to avoid the largest value */
            sum += salary[i];   // add salaries
        return (double) sum / (salary.size() - 2);  // return the average as double value
    }
};
