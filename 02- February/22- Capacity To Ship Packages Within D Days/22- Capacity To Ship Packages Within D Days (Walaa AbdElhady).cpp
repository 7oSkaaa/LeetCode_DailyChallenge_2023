//Author: Walaa AbdElhady

class Solution {
public:
	int shipWithinDays(vector<int>& weights, int days) {
		//total sum of weights
		int total = 0;
		for (int weight : weights) {
			total += weight;
		}
		//search space of bs
		int l = 1, r = total, ans = -1;
		while (l <= r) {
			int md = l + (r - l) / 2;
			//if the current weight is valid save it and search to find smaller if found
			if (valid(md, days, weights))r = md - 1, ans = md;
			//else search for bigger weight to be valid
			else l = md + 1;
		}
		return ans;
	}
	bool valid(int md, int days, vector<int>& weights) {
		int sum = 0, cnt = 1;
		for (int weight : weights) {
			// if there is an weight greater than maxWeight (md) => invalid
			if (weight > md)return false;
			// if the sum is less than maxWeight add it to the sum
			if (sum + weight <= md)sum += weight;
			// else increase numberOfDays by one and make sum equal to only current weight
			else sum = weight, cnt++;
		}
		//if the numberOfDays lessthan or equal to the days we need => Valid
		return cnt <= days;
	}
};