// Author: Ahmed Gamal

// for this problem, we will not be able to store all the snapshots in the memory, so we will store only the changes
// how to store the change? we will store the change in a vector of pairs, the first element of the pair will be the snapshot id and the second element will be the value
// every set operation, we will check if the last change is in the same snapshot id, if it is, we will update the value, if not, we will add a new change
// for the get operation, we will use binary search to find the last change before the snapshot id

class SnapshotArray {
    // idx: the current snapshot id
    // a: the array of changes
    int idx;
    vector<vector<pair<int, int>>> a;
public:
    SnapshotArray(int length) {
        // initialize the snapshot id to 0
        // initialize the array of changes to empty (start with 0 as the first snapshot id and 0 as the first value)
        idx = 0;
        a.assign(length, vector<pair<int, int>>(1, {0, 0}));
    }
    
    void set(int index, int val) {
        // if the last change is in the same snapshot id, update the value, if not, add a new change
        auto p = make_pair(idx, val);
        if(p.first == a[index].back().first) {
            a[index].back() = p;
        } else {
            a[index].emplace_back(p);
        }
    }
    
    int snap() {
        // increment the snapshot id
        return idx++;
    }
    
    int get(int index, int snap_id) {
        // use binary search to find the last change before the snapshot id
        auto it = lower_bound(a[index].begin(), a[index].end(), make_pair(snap_id, 0));
        
        // if the pointer is at the end of the array or the snapshot id is greater than the snapshot id of the change
        if(it == a[index].end() or it -> first > snap_id) {
            it--;
        }

        // return the last change before the snapshot id
        return it -> second;
    }
};