//Author : Omar Salem
class Solution {
public:
    int compress(vector<char>& chars) {
        // If the input vector is empty, return 0
        if(chars.empty())   
            return 0;
        
        // Initialize variables
        char cur = chars[0];
        int count = 1;
        string tmp;
        
        // Iterate over the input vector
        for(int i = 1 ; i <= chars.size() ; i++)
        {
            // If the current character is equal to the previous character and increment count
            if(i < chars.size() && chars[i] == cur)
                count++;
            else
            {
                // Add the current character to tmp
                tmp.push_back(cur);
                
                // If count is greater than 1, add it to tmp as a string
                if(count > 1)
                {
                    string str = to_string(count);
                    for(auto &s: str)
                        tmp.push_back(s);
                }
                
                // Update cur and reset count
                cur = i < chars.size() ? chars[i] : '0';
                count = 1;
            }            
        }

        // Copy characters from tmp back into chars
        for (int i = 0; i < tmp.size(); i++) 
            chars[i] = tmp[i];

        return tmp.size();
    }
};



