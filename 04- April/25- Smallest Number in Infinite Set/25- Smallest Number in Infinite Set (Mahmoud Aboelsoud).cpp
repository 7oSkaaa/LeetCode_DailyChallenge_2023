// Author: Mahmoud Aboelsoud

class SmallestInfiniteSet {
public:
    // we need to find the smallest number in the set and remove it
    // we start the set with all numbers from 1 to 1000
    // we can use a vector to represent the set
    // we can use a variable to keep track of the smallest number in the set
    // when we pop the smallest number we go to the next number in the set
    // when we add a number back to the set we check if it is smaller than the smallest number in the set
    // if it is we update the smallest number in the set

    // vis: vector to represent the set
    // vis[i] = 1 means that the number i is in the set
    // vis[i] = 0 means that the number i is not in the set
    vector<int> vis;
    // idx: the smallest number in the set
    int idx;
    SmallestInfiniteSet() {
        // initialize the set with all numbers from 1 to 1000
        vis.assign(1001, 1);
        // initialize the smallest number in the set to 1
        idx = 1;
    }
    
    int popSmallest() {
        // find the smallest number in the set
        while(!vis[idx]) idx++;
        // remove the smallest number from the set
        vis[idx] = 0;
        // return the smallest number
        return idx++;
    }
    
    void addBack(int num) {
        // add the number to the set
        vis[num] = 1;
        // update the smallest number in the set
        idx = min(idx, num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
