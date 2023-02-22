// author : Ahmed Zedan
class Solution {
public:
    // count number of day to shipped by curr capacity 
    int is_good(vector<int> &w , int cap){
        int day = 1 , curr = 0 ; 
        for(auto &i : w){
            curr+=i ; 
            if(curr>cap){ // start new day
                day++ ; 
                curr = i ; 
            }
        }
        return day ; 
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search
        // start from max weight to sum of all weight 
        // because min capacity to carry packages (max weight)
        int l=*max_element(weights.begin(),weights.end()) , r=accumulate(weights.begin(),weights.end(),0) ; 
        while(l<r){
            int mid = l+(r-l)/2 ; 
            if(is_good(weights,mid)<=days) r=mid ; 
            else l = mid+1 ; 
        }
        return l ; 
    }
};