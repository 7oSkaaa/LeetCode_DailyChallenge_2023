// author : Omar Sanad
class Solution {
public:
    string removeStars(string s) {
        stack <char> st;
        for (auto &ch : s)
            // if the curr character is a star then remove the non star character to its left
            if (ch == '*')
                st.pop();
            // else then push this character to the stack
            else
                st.push(ch);
        
        // declaring a string ans (the string we will return), fill this string with the characters in the stack
        string ans;
        while (st.size())
            ans.push_back(st.top()), st.pop();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
