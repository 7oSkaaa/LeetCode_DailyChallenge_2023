// author : Omar Sanad
class Solution {
public:
    double average(vector<int>& salary) {

        // sort the array salary, to easily exclude the minimum and maximum element
        sort(salary.begin(), salary.end());
        
        // declare a variable to store the sum of all salaries excluding the min and max 
        int sum = 0;

        // iterate over all salaries except the min and max, then add up to "sum"
        for (int i = 1; i < salary.size() - 1; i++)
            sum += salary[i];
        
        // return sum divided by the number of salaries I considered
        // number of salaries I considered = the number of all salaries excluding the min and max
        return sum / (1.0 * (salary.size() - 2));
    }
};
