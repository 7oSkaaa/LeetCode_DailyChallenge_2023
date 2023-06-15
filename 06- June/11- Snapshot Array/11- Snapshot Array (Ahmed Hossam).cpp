// Author: Ahmed Hossam

class SnapshotArray {
public:

    // Declaration of variables
    int snap_id;
    map < int, vector < pair < int, int > > > snapshot;

    // Constructor
    SnapshotArray(int length) {
        snap_id = 0;
        for (int i = 0; i < length; i++)
            snapshot[length].emplace_back(snap_id, 0);
    }

    // Set the value at the given index
    void set(int index, int val) {
        snapshot[index].emplace_back(snap_id, val);
    }

    // Create a snapshot and return the snapshot ID
    int snap() {
        return snap_id++;
    }

    // Get the value at the given index for a specific snapshot ID
    int get(int index, int query_snap_id) {
        vector < pair < int, int > >& snap = snapshot[index];
        
        // get the last value the have a snap id less than or equal the given one
        int l = 0, r = snap.size() - 1, ans = 0;
        while (l <= r) {
            int m = l + (r - l) / 2;
            (snap[m].first <= query_snap_id ? l = m + 1, ans = snap[m].second : r = m - 1);
        }
        return ans;
    }

};
