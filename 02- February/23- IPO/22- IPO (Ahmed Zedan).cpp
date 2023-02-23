//author : Ahmed Zedan
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v ; // {capital[i] , profits[i]}
        int n = profits.size() , i=0 ; 
        for(int i=0 ; i<n ; i++){
            v.push_back({capital[i],profits[i]}) ; 
        }
        sort(begin(v),end(v)) ; // sort by capital priority
        priority_queue<int>pq ; 
        while(k--){
            while(i<n&&v[i].first<=w){  // add project profits to priority queue while can finish project by current capital  
                pq.push(v[i++].second) ;  
            }
            if(pq.empty()) break ;  // break if we can't finish any projects by current caopital 
            w+=pq.top() ; 
            pq.pop() ;  
        }
        return w  ; 
    }
};