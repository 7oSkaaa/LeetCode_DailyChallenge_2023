// author: Esraa Syam
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int l = 0 , r = 0; 
        while(r < n){
            int cnt = 0;
            char c = chars[r]; // the current char  
            while(r < n and chars[r] == c){ // count the number of appearance of the current char
                r++;
                cnt++;
            }
            chars[l++] = c; // put the current 
            if(cnt > 1){
                // convert the number of appearance to string and put it in the vector
                string s = to_string(cnt); 
                // if the size of the string is greater than 1 then we need to put each char in the vector one by one
                // as 10 will be 1 and 0
                for(auto & c : s){
                    chars[l++] = c;
                }
            }
        }       
        return l; // return the size of the vector after compression
    }
    };