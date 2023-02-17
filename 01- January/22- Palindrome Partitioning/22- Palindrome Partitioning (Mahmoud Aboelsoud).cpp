// Author: Mahmoud Aboelsoud

class Solution {
public:
    // initialize string s which is the input string
    string s;

    // initialize vector of strings v_temp which is the temporary vector of strings
    vector<string> v_temp;
    
    // initialize vector of vectors of strings ans which is the answer vector of vectors of strings
    vector<vector<string>> ans;


    // function to check if the substring from index l to index r is a palindrome or not
    bool plain(int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return 0;
        }

        return 1;
    }

    // backtracking function to partition the string into palindromes
    void rec(int idx, int lst){
        // if the index idx is equal to the size of the string s
        // then we have reached the end of the string
        // so we check if the lst which is the start index of new substring partition is equal to the size of the string s
        // if it is equal then we have reached the end of the string and we have a valid partitions till the end of the string
        // so we push the temporary vector of strings v_temp into the answer vector of vectors of strings ans 
        if(idx == s.size()){
            if(lst == s.size())
                ans.push_back(v_temp);
            return;
        }

        // now we have two choices
        // 1- we can add the current character to the current substring partition
        // 2- we can start a new substring partition from the next character if the current substring partition is a palindrome
        // our current substring partition is from index lst to index idx 
        
        // choice 1
        // we add the current character to the current substring partition by moving to next character and keeping the start index of the current substring partition the same
        rec(idx + 1, lst);


        // choice 2
        // we check if the current substring partition is a palindrome or not
        // if it is a palindrome then we start a new substring partition from the next character
        // we also push the current substring partition into the temporary vector of strings v_temp
        // then we call the backtracking function rec() to continue the partitioning with the new substring partition which is from index idx + 1 to index idx + 1
        if(plain(lst, idx)){
            v_temp.push_back(s.substr(lst, idx - lst + 1));
            rec(idx + 1, idx + 1);
            v_temp.pop_back();
        }
            
    }



    vector<vector<string>> partition(string s) {
        this -> s = s;

        // call the backtracking function rec() to start the partitioning from the first character
        rec(0, 0);
        return ans;
    }
};
