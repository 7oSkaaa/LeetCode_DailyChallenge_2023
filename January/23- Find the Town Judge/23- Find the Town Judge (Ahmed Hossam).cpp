// Author: Ahmed Hossam

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        /*
            to[i] -> number of people that the person i trust them
            from[i] -> number of people that trust person i
        */
        vector < int > to(n + 1), from(n + 1);
        for(auto vec : trust)
            to[vec[0]]++, from[vec[1]]++;
        
        /*
            the person is judge if two condition satisfied
            - every body trust him -> from[i] = n - 1
            - he trust no body -> to[i] = 0;
        */ 

        for(int i = 1; i <= n; i++)
            if(to[i] == 0 && from[i] == n - 1)
                return i;
        
        // if there is no judge exist
        return -1;
    }
};
