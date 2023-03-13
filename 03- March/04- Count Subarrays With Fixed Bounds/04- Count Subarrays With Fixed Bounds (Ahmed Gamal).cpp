// Author: Ahmed Gamal

// for this problem we will use two stacks to keep track of the current subarray maximum and minimum
// and we will use two pointers (sliding window) to keep track of the current subarray
// we use these two stacks to represent a queue that contains the current subarray with the following operations:
// 1- push: add an element to the end of the queue
// 2- pop: remove the first element from the queue
// 3- get_max: get the maximum element in the queue
// 4- get_min: get the minimum element in the queue
// 5- empty: check if the queue is empty
// 6- top: get the first element in the queue
// we will use these operations to check if the current subarray is valid or not
// if the current subarray is valid we will add the number of subarrays that ends at the current index to the answer
// since the subarrays should contain at least one minimum element and at least one maximum element we will consider only the subarrays that starts at the first of(lastmax, lastmin) and ends at the current index
// this equals to min(lastmax, lastmin) - l + 1 where l is the left pointer and this range is the valid subarrays starts that ends at r which is the right pointer

class Solution {
public:
    // define some useful macros
    using ll = long long;
    #define imin INT_MIN
    #define imax INT_MAX

    // define the queue data structure
    struct StacksQueue {
        // we will use a vector to represent the stack
        // using the back of the vector as the top of the stack including the operations such as push, pop, top, empty

        // st: the stack that contains the elements
        // mx: the stack that contains the maximum element in the current stack
        // mn: the stack that contains the minimum element in the current stack
        vector<int> st, mx, mn;

        // constructor
        StacksQueue(){
            // initialize the stacks with the minimum and maximum values to avoid checking if the stack is empty or not
            mx = {imin};
            mn = {imax};
        }

        // push an element to the stack
        void push(int x){
            // push the element to the stack and an image of the maximum and minimum elements
            st.emplace_back(x);
            mx.emplace_back(max(mx.back(), x));
            mn.emplace_back(min(mn.back(), x));
        }

        // pop the first element from the stack and remove the image of the maximum and minimum elements
        void pop(){
            st.pop_back();
            mx.pop_back();
            mn.pop_back();
        }

        // get the maximum element in the stack
        int get_max(){
            return mx.back();
        }

        // get the minimum element in the stack
        int get_min(){
            return mn.back();
        }

        // check if the stack is empty
        bool empty(){
            return st.empty();
        }

        // get the first element in the stack
        int top(){
            return st.back();
        }

    } a, b; // a: is the front of the queue, b: is the back of the queue

    // add an element to the back of the queue (b)
    void add(int x){
        b.push(x);
    }

    // remove the first element from the queue (a) and if a is empty we will move all the elements from b to a and remove the first element from a
    void remove(){
        if(a.empty()){
            while(not b.empty()){
                a.push(b.top());
                b.pop();
            }
        }
        a.pop();
    }

    // get the maximum element in the queue (a and b)
    int get_max(){
        return max(a.get_max(), b.get_max());
    }

    // get the minimum element in the queue (a and b)
    int get_min(){
        return min(a.get_min(), b.get_min());
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // not_good: check if the current subarray is not valid (the maximum element is greater than maxK or the minimum element is less than minK)
        auto not_good = [&](){
            return get_max() > maxK or get_min() < minK;
        };

        // good: check if the current subarray is valid (the maximum element is equal to maxK and the minimum element is equal to minK)
        auto good = [&](){
            return get_max() == maxK and get_min() == minK;
        };

        // ans: the answer
        // l: the left pointer of the sliding window
        // max_pos: the last index of the maximum element in the current subarray
        // min_pos: the last index of the minimum element in the current subarray
        ll ans = 0;
        int l = 0, max_pos = -1, min_pos = -1;

        // iterate over the array
        for(int r = 0; r < nums.size(); r++){
            // add the current element to the back of the queue
            add(nums[r]);

            // update the last index of the maximum and minimum elements
            if(nums[r] == minK)
                min_pos = r;
            if(nums[r] == maxK)
                max_pos = r;

            // remove the elements from the front of the queue until the current subarray is valid
            while(not_good() and l <= r){
                remove();

                // update the last index of the maximum and minimum elements
                if(min_pos == l)
                    min_pos = -1;
                if(max_pos == l)
                    max_pos = -1;

                // move the left pointer to the next element
                l++;
            }

            // if the current subarray is valid we will add the number of subarrays that ends at the current index to the answer
            if(good()){
                ans += min(min_pos, max_pos) - l + 1;
            }
        }
        

        // return the answer
        return ans;
    }
};