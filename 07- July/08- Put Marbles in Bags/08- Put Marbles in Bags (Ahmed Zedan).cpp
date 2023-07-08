// author : Ahmed Zedan
#define ll long long 
class Solution {
public:
    /*  
        - we must take weights[0] as start point and weights[n-1] as end point.
        - and try split another (k-1) by this way take weights[i] as end point and weights[i+1] as start point.
    */
    long long putMarbles(vector<int>& weights, int k) {

        ll n = weights.size() ; 

        priority_queue<ll> mx_heap ; // store min costs to split
        // use max heap to get min costs to split because delete max costs split (when splits == k we need k-1 split only)
        priority_queue<ll , vector<ll> , greater<ll>> mn_heap ; // store max costs to split
        // use min heap to get max costs to split because delete min costs split (when splits == k we need k-1 split only)

        for(ll i=0 ; i<n-1 ; ++i){

            mx_heap.push(weights[i]+weights[i+1]) ; 
            mn_heap.push(weights[i]+weights[i+1]) ;

            if(mx_heap.size()==k){
                mx_heap.pop() ; 
                mn_heap.pop() ; 
            } 

        }

        ll mx_cost = weights[0]+weights[n-1] , mn_cost = weights[0]+weights[n-1] ;

        while(!mx_heap.empty()){
            mx_cost += mn_heap.top() ; 
            mn_cost += mx_heap.top() ;    
            mx_heap.pop() ; 
            mn_heap.pop() ; 
        }
        
        return mx_cost - mn_cost ; 
    }
};