// Author: Mahmoud Aboesloud

class Solution {
public:
    // initalize the string s that is the input string and the temp string that is the current string that we are building from the backtracking
    string s, temp = "";

    // initalize the vector of strings that is the answer
    vector<string> ans;
    

    // check if the current string is a valid ip address
    // if it is return 1 else return 0
    // the function is called after we have built the current string
    bool check(string chk){
        string k = "";
        // loop on the current string
        for(int i = 0; i < chk.size(); i++){
            // if the current character is a dot
            // check if the current part of ip address is valid
            if(chk[i] == '.'){
                // if the size of the current part is greater than 3 or equal to 0 return 0 because each part of ip address must be between 0 and 255
                if(k.size() > 3 || k.size() == 0) return 0;
                // if the size of the current part is greater than 1 and the first character is 0 return 0 because the first character of each part of ip address must not be 0
                if(k.size() > 1 && k[0] == '0') return 0;
                // if the current part is greater than 255 return 0
                if(stoi(k) > 255) return 0;

                // reset the current part
                k = "";
            }else
                // build the current part of ip address
                k += chk[i];
        }
        // check the last part of ip address
        if(k.size() > 3 || k.size() == 0) return 0;
        if(k.size() > 1 && k[0] == '0') return 0;
        if(stoi(k) > 255) return 0;

        // if the current string is a valid ip address return 1
        return 1;
    }
    
    // the backtracking function
    // idx is the current index in the input string
    // dot is the number of dots that we have added to the current string, we must add 3 dots to create a valid ip address
    void rec(int idx, int dot = 3){
        // if the current index is equal to the size of the input string
        if(idx == s.size()){
            // we check if the current string is a valid ip address and if we have added 3 dots to the current string
            // if it is we push the current string to the answer
            if(check(temp) && dot == 0)
                ans.push_back(temp);
            
            return;
        }

        // we have 2 choices
        // 1- add the current character to the current string
        // 2- add the current character and a dot to the current string as we declare that the current character is the end of the current part of ip address
        // we call the function recursively with the next index and the number of dots that left to add

        // first choice
        // add the current character to the current string and call the function recursively 
        temp += s[idx];
        rec(idx + 1, dot);

        // second choice
        // add the current character and a dot to the current string and call the function recursively if we have dots left to add
        if(dot){
            temp += '.';
            rec(idx + 1, dot - 1);
            // remove the dot that we added to the current string
            temp.pop_back();
        }
        // remove the current character that we added to the current string
        temp.pop_back();
    }

    vector<string> restoreIpAddresses(string s) {
        // set the input string to the string s
        this -> s = s;
        // if the size of the input string is less than 4 or greater than 12 return an empty vector because the size of the input string must be between 4 and 12
        if(s.size() < 4 || s.size() > 12) return {};

        // call the backtracking function
        rec(0);

        return ans;
    }
};
