// Author: Ahmed Gamal

// for this problem, we need to find the smallest number in an infinite set
// as the infinite set consists of all the positive integers, we can use a variable to store the smallest number
// we can use a boolean array to store the numbers that are in the set and the numbers that are not in the set
// when we need to pop the smallest number, we can return the smallest number and mark it as not in the set
// after that, we need to find the next smallest number in the set and update the smallest number
// when we need to add a number to the set, we can mark it as in the set and update the smallest number if needed

class SmallestInfiniteSet {
    // N is the maximum number in the set
    // sm is the smallest number in the set
    // vis[i] is true if i is in the set and false otherwise
    static const int N = 1e3 + 5;
    int sm;
    bool vis[N];
public:
    SmallestInfiniteSet() {
        // initialize the smallest number to 1
        // mark all the numbers as in the set
        sm = 1;
        memset(vis, true, sizeof vis);
    }
    
    int popSmallest() {
        // return the smallest number and mark it as not in the set
        int x = sm;
        vis[sm] = false;

        // find the next smallest number in the set
        while(not vis[sm]) {
            sm++;
        }

        // return the answer
        return x;
    }
    
    void addBack(int num) {
        // mark the number as in the set and update the smallest number if needed
        vis[num] = true;
        sm = min(sm, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */