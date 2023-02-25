// Author: Ahmed Hossam

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue < int > pq;
        int minval = INT_MAX;
        
        // make all elements even
        for(auto& i : nums){

            // if the number is odd multiply it by 2 to be even
            if(i & 1) i *= 2;

            // get the minimum value after make all element even
            minval = min(minval, i);

            // add the element in the pq
            pq.push(i);
        }

        // to get the minimum diff
        int diff = INT_MAX;

        // while the first max element in the pq is even
        while(!pq.empty() && pq.top() % 2 == 0){
            // get the max value and remove it from the pq
            int maxval = pq.top();
            pq.pop();

            // update the min diff with min value and max value
            diff = min(diff,maxval - minval);

            // update the min val by the new value of the element
            minval = min(minval, maxval / 2);

            // add new value of the element
            pq.push(maxval / 2);
        }

        // update the minimum diff with max odd element with the min val
        return min(diff, pq.top() - minval);
    }
};
