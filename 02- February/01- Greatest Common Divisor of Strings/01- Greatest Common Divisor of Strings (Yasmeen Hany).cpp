// Author : Eileanora
class Solution {
public:

    bool valid(string& s , string& sub , int& l)
    {
        string ans;
        for(int i = 0; i < l; i++)
            ans += sub;
        return (ans == s);
    } 

    string gcdOfStrings(string& s, string& t)
    {
        int sz1 = s.size(), sz2 = t.size();
        if(sz1 < sz2) { // assume s is always greater than t
            swap(s , t);
            swap(sz1 , sz2);
        }

        // we will iterate over every prefix of t starting from the biggest one possible and check if it is a valid gcd
        for(int i = sz2 ; i >= 1; i--) 
        {
            string sub = t.substr(0 , i);
            int szsub = sub.size();
            // if the size of the prefix is not a divisor of the size of s or t then it is not a valid gcd 
            if((sz1 % szsub) || (sz2 % szsub)) 
                continue;

            // we will check if it's possbile to construct s and t using the prefix by concatenating it sz/subsz times
            // ex) s = "abcabc" , t = "abc" , sub = "abc" , szsub = 3 , sz1 = 6 , sz2 = 3
            //  for s-> 6 / 3 = 2 , for t-> 3 / 3 = 1 
            // s = abs + abc = 2 * abc = abcabc , t = abc = 1 * abc
            int cnt1 = 0 , cnt2 = 0;
            cnt1 = sz1 / szsub;
            cnt2 = sz2 / szsub;
            if(valid(s , sub , cnt1) && valid(t , sub , cnt2))
                return sub;
        }
        return "";
    }

};