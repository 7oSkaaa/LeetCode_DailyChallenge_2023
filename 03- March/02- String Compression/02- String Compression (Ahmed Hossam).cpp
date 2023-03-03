// Author: Ahmed Hossam

class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 1, index = 0;
        
        auto add_new_group = [&](char c){
            // make the current char of the new array equal c
            chars[index++] = c;

            // the number of element in the group more than 1 add the freq
            if(cnt > 1){
                for(auto& cc : to_string(cnt))
                    chars[index++] = cc;
            }

            // reset the number of elements in the group
            cnt = 1;
        };

        // loop over the chars and checks the consecutive characters
        for(int i = 1; i < chars.size(); i++){
            // if the current char equal the last one so we will add to the current group
            // otherwise we will start new group
            if(chars[i] == chars[i - 1])
                cnt++;
            else 
                add_new_group(chars[i - 1]);
        }

        // add the remainig characters
        add_new_group(chars.back());

        return index;
    }
};
