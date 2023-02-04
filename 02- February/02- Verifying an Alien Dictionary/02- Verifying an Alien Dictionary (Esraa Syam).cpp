// author: Esraa Syam
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map < char , int > mp;
        // store the index of each char in the alien language
        for(int i = 0 ; i < order.size() ; i++){
            mp[order[i]] = i;
        }
        // take a copy of words to compare it with the sorted words
        // if the copy is equal to the sorted words then the words are sorted
        // by the alien language
        // else the words are not sorted by the alien language
        vector < string > target = words;
        // sort the words by the alien language
        // use lambda function to compare between two words char by char
        sort(target.begin() , target.end() , [&](string & a , string & b){
            int i = 0 , j = 0;
            // compare between two words char by char
            while(i < a.size() and j < b.size()){
                // if the index of char in first word is less than the index of char in second word
                // then the first word is less than the second word
                if(mp[a[i]] < mp[b[j]]) return true;
                // if the index of char in first word is greater than the index of char in second word
                // then the first word is greater than the second word
                else if(mp[a[i]] > mp[b[j]]) return false;
                i++ , j++;
            }
            // if the size of first word is less than the size of second word
            // then the first word is less than the second word
            return (a.size() <= b.size());
        });
        // return if the words are sorted by the alien language or not
        return (target == words);
        
    }
};