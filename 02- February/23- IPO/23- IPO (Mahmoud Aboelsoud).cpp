// Author: Mahmoud Aboelsoud

class Solution {
public:
    // we need to maximize the profit using k projects
    // we can only start build a project if its capital is less than or equal to our main capital (w)
    // so we need to sort the projects by their capital
    // and at each step we will try to maximize the profit by choosing the project with the maximum profit and its capital is less than or equal to our capital (w)
    // we will use a priority queue to store the profits of the projects that we can start building them
    // we only add to the priority queue the projects that we can start building them (their capital is less than or equal to our capital (w))
    // and we will choose the project with the maximum profit from the priority queue which will increase our capital (w)
    // so we go and add to the priority queue the projects that we can start building them after the increase in our capital (w)
    // and we will do this k times or until we can't start building any project
    // and at the end we will return our capital (w)

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // create a vector of pairs to store the capital and the profit of each project
        vector<pair<int,int>> proj;
        for(int i = 0; i < profits.size(); i++)
            proj.push_back({capital[i], profits[i]});
        
        // sort the projects by their capital
        sort(proj.begin(), proj.end());

        // create a priority queue to store the profits of the projects that we can start building them
        priority_queue<int> pq;

        // idx to keep track of the projects that we didn't add to the priority queue yet, and n to store number of projects
        int idx = 0, n = profits.size(); 

        // loop k times or until we can't start building any project
        while(k--){
            // add to the priority queue the projects that we can start building them
            while(idx < n && w >= proj[idx].first)
                pq.push(proj[idx++].second);

            // if we can't start building any project, break
            if(pq.empty()) break;
            // else, choose the project with the maximum profit from the priority queue which will increase our capital (w)
            w += pq.top();
            // and remove the project from the priority queue
            pq.pop();
        }

        // return our capital (w)
        return w;
    }
};
