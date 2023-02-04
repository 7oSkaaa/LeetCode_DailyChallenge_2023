// Author : Hazem Elakbawy
class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
  {
    int n=intervals.size();
    vector<vector<int>>res;
    // no intervals then add new_interval
    if(!n)
    { 
      res.push_back(newInterval);
      return res;
    }
    int st=10000000,en=-1,a=newInterval[0],b=newInterval[1];
    for(int i=0;i<n;i++)
    {
      int x=intervals[i][0],y=intervals[i][1];
      // no intersection conditions
      // new_interval (after/before) current interval
      if(y<a||x>b) 
        continue;
      else
        // start is the minimum point (of all intersecting intervals)
        // end is the maximum point (of all intersecting intervals)
        st=min({st,a,x}),en=max({en,b,y});
    }
    if(en!=-1) //overlapping occured
    {
      newInterval[0]=st;
      newInterval[1]=en;
      bool done=0;
      for(int i=0;i<n;i++)
      {
        if (intervals[i][1]<st) // no overlap
          res.push_back(intervals[i]);
        else if (intervals[i][0]>en)
          res.push_back(intervals[i]); // no overlap
        else if (!done)
          res.push_back(newInterval),done=1;
      }
    }
    else // no overlapping
    {
      bool done=0;
      for(int i=0;i<n;i++)
      {
        if (intervals[i][1]<newInterval[0]) // no overlap
          res.push_back(intervals[i]);
        else if (intervals[i][0]>newInterval[1]) // no overlap
          res.push_back(intervals[i]);
        else if (!done)
          res.push_back(newInterval),done=1;
      }
      // check if we didn't inserted new_interval
      // if so  add it then (sort) to make sure it was added in right position
      if (res.size()==n) 
        res.push_back(newInterval),sort(res.begin(),res.end());
    }
    return res;
  }  
};