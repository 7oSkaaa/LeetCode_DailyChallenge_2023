// Author: Zeinab Mohy

class Solution {
public:
    int addDigits(int num) {
      //convert num into string to apply my idea
        string s=to_string(num);
      //if the length of string is greater than 1 then ..
        if(s.length()>1){
            while(s.length()>1){
              /*initialize the summation of the digits with 0 
              then sum the digits in string after convert all into integer 
              then convert summatiomn into string again and so on 
              until the length of string equal 1*/
                int sum=0;
                string ss;
                for(int i=0;i<s.length();i++){
                    ss=s[i];
                    int x=stoi(ss);
                    sum+=x;
                }
                s=to_string(sum);
            }
          // after that convert string into integer to return the result
            int ans=stoi(s);
            return ans;
        }else{
            return num;
        }
    }
};
