//Author: Abdullah Moemen 

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        string s=to_string(k);
        int i=num.size()-1;
        int j=s.size()-1;
        int c=0;
        while(i>=0&&j>=0)
        {
            int x=s[j]-'0';
            int cc=x+num[i]+c;
            ans.push_back(cc%10);
            c=cc/10;
            i--;
            j--;
        }
        while(i>=0)
        {
            int x=num[i]+c;
            int cc=c+num[i];
             ans.push_back(cc%10);
            c=cc/10;
            i--;
        }
        while(j>=0)
        {
            int x=s[j]-'0';
            int cc=c+x;
            ans.push_back((cc%10));
            c=cc/10;
            j--;
        }
        if(c)ans.push_back(c);
        reverse(ans.begin(),ans.end());
      //  for(auto e:ans)cout<<e<<" ";
        return ans;
        
    }
};