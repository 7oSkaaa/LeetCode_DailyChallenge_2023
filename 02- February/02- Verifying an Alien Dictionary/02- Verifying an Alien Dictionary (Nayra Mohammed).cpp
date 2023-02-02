//Author : Nayra Mohammed
#define sz(s) (int(s.size()))

class Solution {
public:
    /* In normal sorting between two string x, y the smallest lexographical string comes first according to these rules : 
                                     - for some index i (s.t. 0 <= i <= min (x.size() , y.size()) if there exists such case where x[i] != y[i], if x[i] < y[i]
                                         then x is smaller lexographically than y  otherwise y is the smallest
                                     - In case of all characters in range [0,min(x.size() , y.size())] are all similar then if x.size() < y.size()   
                                         then x is smaller lexographically than y  otherwise y is the smallest
            
            Noraml sorting depends on the character's ordering in ASCII,But here in our problems we need to rely on their ordering in the given string.
            
            -- First we need to store each character's ordering in that string to get it as fast as possible if needed in O(1),instead of search in the whole string
               every time we need a character's ordering
               
            -- For any two consecutive strings  in words check whether the first one is smaller or equal to the second for all pairs (i-1,i) (s.t. 0 < i < words.size())
                * our check will rely on the same rules of normal sorting but instead of comparing the character's itself, we gonna compare their ordering in "order"
                  I.e the ordering that was already stored *_^
                  
            -- If all valid i all two consecutive strings are sorted then the whole sequence "words" is sorted      
            
       */
  
    int pos[26]; // to store character's order in this problem 
  
    bool comp (string x,string y){ //to compare between any two consecutive strings
        
      
        for(int i = 0 ;i < min(sz(x),sz(y)); i++)
        {
            if(x[i] == y[i]) //  similar characters won't help us in comparing 
                continue;
          
            return (pos[x[i] - 'a'] < pos[y[i] - 'a']); /* if the order of current x's character is smaller than the order of current y's character
                                                          return true "first string is smaller than the second string"
                                                          .otherwise, return false "first string is larger than the second string" 
                                                          */ 
        }
        // if all previously checked characters are the same then we decide who is smaller by who have smaller size
        return (sz(x) <= sz(y));
    }    

    
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i = 0;i < sz(order);i++) // store each character's ordering in the givin string
            pos[order[i] - 'a'] = i;

        for(int i = 1 ;i < sz(words); i++) // compare every two consecutive string 
            if(!comp(words[i-1],words[i])) // in case of the wrong replacement of these two strings "not sorted" the we returns false 
                return 0;

        return 1; // we passed all previous checks, then words'sequence is AlienSorted
    }
};
