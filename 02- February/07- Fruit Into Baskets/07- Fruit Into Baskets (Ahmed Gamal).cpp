// Author: Ahmed Gamal

class Solution {

    // here we want to find the longest subarray that contains at most 2 different elements (start at any index we want and once we have met the third kind of fruit we have to stop)
    // so we can use a sliding window and keep track of the number of different elements in the current window
    // if the number of different elements is greater than 2 we have to remove the leftmost element from the window and keep doing this until the number of different elements is 2

public:
    int totalFruit(vector<int>& fruits) {
        // n: size of the input vector
        const int n = (int)fruits.size();

        // freq: frequency of each element in the current window
        vector<int> freq(1e5 + 5);

        // ans: the answer
        // cnt: the number of different elements in the current window
        int ans = INT_MIN, cnt = 0;

        // add: add an element to the current window and update the number of different elements
        auto add = [&](int x){
            if(not freq[x]++)
                cnt++;
        };

        // remove: remove an element from the current window and update the number of different elements
        auto remove = [&](int x){
            if(not --freq[x])
                cnt--;
        };

        // loop over the input vector and update the answer
        for(int l = 0, r = 0; r < n; r++){
            // add the current element to the current window
            add(fruits[r]);

            // if the number of different elements is greater than 2 we have to remove the leftmost element from the window and keep doing this until the number of different elements is 2
            while(cnt > 2){
                remove(fruits[l++]);
            }

            // update the answer with maximum between the current answer and the size of the current window
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};