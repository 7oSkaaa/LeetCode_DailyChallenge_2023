// author : Omar Sanad

// In this problem, very simple, in each turn of R ((If not banned)), he has to ban the first D he encounters.
// in each turn of D ((If not banned)), he has to ban the first R he encounters.
class Solution {
public:
    string predictPartyVictory(string senate) {

        // declare two queues one for the letter R and the other for the letter D
        queue < int > RR, DD;

        // push the indecies of the two letters in the queue, to know the turns of each person
        for (int i = 0; i < senate.size(); i++)
            if (senate[i] == 'D')
                DD.push(i);
            else
                RR.push(i);

        // declare a timer variable to know whose turn is it now....
        int currTimer = senate.size();

        // iterate untill one party is out of people
        while (RR.size() and DD.size()) {

            // if it is the R turn, then he will ban the first D he encounters
            if (RR.front() < DD.front()) {
                RR.push(++currTimer);   // we will add this person at the last.
                RR.pop();               // then remove him from the front
                DD.pop();   // we will remove this banned person of the D party
            }
            // else if it is the D turn, then he will ban the first R he encounters
            else{
                DD.push(++currTimer);   // we will add this person at the last.
                DD.pop();               // then remove him from the front.
                RR.pop(); // we will remove this banned person of the R party
            }
        }

        // if all the remaining not banned people are from D party   return  "Dire"
        // else if they are from R party return "Radiant"
        return DD.size() ? "Dire" : "Radiant";
    }
};
