// Author: Mohamed Ashraf

class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> temp;
        int size_chars = chars.size();
        for(int i = 0; i < size_chars; i++){

            int frequency = 1;

            while(i+1 < size_chars && chars[i+1] == chars[i]) frequency++ , i++;

            temp.push_back(chars[i]);
            
            // Push frequency to (temp)
            // Skip if frequency equal 1
            if(frequency > 1){
                string s = "";

                while(frequency > 0){
                    // Change last digit to char
                    s += (frequency % 10) + '0';
                    frequency /= 10;
                }

                // Push reverse (s) to (temp)
                while(s.size()){
                    temp.push_back(s.back());
                    s.pop_back();
                }
            }
        }
        chars.clear();
        chars = temp;
        return chars.size();
    }
};
