//Author: Walaa AbdElhady
class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		map<int, int>baskets;// freq of each type of tree
		// two pointers 
		int l = 0, r = 0, ans = 0;
		while (l < fruits.size()) {
			//loop if you have two types of trees or less
			while (r < fruits.size() && baskets.size() <= 2) {
				// check if you have only two types of trees or not
				if (baskets.size() == 2 && baskets.find(fruits[r]) == baskets.end())break;
				baskets[fruits[r]]++;// add the current tree
				r++;
			}
			// update ans (max of fruits you can collect)
			ans = max(ans, r - l);
			// remove the leftmoste tree from the baskets 
			baskets[fruits[l]]--;
			// if there is only one type of leftmost tree remove it from frq
			if (baskets[fruits[l]] == 0)baskets.erase(fruits[l]);
			l++;
		}
		// max number of fruits can be picked
		return ans;
	}
};