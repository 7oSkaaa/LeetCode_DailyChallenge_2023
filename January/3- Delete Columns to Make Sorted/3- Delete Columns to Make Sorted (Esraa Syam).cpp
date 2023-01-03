// author: Esraa Syam
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        string s = "";
        int cnt = 0;
        // 1 - Traverse The Grid Through The Columns  
        // 2 - put every column it in a string then take a copy 
        // 3 - sort it then compare it with the condition of the problem
        for(int i = 0 ; i < strs[0].size() ; i++){
            for(int j = 0 ; j < strs.size() ; j++){
                s += strs[j][i];
            }
            string t = s;
            sort(t.begin() , t.end());
            if(t != s) cnt++;
            s = "";
        }
        return cnt;
    }
};