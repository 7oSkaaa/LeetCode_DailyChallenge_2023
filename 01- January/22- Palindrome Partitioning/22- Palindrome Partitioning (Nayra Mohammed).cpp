//Author : Nayra Mohammed

/*
We need to split our strings into palindroms and print all valid partitions
Using backtracking will ease that task to us as for each state we decide whether we consider it as a new start for substring or as a part of the last substring.

*/ 

#define sz(s) (int (s.size()))
class Solution {
public:
  
    string x; // store our string as a general copy in it
    
    bool ispalin(string z){ // to check whether that substring is palindrome or not in O(n/2)
       // check both ends similarity
        for(int i = 0;i <= (sz(z)>>1); i++)
            if(z[i] != z[sz(z)-i-1])
                return 0;
        return 1;        
    }
  
  // our backtracking func (idx-> to refer to current character,curr-> to store current partition , v-> our matrix that stores all valid partiitons passing them by ref)
     void Palin(int idx, vector<string>curr, vector<vector<string>>&v){ 
        
        if(idx == sz(x)){ // reaching base case , we need to check whether all substrings we made from the string in current partition are all palindrome or not

            bool bad=0;
            for(auto it:curr)
                bad |= (ispalin(it) == 0);
            
            if(!bad) // if all are palindrome then this paritition is valid , we push it into matrix of answer
                v.push_back(curr);
          
            return;
        }
        /*
        we have two transition state!
        */
        // first : add current character as a new start of a substring
        string z = "";
        z += x[idx];
       
        curr.push_back(z);
        Palin(idx+1, curr, v);
        curr.pop_back();
        // second:  if we have a previous substring we may add it as a part of it in it'end
        if(sz(curr))
            curr.back() += x[idx], Palin(idx+1, curr, v), curr.back().pop_back();
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans; // here we store our answer
        
        x = s; // make our string global
        
        Palin(0, {}, ans); // start from first character , no previous substring where made , and pass ans by reference to store valid partition throughout the process
       
        return ans; // return all valid partitions
    }
};
