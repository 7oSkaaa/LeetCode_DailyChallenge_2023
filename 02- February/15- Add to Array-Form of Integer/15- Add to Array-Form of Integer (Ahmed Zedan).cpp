// author : Ahmed Zedan 
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        long long n=k ; 
        vector<int>res ;
        for(int i=num.size()-1 ; i>=0 ; i--){
            n+=num[i]; 
            res.push_back(n%10) ; 
            n/=10 ; 
        }
        while(n){
            res.push_back(n%10) ; 
            n/=10 ; 
        }
        reverse(res.begin(),res.end());
        return res ; 
    }
};