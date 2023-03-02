//Author: Abdullah Moemen

class Solution {
public:
    int compress(vector<char>& chars) {

        ///first intialize new vector(arr) that at the end will have (chars) after compressed
        ///  iterate over (chars) every time we found consecutive repeating characters increase count by one

        /// if current char in chars not match with previous char in chars, we add previous char to arr and their count if 
        /// its counts more than 1 character 

        char c=chars[0];
        vector<char>arr;
        int cnt=1;
        int ans=0;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==c)
            {
                cnt++;
            }
            else 
            {
                if(cnt==1)
                {
                    ans++;
                    arr.push_back(c);
                }
                else 
                {
                   ans++;
                   string x=to_string(cnt);
                   ans+=x.size(); 
                   arr.push_back(c);
                   for(int j=0;j<x.size();j++)arr.push_back(x[j]);
                }
                cnt=1;
                c=chars[i];
            }
        }
         
                if(cnt==1)
                {
                    ans++;
                    arr.push_back(c);
                }
                else 
                {
                   ans++;
                   string x=to_string(cnt);
                   ans+=x.size(); 
                   arr.push_back(c);
                   for(int j=0;j<x.size();j++)arr.push_back(x[j]);
                }
                
                chars.clear();
                for(auto e:arr)chars.push_back(e);
               // c=chars[i];
                return ans;
        
    }
};