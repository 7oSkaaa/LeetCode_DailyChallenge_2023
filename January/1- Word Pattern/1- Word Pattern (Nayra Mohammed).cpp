#define sz(s) (int (s.size()))
class Solution {
public:
    bool wordPattern(string pattern, string s) {
    
        stringstream ss(s); //using stringstream to ignore space and deal with string as a separated words
        unordered_map<char,string>mp; //map to make sure that each character in pattern facing same word in the string not distinct !!
        unordered_set<string>xx; // to count the different words in s versus the different characters in pattern
        
        int id = 0;//to iterate over characters in pattern
        string x;  
      
        while(ss >> x){//while we have words to be processed 
            
            if(id==sz(pattern)) return 0;// in case our pattern length cant take more words,then string doesnt follow the pattern
            
            if(mp.find(pattern[id])==mp.end()) mp[pattern[id]] = x,xx.insert(x);
            else if(mp[pattern[id]] != x) return 0;
            /*
              in case the current pattern's character has faced no words before, we will assign mp[pattern's character] with the current word 
              and insert the word in set <xx>
              otherwise, if it faced a word before  and that word isn't equal to the current processed word ,then string doesnt follow the pattern
            */
          
            id++;//next pattern's character
        }

        if(sz(xx)<sz(mp)) // if the distinct processed words doesn't equal to pattern's distinct characters,then string doesnt follow the pattern 
              return 0;

        return (id==sz(pattern));// make sure that we finished all pattern'characters        
    }
};
