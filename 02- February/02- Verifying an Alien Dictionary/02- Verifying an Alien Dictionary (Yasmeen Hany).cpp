// Author : Eileanora

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map <char , int> ordered;  // map each character to its index in the order string for better accessing

        for(int i = 0; i < order.size(); i++)
            ordered[order[i]] = i;
        
        // this approach is to sort the words vector according to its alien order and compare it with the original vector 
        // if they are equal then the words are sorted corectly
        vector <string> ans = words; 
        sort(words.begin() , words.end() , [&](string& a , string& b){
            int sz1 = a.size() , sz2 = b.size();
            int i = 0 , j = 0;
            while(i < sz1 && j < sz2) // let's iterate over both string untill one of them ends
            {
                if(ordered[a[i]] < ordered[b[j]]) // if the chacaacter in a is less than the character in b 
                    return true; // then a is smaller than b

                else if(ordered[a[i]] > ordered[b[j]]) // if not then a is greater than b 
                    return false;

                i++ , j++;
            }
            return (sz1 <= sz2); // if the strings are equal untill one of them ends then the smaller one is the one with the smaller size
        });

        return (ans == words); // if the sorted vector is equal to the original vector then the words are sorted correctly
    }
};