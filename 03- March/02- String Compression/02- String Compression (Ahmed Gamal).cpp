// Author: Ahmed Gamal

// for this problem, we need just to implement what the problem asks us to do
// for each character, we need to count the number of consecutive characters and replace them with the character and the number of consecutive characters (if the number of consecutive characters is more than 1)
// we can use two pointers to solve this problem in O(n) time complexity and O(1) space complexity
// the first pointer will point to the current position in the array (c -> points to the current character) 
// and the second pointer will point to the next character to be filled (i -> points to the next position to be filled)
// we will count the number of consecutive characters while the first pointer points to the same character from (last)
// otherwise, we will update the array and start counting the number of consecutive characters from the new character

class Solution {
public:
    int compress(vector<char>& chars) {
        // i: index of the next position to be filled
        // cnt: number of consecutive characters
        // last: the last character
        int i = 0, cnt = 0;
        int last = chars.front();

        // lambda function to update the array
        auto update = [&](char c) -> void {
            // fill the next position with the last character and increment the index
            chars[i++] = last;

            // update the last character
            last = c;

            // no further processing if the number of consecutive characters is 1
            if(cnt == 1)
                return;
            
            // fill the next positions with the number of consecutive characters and increment the index (we can use to_string function to convert the number to string)
            // we are using string here to handle the case of numbers with more than one digit
            for(auto& d : to_string(cnt)){
                chars[i++] = d;
            }

            // reset the number of consecutive characters
            cnt = 1;
        };

        // loop over the array
        for(auto& c : chars){
            // update the array if the current character is different from the last character
            // give it the current character and start counting the number of consecutive characters from 1
            if(c != last){
                update(c);
            }else{
                // increment the number of consecutive characters
                cnt++;
            }
        }

        // update the array one last time to handle the last character (no matter what the character is because we are not going to use it later)
        update('z');

        // return the length of the compressed array
        return i;
    }
};