//Author: Eileanora

class Solution {
public:
    bool detectCapitalUse(string s) {
        bool a = 1 , b = 1 , c = 1;   
        //assume all possiblites are true then eleminate them
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != tolower(s[i]))  
                b = 0;
            //if it is capital then possibility of all chars are small is false

            if(s[i] == tolower(s[i]))
                c = 0;
            //if it is small then possibility of all chars are capital is false
            if(i == 0)
            {
                if(s[i] == tolower(s[i]))
                    a = 0;
            }
            else
                if(s[i] != tolower(s[i]))
                    a = 0;

            // if the first letter isn't capital or the rest aren't small then it's false
        }
        return (a || b || c);  // if one of them remains true return true
    }
};