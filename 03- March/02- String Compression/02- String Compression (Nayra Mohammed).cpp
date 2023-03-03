//Author: Nayra Mohammed

#define sz(s) (int(s.size()))
class Solution
{
public:
    /*
        - Count Similar Consecutive Characters
        - Once we find a differrent character we stop counting and store what we've already counted in our container,
            and reset the counter value to start counting from current character
        - When we store what we counted ,we first store the character itself followed by the counter value "we store counter value digit by digit from left to right"
    */

    void Push_digits(vector<char> &v, int cnt)//to store the counter's value digit by digit
    {
        if (cnt == 1) // value = 1 ? no need to store it
            return;
  
        //Otherwise we convert the counter to a string and iterate through its digits from left to rigit and store them in our container
  
        string s = to_string(cnt);
        for (int i = 0; i < sz(s); i++)
            v.push_back(s[i]);
    }

    int compress(vector<char> &s)
    {
        int cnt = 1;//initially counter = 1 , for the first character in s
        vector<char> ans;// to store s after compressing it
  
        for (int i = 1; i < sz(s); i++)//iterate through s'characters
        {
            if (s[i] == s[i - 1])// if current character = the previous then we increase our counter
                cnt++;
            else //Otherwise, We store what we've already counted and reset counter "value = 1" for current character
                ans.push_back(s[i - 1]), Push_digits(ans, cnt), cnt = 1;
        }
        // for the last consecutive character counting,it'll be stored here not during the iteration
        ans.push_back(s.back()), Push_digits(ans, cnt);
  
        s = ans;//make s equal to our final answer after compressing
  
        return sz(s);//return s's size
    }
};
