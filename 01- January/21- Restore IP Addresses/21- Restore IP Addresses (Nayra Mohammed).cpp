//Author : Nayra Mohammed


/*
Using backtracking ,We will find all valid partitions of our string
A valid partition to make an ip address is when we can apply the following rules:
        * Each integer in an ip address is between 0 and 255 
        * Have no leading zeros.
*/
#define sz(s) (int(s.size()))
class Solution {
public:
    string x; // global copy of our original string

    bool is_valid(string s,char ss){ // check whether the values in ip address are proper (less than 256)
        int val = ((s[0] - '0') * 100) + ((s[1]-'0') * 10) + (ss -'0');

        return val <= 255;
    }

    void Generate(int idx,vector<string>ip,vector<string>&v){
        
        if(idx == sz(x)) //base case  : we finished all digits 
        {   
        
            if(sz(ip) == 4) // valid ip address is represented  as 4 bytes
            {  
                // make the generated ip in form of  " num1 . num2 . num3 . num4 " 
                
                string ip_f = ip[0]; 
                for(int i = 1; i < 4 ; i++)
                    ip_f += "." + ip[i];

                v.push_back(ip_f); //push it into our final answer 
            }

            return;
        }
        
        //add current digit as a new start for the next integer in ip address
        ip.push_back(to_string(x[idx]-'0')),Generate(idx+1,ip,v),ip.pop_back();
        
      
        // add current digit as a part of previous integer if and only if adding it won't results in having a leading 0 "00 or 01 ..etc"
      
        if(sz(ip) && sz(ip.back()) == 1 && ip.back()[0] != '0')
            ip.back() += x[idx], Generate(idx+1, ip,v), ip.back().pop_back();
      
      // Or adding it will results in a proper value for the integer "less than 256"       
        if(sz(ip) && sz(ip.back()) == 2 && is_valid(ip.back(),x[idx]))
            ip.back() += x[idx], Generate(idx+1, ip,v), ip.back().pop_back();
                
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string>ans; //store all valid partition for ip addresses
        x = s; //make it global
        
        if(sz(s) > 12)   // we can't have an ip address bigger than 255.255.255.255  
            return {}; //return empty 
      
        // start from first digit, an empty ip address, passing ans by reference to store all valid ip addresses throughout the process  
        Generate(0,{},ans); 
      
        return ans; //return all valid partitions    
    }
};
