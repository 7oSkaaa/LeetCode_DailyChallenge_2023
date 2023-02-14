//auther : Lilian Stephanos 

// Solution  in O(N^2) , USING BITMASKS
class Solution {
public:
    //Putting little in the right bits (knowing all possible letters in the allowed word)
    int bitsInString(string curr_string ){
        int bits = 0 ;
        for(auto& ch : curr_string){
            bits |=(1<<ch-'a');
        }
        return bits ;
    }
    //Approach
    /*
    The idea is to count all the letters that fulfill the condition and the check if it is      equal to the size of the whole word, then this means that all the letters are in current word in the allowed word so This increases the answer by 1.
    */
    int countConsistentStrings(string allowed, vector<string>& words) {
            int len = words.size() , ans(0);
            int oroginal_word = bitsInString(allowed);
            for (int i = 0; i < len; i++)
            {
                int co(0);
                for (int j = 0; j < words[i].size(); j++)
                {
                    if(oroginal_word & (1<<(words[i][j]-'a'))){
                        co++;
                    }
                }
                if(co == words[i].size()) ans++;
            }
            return ans ;
        }
};