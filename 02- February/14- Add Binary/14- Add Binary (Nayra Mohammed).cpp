//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:

    /*
        - Here all we do is literally implementing binary addition operation
        - Reference :) https://www.wikihow.com/Add-Binary-Numbers
        Basic :
            * Adding '1' bit to '1' bit results '10' 
            * Adding '0' bit to '1' bit results '1'
            * Adding '1' bit to '0' bit results '1'
            * Adding '0' to '0' results '0'
            
        In case of having "10" as our result then we consider bit '0' for current position
        and take a carry '1' for our next operation in next position and so on.
    */

    string addBinary(string a, string b)
    {
        string ans;//to store our answer
        bool rem = 0; //to know whether there is a reminder "carry"from previous operation or not
  
        
        // to make it easier will modify the smallest string with a leading zeros to have a similar size as the other
        if (sz(a) < sz(b))
            swap(a, b);

        reverse(b.begin(), b.end());
  
        while (sz(b) < sz(a))
            b += "0";
  
        reverse(b.begin(), b.end());
  
        //starting with right most bit
        for (int i = sz(a) - 1; i >= 0; i--)
        {
            if (a[i] == '1' && b[i] == '1')//adding 1 with 1 results 0 for current position with a carry equals to 1
                ans += (rem ? "1" : "0"), rem = 1;
            else if (!(a[i] == '0' && b[i] == '0'))//adding 1 to 0 results 1 but in case of having a reminder then the answer for current bit is 0 with same carry
                ans += (rem ? "0" : "1");
            else // adding 0 to 0 results 0 but in case of having a reminder then the answer is '1' and we remove the carry 
                ans += (rem ? "1" : "0"), rem = 0;
        }
        //if we have a reminder then we add it
        ans += (rem ? "1" : ""); 
        
        //reverse the anwer to make it in a proper form of binary numbers
        reverse(ans.begin(), ans.end());
  
        return ans; 
    }
};
