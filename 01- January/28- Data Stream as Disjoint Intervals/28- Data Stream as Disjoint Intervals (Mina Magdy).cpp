// Author: Mina Magdy

class SummaryRanges {
public:
    // using map to label the values added
    map<int, bool> exist;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        // label 'value' with true as it's added to map
        exist[value] = 1;
    }
    
    vector<vector<int>> getIntervals() {
        // iterating through the added values and making intervals
        vector<vector<int>> v;
        int prev = -2;
        int l = -1;
        for (auto& I : exist) {
            if (I.first - 1 != prev) {
                if (l != -1)
                    v.push_back({l, prev});
                l = I.first;
            }
            prev = I.first;
        }
        if (l != -1) v.push_back({l, prev});
        return v;
    }
};
