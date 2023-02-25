// Author: Ahmed Hossam

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // make vector of indices to sort it
        vector < int > Idx(n);
        
        // make the vector 0 ... n - 1
        iota(Idx.begin(), Idx.end(), 0);
        
        // We sort the projects by their minimum capital required in ascending order because we want to consider the projects that we can afford with our current capital. 
        // By iterating over the sorted projects, we can ensure that we only consider the projects that have a minimum capital requirement less than or equal to our current capital.
        sort(Idx.begin(), Idx.end(), [&](int i, int j){
            return capital[i] < capital[j] || (capital[i] == capital[j] && profits[i] < profits[j]);
        });
        
        int i = 0;
        priority_queue < int > maximizeCapital;
        while (k--) {
            //The condition capital[Idx[i]] <= w checks if the minimum capital requirement of the next project is less than or equal to our current capital w. If this condition is true, we can add the project to the priority queue because we have enough capital to start the project.
            //We use this condition to ensure that we only add the available projects that we can afford to the priority queue. By checking the minimum capital requirement of the next project before adding it to the priority queue, we can avoid adding projects that we cannot afford, and we can focus on selecting the most profitable project that we can afford with our current capital.
            while (i < n && capital[Idx[i]] <= w) 
                maximizeCapital.push(profits[Idx[i++]]);

            if (maximizeCapital.empty()) break;

            w += maximizeCapital.top();
            maximizeCapital.pop();
        }

        return w;
    }
};
