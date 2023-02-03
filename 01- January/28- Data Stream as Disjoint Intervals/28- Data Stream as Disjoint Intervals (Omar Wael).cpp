// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        // set current interval to the begining of the set
        // the begining of interval
        int start=*s.begin();
        // the end of the interval
        int end=*s.begin();
        for(auto it=++s.begin();it!=s.end();it++){
            // if current element equal to the end of interval +1 
            if(*it==end+1){
                // add it to the interval
                end++;
            }else{
                // push current interval 
                ans.push_back({start,end});
                // create new interval starts at this value
                start=*it;
                // and also edns at it
                end=*it;
            }
        }
        // push the last interval
        ans.push_back({start,end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */