//Author: Walaa AbdElhady

/*
   
   In this problem I will sort the List of Pairs according to the capital.
   then I have atmost k projects so I will run a while loop till k becomes 0. 
   firstly, I will add all the projects having capital less than or equal to the initial capital (w) to the PriorityQueue.
   then I kept on adding the profit to the capital value of company accordingly and for every iteration i will repeat this.
   
   */
class Solution {
public:
	int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
		vector<pair<int, int>>projects;
		for (int i = 0; i < profits.size(); i++) {
			projects.push_back({ capital[i], profits[i] });
		}
		sort(projects.begin(), projects.end());
		priority_queue<int>maxProfit;
		int idx = 0;
		while (k--) {
			while (idx < projects.size() && projects[idx].first <= w) {
				maxProfit.push(projects[idx++].second);
			}
			if (!maxProfit.empty()) {
				w += maxProfit.top();
				maxProfit.pop();
			}
		}
		return w;
	}
};