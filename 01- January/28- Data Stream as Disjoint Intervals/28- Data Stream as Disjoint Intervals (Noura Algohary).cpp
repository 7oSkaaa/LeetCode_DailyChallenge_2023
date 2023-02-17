// Author: Noura Algohary
/*
[1]
 = [1, 1]
[1, 3]
 = [[1, 1], [3, 3]]
 [1, 3, 7]
  = [[1, 1], [3, 3], [7, 7]]

[1, 2, 3, 7]
 = [[1, 3], [7, 7]]

[1, 2, 3, 6, 7]
 = [[1, 3], [6, 7]]
*/
class SummaryRanges {
public:
    set<int>values;  //numbres must be sorted
    SummaryRanges() {}
    
    void addNum(int value) {values.insert(value);}
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> intervals;
        int first = -1, second = -1;

        for(auto value : values)
        {
            if(first == -1)
            {
                first = value;
                second = value;
            }
            else if(value != second + 1)
            {
                intervals.push_back({first, second}); 
                first = value;
                second = value;
            }
            second = value;
        }    
        intervals.push_back({first, second});      
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */