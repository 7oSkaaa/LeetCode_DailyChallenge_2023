// Author: Ahmed Gamal

// for this problem, we will use dynamic programming to try all possible ways to make the array strictly increasing and choose the minimum cost
// if we notice, we will find that we have two options for each element:
// 1- keep the element as it is
// 2- replace the element with the next greater element in arr2 (if exists)
// to change the element with the next greater element in arr2 is the best option when replacing
// and since we can use each element in arr2 only once (we can't use the same element to replace two different elements in arr1)
// we can sort arr2 and use binary search to get the next greater element in log(n) time

// we will face a problem when we use the last element index as a parameter in the dp function
// because the last element index can be from arr1 or arr2
// so we will use a trick to solve this problem
// we will create a new array called v and we will put all the elements of arr1 and arr2 in it, then we will sort it
// then we will use binary search to get the index of the last element from v instead of arr1 or arr2
// and we will use -1 as the last element when starting the dp function to make sure that the first element will be used as it is

class Solution {
    // N: the size of arr1
    // M: the size of v
    // memo: the dp memoization table
    // v: the new array that contains all the elements of arr1 and arr2
    // arr1: the first array
    // arr2: the second array
    static const int N = 2e3 + 5, M = 4e3 + 5;
    int memo[N][M];
    vector<int> v, arr1, arr2;

    // this function returns the index of the first element in v that is greater than or equal to x
    // and since we are sure that there is an element in v that is equal to x, we will use lower_bound to get the index
    int get_idx(int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin();
    }

    // dp(idx, lst): returns the minimum cost to make the array strictly increasing starting from idx and the last element is lst
    int dp(int idx, int lst) {
        // if we reached the end of arr1, return 0
        if(idx >= arr1.size()) {
            return 0;
        }

        // if the answer is already calculated, return it
        int& ret = memo[idx][lst];
        if(~ret) {
            return ret;
        }

        // initialize the answer with a very large value
        ret = 2e9;

        // if the current element is greater than the last element, keep it as it is
        if(arr1[idx] > v[lst]) {
            ret = min(ret, dp(idx + 1, get_idx(arr1[idx])));
        }
        
        // get the next greater element in arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), v[lst]);

        // if the next greater element exists, replace the current element with it
        if(it != arr2.end()) {
            ret = min(ret, 1 + dp(idx + 1, get_idx(*it)));
        }

        return ret;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // initialize the dp memoization table with -1
        memset(memo, -1, sizeof memo);

        // create a new array called v and put all the elements of arr1 and arr2 in it
        v = arr1;
        for(auto& i : arr2) {
            v.emplace_back(i);
        }

        // sort v and add -1 to it
        v.emplace_back(-1);

        // sort v and arr2
        sort(v.begin(), v.end());
        sort(arr2.begin(), arr2.end());

        // assign arr1 and arr2 to the class variables
        this -> arr1 = arr1;
        this-> arr2 = arr2;

        // get the minimum cost to make the array strictly increasing starting from the first element and the last element is -1
        int ans = dp(0, 0);

        // if the answer is greater than 1e4, return -1 (we can't make the array strictly increasing)
        return ans > 1e4 ? -1 : ans;
    }
};