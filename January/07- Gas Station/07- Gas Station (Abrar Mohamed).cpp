// Author : Abrar Mohamed
class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int startStation = 0;
        int currGas = 0;
        
        // Greedy cycling algorithm
        for (int station = 0; station < gas.size(); ++station) {
   //If the fuel becomes negative, reset the start station to the 
  current station and  reset the current gas  to 0.
            if (currGas < 0) {
                currGas = 0;
                startStation = station;
            }
            
            currGas += gas[station];
            currGas -= cost[station];
        }
        
        // Check if cycle is even possible
        int station = startStation;
        currGas = 0;
//Loop around the circuit from the start
        for (int i = 0; i < gas.size(); ++i) {
            currGas += gas[station];
            currGas -= cost[station];


            if (currGas < 0) {
                return -1;
            }
            
            ++station;
            station %= gas.size();
        }
        
        return startStation;
    }
};