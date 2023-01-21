// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    vector<string>ans;
    vector<string> restoreIpAddresses(string s) {
        dfs(s,"",0,0);
        return ans;
    }
    void dfs(string s,string curip,int cnt,int cur){
        // check if number of integers more than 4 (invalid IP address)
        if(cnt>4){
            return ;
        }
        // check if number of integers equal 4 and reached the end of the string (valid IP address)
        if(cnt==4 && cur==s.size()){
            // save this IP address
            ans.push_back(curip);
            return ;
        }
        // i<=3 because each integer should not exceeded 255 (which is length equal 3)
        for(int i=1;i<=3;i++){
            if(cur+i>s.size()){
                break;
            }
            // create sub string of length i for this integer
            string subip=s.substr(cur,i);
            // if the integer has leading zeros or it is greater than 255 (invalid IP address)
            if((subip[0]=='0' && subip.size()>1) || stoi(subip)>255){
                continue;
            }else{
                // add this integer to the IP address and add '.'
                dfs(s,curip+subip+(cnt<3?".":""),cnt+1,cur+i);
            }
        }
    }
};