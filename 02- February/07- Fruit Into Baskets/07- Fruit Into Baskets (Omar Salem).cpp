//Author : Omar Salem
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //Intialize a map
        map < int , int > freq;
        //Intialize varibal
        int i = 0 , j  = 0 , ans = 0;
        while(j < fruits.size())
        {
            freq[fruits[j]]++;
// here we find a longest subarray that contains at most 2 different elements 
            if(freq.size() <= 2)
                ans = max(ans , j - i + 1);
            
            else
            {
                // if freq contains more than 2 different elemenets erase element is freq equal zero 
                freq[fruits[i]]--;
                if(freq[fruits[i]] == 0)
                    freq.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
           
    }
};