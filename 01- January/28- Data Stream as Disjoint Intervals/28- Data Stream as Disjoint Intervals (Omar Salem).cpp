// Author: Omar Salem
class SummaryRanges {
public:
    vector < int > v;
    SummaryRanges() {
 
        v.assign(0,0);
    }
    
    void addNum(int value) {
        //find pos of number in v
        auto it = upper_bound(v.begin() , v.end() , value);
        v.insert(it , value) ;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(v.empty())
            return ans;
        int start , end ;
        start = end = v.front();
        for(int i = 0 ; i < v.size() ; i++)
        {
            if(v[i] - end > 1)
            {
                // if current number isnt adjacent to the current interval we need to add the current interval to the answer and start a new interval
                ans.push_back({start , end});
                start = end = v[i];
            }
            else 
                end = v[i];
        }
        // add last interval
        ans.push_back({start , end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */