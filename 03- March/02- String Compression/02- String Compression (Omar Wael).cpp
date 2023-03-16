// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1){
            return 1;
        }
        int ans=0;
        int cnt=0;
        int i=0;
        int n=chars.size();
        while(i<n){
            // count current character
            cnt++;
            // check if current character is the last one or
            // current character not equal next one
            if(i+1==n || chars[i]!=chars[i+1]){
                // add current character
                chars[ans]=chars[i];
                // increase the answer
                ans++;
                // check if current group's length equal 1
                // then do not add the length
                if(cnt==1){
                    cnt=0;
                    i++;
                    continue;
                }
                // add the length
                string s=to_string(cnt);
                for(char c:s){
                    chars[ans]=c;
                    ans++;
                }
                cnt=0;
            }
            i++;
        }
        return ans;
    }
};
