// author: Esraa Syam
class Solution {
public:
   vector < string > res; 
    void rec(string s, int idx , string ip, int count) {
        // base case
        // if we have 4 parts and we have reached the end of the string
        // then we have a valid ip address
        // so we push it to the result
       if (count == 4) {
           if (idx == s.size()) res.push_back(ip);
           return;
       }
       // we have 3 choices for each part to make a valid ip address
       // 1. take 1 digit
       // 2. take 2 digits
       // 3. take 3 digits
       // but we have to make sure that the number is less than 255
       // and we have to make sure that we don't take leading zeros
       // for example 01 is not valid
       // so if the first digit is 0 then we can't take more than 1 digit
       // and if the number is greater than 255 then we can't take more than 2 digit
       // so we break
       // and we add a dot if it's not the last part
       // if it's the last part then we don't add a dot
       for (int i = 1; i <= 3 and idx + i <= s.size(); i++) {
           string t = s.substr(idx, i);
           if(t[0] == '0' and t.size() > 1) break;
           if (stoi(t) <= 255) {
               string newIp = ip + t + (count == 3 ? "" : ".");
               rec(s, idx + i, newIp, count + 1);
           }
       }
   }
   vector<string> restoreIpAddresses(string s) {
       rec(s, 0, "", 0);
       return res;
   }
};
