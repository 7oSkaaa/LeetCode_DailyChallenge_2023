// Author: Mahmoud Aboelsoud

class Solution {
public:
    int compress(vector<char>& chars) {
        // 1. Create a string to store the compressed string
        // 2. Create a counter to count the number of the same character
        // 3. Loop over the vector and check if the current character is the same as the previous one
        // 4. If it is the same, increment the counter
        // 5. If it is not the same, check if the counter is 1 or not
        // 6. If it is not 1, add the counter to the string
        // 7. Add the current character to the string
        // 8. Reset the counter to 1
        // 9. After the loop, check if the counter is 1 or not
        // 10. If it is not 1, add the counter to the string
        // 11. Loop over the string and add the characters to the vector
        // 12. Return the size of the string

        // string to store the compressed string
        string s = "";
        // counter to count the number of the same character
        int cnt = 0;
        // loop over the vector
        for(auto&i: chars){
            // if the string is empty, add the current character to the string and increment the counter
            if(s == "") s += i, cnt++;
            else{
                // if the current character is the same as the previous one, increment the counter
                if(i == s.back()) cnt++;
                // if the current character is not the same as the previous one
                else{
                    // if the counter is not 1, add the counter to the string
                    if(cnt != 1) s += to_string(cnt);
                    // add the current character to the string
                    s += i;
                    // reset the counter to 1
                    cnt = 1;
                }
            }
        }

        // if the counter is not 1, add the counter to the string
        if(cnt != 1) s += to_string(cnt);
        // loop over the string and add the characters to the vector
        for(int i = 0; i < s.size(); i++)
            chars[i] = s[i];

        // return the size of the string
        return s.size();
    }
};
