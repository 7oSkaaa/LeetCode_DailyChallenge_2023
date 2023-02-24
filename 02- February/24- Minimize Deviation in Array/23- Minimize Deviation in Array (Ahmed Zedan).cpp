// author : Ahmed Zedan
class Solution {
public:
    /*
        - we need maximize smallest number and minimize largest number 
        - we can maximize only odd number and minimize only even number 
    */
    int minimumDeviation(vector<int>& nums) {
        multiset<int>ms ; // to auto sort element
        for(auto &i : nums){
            if(i%2) i*=2 ; // try to maximize odd element
            ms.insert(i) ;
        }
        int ans = *ms.rbegin() - *ms.begin() ; // current minimum deviation
        // try to minimize all even numbers (divide by 2)
        while(!(*ms.rbegin()%2)){
            auto curr = *ms.rbegin() ; 
            ms.erase(curr) ; 
            ms.insert(curr/2) ; 
            ans = min(ans,*ms.rbegin() - *ms.begin()) ; // check if current deviation minimum
        }
        return ans ; 
    }
};