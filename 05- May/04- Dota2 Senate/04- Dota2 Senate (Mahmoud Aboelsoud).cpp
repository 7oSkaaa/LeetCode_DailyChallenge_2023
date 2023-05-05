// Author: Mahmoud Aboelsoud

class Solution {
public:
    string predictPartyVictory(string s) {
        // we need to simulate the process of banning and voting until one party wins
        // we will use two queues to store the indices of the senators of each party
        // we will use a while loop to simulate the process
        // at each iteration we will pop the first senator from each queue
        // if the first senator of the Radiant party is before the first senator of the Dire party
        // then we will ban the first senator of the Dire party and push the first senator of the Radiant party to the end of the Radiant queue
        // to be a part of the next round
        // else we will ban the first senator of the Radiant party and push the first senator of the Dire party to the end of the Dire queue
        // to be a part of the next round
        // we will repeat this process until one of the queues becomes empty
        // the party of the senator who is still in the queue will be the winner


        // n: the number of senators
        // r: the queue of the Radiant senators
        // d: the queue of the Dire senators
        int n = s.size();
        queue<int> r, d;
        

        // loop through the senate string to fill the queues
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') r.push(i);
            else d.push(i);
        }

        // simulate the process of banning and voting until one party wins
        while(r.size() && d.size()){
            // if the first senator of the Radiant party is before the first senator of the Dire party
            if(r.front() < d.front()){
                // ban the first senator of the Dire party
                d.pop();
                // push the first senator of the Radiant party to the end of the Radiant queue + n (to be a part of the next round we add n to its index so it will be after all the senators of the current round)
                r.push(r.front() + n);
                // remove the first senator of the Radiant party from the Radiant queue
                r.pop();
                
            }else{
                // ban the first senator of the Radiant party
                r.pop();
                // push the first senator of the Dire party to the end of the Dire queue + n (to be a part of the next round we add n to its index so it will be after all the senators of the current round)
                d.push(d.front() + n);
                // remove the first senator of the Dire party from the Dire queue
                d.pop();
            }
        }

        // return the winner party
        return (r.empty() ? "Dire" : "Radiant");
        
    }
};
