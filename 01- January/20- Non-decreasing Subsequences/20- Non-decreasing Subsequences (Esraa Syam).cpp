// author: Esraa Syam
class Solution {
public:
    vector < vector < int > > res; // the vector that will contain the result
    // the vector that will contain the current subsequence 
    // cheak vector is used to check if the current subsequence is valid or not 
    vector < int > curr , cheak; 
    map < vector < int > , int > mp; // map to check if the current subsequence is already in the result or not
    void rec(int i , vector < int > &num){
        // base case
        cheak = curr; // cheak vector is used to check if the current subsequence is valid or not
        sort(cheak.begin() , cheak.end()); // sort the cheak vector
        // if the current subsequence is valid and it is not already in the result then push it in the result
        if(cheak == curr and curr.size() >= 2 and mp.find(curr) == mp.end()){
            res.push_back(curr);
            mp[curr] = 1; // mark the current subsequence as already in the result
        }
        // rec case
        for(int j = i  ; j < num.size() ; j++){
            curr.push_back(num[j]); // push the current element in the current subsequence
            rec(j + 1, num); // call the rec function with the next index and the same vector
            // backtracking step
            // pop the last element from the current subsequence
            // so that we can try the next element in the next iteration
            curr.pop_back();      
        }
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        rec(0 , nums); 
        return res;
    }
};
/*
the idea is to use backtracking to generate all the possible subsequences
and then check if the current subsequence is valid or not
if it is valid and it is not already in the result then push it in the result
*/