// Author: Eileanora
class SummaryRanges {
public:

    //we will use a set to store our values and sort them
    set <int> intervals;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        intervals.emplace(value);
    }
    
    vector<vector<int>> getIntervals() {
        int start = -1 , end = -1;  // initialize our start and end to -1 for each interval
        vector < vector <int> > ans;

        for(auto& i : intervals) //to generate our interval list , we will iterate throgth our set 
        {
            if(start == -1) // if we have no interval initialized , start one
            {
                start = i;
                end = i;
            }
            else if(i == end + 1) // if that interval could be expanded with end + 1 , change the end value
                end = i;
            else   // if we can't expand the interval , push it to our answer and start a new interval
            {
                ans.push_back({start, end});
                start = i;
                end = i; // start from where we stopped the last interval
            }
        }
        // if we have an interval that is not pushed to our answer because it was continuous untill the end push it seperately
        if(start != -1)  
            ans.push_back({start, end});
        return ans;
    }
};