// Author: Mahmoud Aboelsoud

class Solution {
public:
    double average(vector<int>& salary) {
        // we need find the avaerage of all salaries except the minimum and maximum salaries
        // we can find the minimum and maximum salaries using min_element and max_element
        // then we can find the average of all salaries except the minimum and maximum salaries


        // mn: minimum salary, mx: maximum salary
        int mn = *min_element(salary.begin(), salary.end()), mx = *max_element(salary.begin(), salary.end());
        // sum: sum of all salaries except the minimum and maximum salaries
        double sum = 0;
        // loop over all salaries and add them to sum except the minimum and maximum salaries
        for(auto&i: salary) sum += i * (i != mn && i != mx);

        // return the average of all salaries except the minimum and maximum salaries
        return sum / (salary.size() - 2);
    }
};
