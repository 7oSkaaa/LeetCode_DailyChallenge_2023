//Author : Nayra Mohammed

#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
class Solution {
public:
  
    unordered_set<string>s; // to store all string and help us in checking
  
    string x; // used as a genral copy of current string
  
    int dp[31]; // our dp array to used in memorization
  
    bool  Concatenated(int idx){
       
        if(idx == sz(x)) // we reached the end of the string , then we succussfully could seperate our concatenated string into continuous substrings!
            return 1; 

        if(dp[idx] != -1) // we reached a situation where we ve gone into same path before, so all we need is return the answer we memorized.
            return dp[idx];
        
        bool ok = 0; //our answer for current state ,initially false 
        string temp = ""; // to build our substring for every possible size 
      
        for(int i= idx ; i < sz(x);i++){ // our substring's start is from current idx  but it's end [current idx, last idx in string]
            temp += x[i]; // add current character "prefix substring from idx"
            if(s.find(temp) != s.end()) // if that prefix exists in our list then we check the rest of string whether it can be splited or not
                ok |= Concatenated(i+1); //update our answer
        }
        
        return dp[idx] = ok; // memorize our answer for current state
    }
  
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans; // to store our valid concatenated strings
      
        for(auto it:words) s.insert(it); //to help us checking whether a specific substring exists or not
        
        for(auto it:words) //for each string we check whether it is concatenated or not
        {
            x = it; //update our general string to current string in words
            s.erase(s.find(it)); // we delete current string from set to prevent the case of substring is the string itself
            MemS(dp,-1); // reinitialize our memorization array
          
            if(Concatenated(0)) // check whether we can split our string into continuous substrings that exists in words
                ans.push_back(it); 
           
            s.insert(it); //add the deleted string for further checking
        }

        return ans; // return answer
    }
};
