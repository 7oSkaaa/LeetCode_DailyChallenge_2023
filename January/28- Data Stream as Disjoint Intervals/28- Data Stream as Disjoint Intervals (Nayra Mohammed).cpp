//Author :  Nayra Mohammed

/*

Main idea here is to keep our added value sorted always in a proper time O(lg(n)).From that point all we would need is just tracing our intervals:
Each added value is an interval itself if an only if we can't merge it into another interval.

For example :
Add 1 --> current created interval is [1,1]
Add 5 --> current created interval is [5,5]
Add 4 --> current created interval is [4,4]  (but we can find that 4 is followed by 5 so we merge them togther) 
so the overall intervals are { [1,1] , [4,5] }
Add 6 --> we can see we can merge its interval [6,6] with [4,5] so the overall intervals  are {[1,1] , [4,6] }

and so on...
_________________________________
so in adding values we gonna keep them sorted in set, but in generating output for the call "getintervals" we deal with each value in set as an interval itself
till we can merge it with another as we ve seen before ^__^
*/
class SummaryRanges {
public:
  
    set<int>s; // to store all added values sorted  (insertion time O(g(n)) )

    SummaryRanges() {
        s.clear(); // new object is created , so our set needs to be empty
    }
    
    void addNum(int value) {
        s.insert(value); //adding value into our set 
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans; //to store all intervals after we merge them
        
        int st ,ed; // the base interval is [-1,-1] 
        
        st = ed =-1;
        
        for(auto it:s){
          
            if(st == -1) // new interval is coming up
                st = ed = it; // update our interval with the value itself
            else if(ed + 1 == it) // if previous interval is followed by current value like: [4,4] [5,5]  then we update our interval's end
                ed = it;
            else // current value can't be merged then push the stored interval as a final one , create new interval with current value
                ans.push_back({st,ed}),st = ed = it;    
        }

        if(st != -1) // to add the last interval
                ans.push_back({st,ed});    
        
        return ans; // return overall intervals
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
