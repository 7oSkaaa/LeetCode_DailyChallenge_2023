//author : Ahmed Zedan 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int totalgas=0 , totalcost=0 , curr=0 , ans=0 , n=cost.size() ; 
        for(int i=0 ; i<n ; i++){
            totalgas+=gas[i] ;             //sum all gas can get 
            totalcost+=cost[i] ;           // sum all costs
            curr+= (gas[i]-cost[i]) ;     // calucte the remain gas after moving 
            if(curr<0){                   // if remain gas > 0 try to stat from next idx
                ans=i+1;
                curr=0 ; 
            }
        }
        if(totalgas<totalcost) return -1 ;    
        // if total gas less than total cost impossible to travel around the circuit once in the clockwise direction
        return ans ;  
    }
    
};
