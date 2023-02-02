//Author : Nayra Mohammed
// Bye Bye January UwU

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
class Solution {
  
  /*
   -- We 've two main goals : 1- Make a valid team :
                                   - All have same age 
                                   - In case of a player higher age there must be no player with lower age having a higher score than that player
                              2- Getting Maximum Score as possible in team formation. 
      Gonna solve it using DP !
      let's imagine that problem as Knapsack problem "Our Capcitiy is infinity",all we need is to try to take a player but with taking care of previous taken players
      So, To simplifiy that we gonna sort our players according to their ages then their scores "lower ages come first , in case of similarity lower scores comes first".
      Our dp will focus on memorizing answers for states with regard to current player's index and previous player's index.
      There exists two possibility in each state we reach either to skip current player or if it's a valid player "compair him with previous one" then we consider it's score
      then Our final state's answer will be the maximum value between these two possibilities!
  */
public:
    
    vector<vector<int>>dp; //our memorization matrix
    vector<pair<int,int>>v; // to store the combination of each player's info in one component <his age, his score> instead of being seperated

    int Max_Score(int idx,int pre){
        if(idx == sz(v)) //no more players to be checked "our base case !!"
            return 0;
      
        if(dp[idx][pre] != -1) // in case of reaching same state we ve been before then we return it's memorized answer
          return dp[idx][pre];
      
        int op = Max_Score(idx+1,pre); // don't consider current player
      
        // if taking current player will be valid "having same age" of "bigger age with higher or similar score of previous player"
       // we add his value and proceed to the next player
      // we take the maximum value between these two states
        if( (v[idx].first == v[pre].first) || (v[idx].second >= v[pre].second)) 
            op = max(op, v[idx].second + Max_Score(idx+1,idx));
        
        return dp[idx][pre] = op;  // memorize current state with maximum value we have reached      
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        v.push_back({0,0}); //add a pre value <age = 0 , score = 0>
      
        for(int i=0;i<sz(scores);i++) //combine each player's info in one component <his age, his score> instead of being seperated
            v.push_back({ages[i],scores[i]});
      
        sort(v.begin(),v.end()); //sort according to first their ages,then their score "normal sorting in pair's elements !!"  
        
        dp.resize(sz(v),vector<int>(sz(v),-1)); //set our memorization size and it's initialized value 
        
        return Max_Score(1,0); // get the answer   
    }

};
