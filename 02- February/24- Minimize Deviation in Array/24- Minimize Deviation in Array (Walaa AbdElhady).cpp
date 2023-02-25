//Author: Walaa AbdElhady

/*

    in this problem we can sya that the minimum deviation is the difference between the maxNumber and minNumber in array
    so we try to find the maxNumber and minNumber in array after  performing some number of operations

    we have two operations if number odd multiply it by 2 and if it even divide it by 2
    so we can observe that when we multiply odd by two it becomes even and now can divide it by two and becomes odd again
	ex : 3 => 3*2 = 6 => 6/2 = 3
	but the even number may be differ
	ex : 8 => 8/2 = 4 => 6/2 = 2 => 2/2 = 1

	so we can multiply odd number by two and then we have only one operation => divide number by 2
	and then try to find the maxNumber and minNumber in array by save numbers in priorityQueue and traverse on it
	to do opertaion on numbers and every iteration find the difference between the maxNumber and minNumber
	and when the maxNumber becomes odd we can not do any operation on it and it now the max => we must take it and break the loop

*/
class Solution {
public:
	int minimumDeviation(vector<int>& nums) {
		priority_queue<int>q;
		int ans = INT_MAX, mn = INT_MAX;
		int mx = INT_MIN;
		for (int n : nums) {
			if (n & 1)n *= 2;
			q.push(n);
			mn = min(mn, n);
		}
		while (1) {
			int tmpMax = q.top();
			q.pop();
			ans = min(ans, tmpMax - mn);
			if (tmpMax & 1)break;
			q.push(tmpMax / 2);
			mn = min(mn, tmpMax / 2);
		}
		return ans;
	}
};
