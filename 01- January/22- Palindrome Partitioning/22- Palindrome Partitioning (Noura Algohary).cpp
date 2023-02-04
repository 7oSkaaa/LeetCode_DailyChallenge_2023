// Author: Noura Algohary
class Solution {
public:
    bool isPalindrome(string s, int st, int end)
    {
        while(st < end)
        {
            if(s[st]!=s[end])
                return false;
            
            st++;
            end--;
        }
        return true;
    }
    void allPossiblePalidrome(vector<vector<string>>& palindrome, string s, int idx, vector<string>& branch)
    {
       // solution is found 
        if(idx == s.size())
        {
            palindrome.push_back(branch); //add solution to other solutions
            return;
        }
            
        for(int i=idx;i<s.size();i++)
        {
            if(isPalindrome(s, idx, i))
            {
                branch.push_back(s.substr(idx, i - idx + 1));  
                allPossiblePalidrome(palindrome, s, i+1, branch);
                branch.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindrome;
        vector<string> branch;
        allPossiblePalidrome(palindrome, s, 0, branch);
        return palindrome;
    }
};