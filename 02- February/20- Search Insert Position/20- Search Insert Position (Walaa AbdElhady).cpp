// Author: Walaa AbdElhady

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		// search space
		int l = 0, r = nums.size() - 1, ans = -1;
		// Simple binary search to find  idx of min number greater than or equal to target
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] == target)return mid;
			else if (nums[mid] > target)r = mid - 1, ans = mid;
			else l = mid + 1;
		}
		// if the target not found and there is not number in array greater than target
		if (ans == -1)return nums.size();
		// if the target  found or there is a number in array greater than target
		return ans;
	}
};