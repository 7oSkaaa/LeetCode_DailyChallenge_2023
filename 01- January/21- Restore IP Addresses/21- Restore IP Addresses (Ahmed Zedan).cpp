// author : Ahmed Zedan
class Solution {
public:
    string s; // digits
    int n  ; // size of digit string
    vector<string>v , ans ; 
    void rec(int i=0){
        // check if select all digits and  numbers is only four number 
        if(i==n&&v.size()==4){
            string a = v[0]+'.'+v[1]+'.'+v[2]+'.'+v[3] ; 
            ans.push_back(a) ; 
            return ; 
        }
        if(i>n&&v.size()>4) return ; //base case 
        for(int j=1 ; j<=3 ; j++){ // select(1-3)digit because the number between(0-255)
            if(i+j-1<n){
                string str = s.substr(i,j) ;  
                int x = stoi(str) ; 
                // check number is valid 
                if(j>1&&str[0]=='0') continue ; 
                if(x>=0&&x<=255){
                    v.push_back(str) ; // do 
                    rec(i+j) ; // recursion call
                    v.pop_back() ; //undo
                } 
            }
        }
    }  
    vector<string> restoreIpAddresses(string s) {
        n = s.size() ; 
        this->s = s ;     
        rec() ;  
        return ans ; 
    }
};