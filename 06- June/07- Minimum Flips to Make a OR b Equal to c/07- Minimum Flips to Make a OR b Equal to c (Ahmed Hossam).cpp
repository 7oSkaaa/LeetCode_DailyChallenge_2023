// Author: Ahmed Hossam

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // Lambda function to get the value of a particular bit
        auto get_bit = [&](int bit, int x){
            return (x >> bit) & 1;
        };
        
        int flips = 0;
        
        // Iterate through each bit from right to left (0 to 31)
        for(int bit = 0; bit < 32; bit++){
            // Check if the current bit in 'c' is set to 1
            if(get_bit(bit, c)) 
                // If 'c' has a 1 and 'a' and 'b' have 0, increment flips
                flips += !(get_bit(bit, a) | get_bit(bit, b));
            
            // Check if the current bit in 'c' is set to 0
            if(!get_bit(bit, c))
                // If 'c' has a 0 and either 'a' or 'b' has a 1, increment flips
                flips += (get_bit(bit, a) + get_bit(bit, b));
        }
        
        return flips;
    }
};
