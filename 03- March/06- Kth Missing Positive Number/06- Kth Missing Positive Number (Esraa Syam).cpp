// author: Esraa Syam
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector < int > v(2000); 
        iota(v.begin() , v.end() , 1); // fill the vector with 1 to 2000
        int cnt = 0;
        for(int i = 0 ; i < v.size() ; i++){
            // if the number is not in the array then increase the counter
            // and return the number if the counter is equal to k 
            // because the number is the kth missing number
            if(!binary_search(arr.begin() , arr.end() , v[i])) cnt++;
            if(cnt == k) return v[i];
        }
        return 0; 
    }
};
