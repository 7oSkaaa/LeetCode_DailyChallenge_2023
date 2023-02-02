// Author: Ahmed Hossam

class Solution {
public:
    
    // to save the ordered of each charachter
    vector < int >  ord;
    
    bool isSmaller(string& a, string& b){

        // loop for the minimum size between them
        for(int i = 0; i < min(a.size(), b.size()); i++){
            // if the ordered of the char of the first word is smaller than the right word so return false
            // if the ordered of the char of the first word is bigger than the right word so return true
            // if they are the same skip this character
            if(ord[a[i] - 'a'] < ord[b[i] - 'a']) 
                return false;
            else if(ord[a[i] - 'a'] > ord[b[i] - 'a']) 
                return true;
        }

        // if the all character are same so return if the left word size greatet than or equal
        return a.size() >= b.size();
    }

    bool isAlienSorted(vector<string>& words, string& order) {
        ord = vector < int > (26);
        
        // assign each character with its order
        for(int i = 0; i < order.size(); i++)
            ord[order[i] - 'a'] = i + 1;

        // compare each two consecutive words if the left word is smaller than right word
        for(int i = 1; i < words.size(); i++)
            if(!isSmaller(words[i], words[i - 1])) 
                return false;
        
        return true;
    }
};
