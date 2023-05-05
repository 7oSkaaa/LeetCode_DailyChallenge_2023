// Author: Noura Algohary

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();

        queue<int>Rs, Ds;

        // append indexes of Rs and Ds in 2 different queues
        for(int i = 0;i<senate.size(); i++)
        {
            if(senate[i] == 'R')
            Rs.push(i);
            else
            Ds.push(i);
        }
        while(!Rs.empty() && !Ds.empty())
        {
            // pushing min to the queue with new index 
            if(Rs.front() < Ds.front())
                Rs.push(n++);
            else
                Ds.push(n++);
            
            Rs.pop();
            Ds.pop();
        }

        if(Rs.empty())
            return "Dire";
        else
            return "Radiant";
    }
};