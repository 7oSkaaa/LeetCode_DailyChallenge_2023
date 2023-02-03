// Author: Ahmed Gamal

class SummaryRanges {
public:

    // we are going to use a vector to store the numbers in the data stream in sorted order
    // we can use binary search to find the position of a number in the vector in O(logn) (upper_bound builtin function)
    // we can insert a number in the vector in O(n) (insert builtin function)
    // we can get the intervals in O(n) (we need to iterate over the vector and merge the intervals)
    // so the total time complexity is O(nlogn)

    vector<int> v;

    SummaryRanges() {
        // initialize the vector
        v.assign(0, 0);
    }
    
    void addNum(int value) {
        // find the position of the number in the vector
        auto it = upper_bound(v.begin(), v.end(), value);

        // insert the number in the vector
        v.insert(it, value);
    }
    
    vector<vector<int>> getIntervals() {
        // the answer (the intervals)
        vector<vector<int>> ans;

        // if the vector is empty we need to return the answer (empty vector of intervals)
        if(v.empty())
            return ans;
        
        // start and end of the current interval (initially the first number in the vector)
        int st, ed;
        st = ed = v.front();

        // iterate over the vector and merge the intervals
        for(int i = 0; i < v.size(); i++){
            // if the current number is not adjacent to the current interval we need to add the current interval to the answer and start a new interval
            if(v[i] - ed > 1){
                ans.push_back({st, ed});
                st = ed = v[i];
            }else{
                // if the current number is adjacent to the current interval we need to extend the current interval
                ed = v[i];
            }
        }

        // add the last interval to the answer
        ans.push_back({st, ed});

        // return the answer
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */