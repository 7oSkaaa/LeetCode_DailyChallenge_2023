// Author: Osama Ayman
// Space: O(n)
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        // initially all are non blocked
        boolean[] blocked = new boolean[n];
        // count of R and D in senate
        int r=0, d=0;
        for(char c: senate.toCharArray()){
            if(c=='R') r++;
            else d++;
        }
        // count of the senators that should be blocked in each party
        int rblocked = 0, dblocked = 0;

        // while there are still members in both parties
        while(r>0 && d>0){

            for(int i=0; i<n; i++){
                // if cur senator is blocked, he can do nothing, so continue.
                if(blocked[i]) continue;
                // if cur is R
                if(senate.charAt(i)=='R'){
                    // if this R should be blocked by a previous D, block it
                    if(rblocked > 0){
                        blocked[i] = true;
                        rblocked--;
                        // decrement the number of R remaining
                        r--;
                    }
                    // else block the next D
                    else dblocked++;
                    
                }
                // if cur senator is D
                else{
                    // if this D should be blocked by a previous R, block it
                    if(dblocked > 0){
                        blocked[i] = true;
                        dblocked--;
                        //// decrement the number of D remaining
                        d--;
                    }
                    // else block the next R
                    else rblocked++;
                }
            }
        }
        // return the nonblocked
        return r > 0 ? "Radiant":"Dire";
    }
}