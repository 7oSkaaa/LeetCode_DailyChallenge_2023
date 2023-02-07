// Author: Ahmed Hossam

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //  the frequency of each type of tree
        map < int, int > freq;

        // two pointers to moves
        int l = 0, r = 0, max_fruits = 0, n = fruits.size();
        
        while(r < n){
            // add the current tree
            freq[fruits[r]]++;

            // check if you have only two types of trees or not
            while(freq.size() > 2){
                // remove the leftmoste tree from the baskets until you have two unique types of trees
                freq[fruits[l]]--;
                
                // if the frequency of this tree becomes zero so let's remove it
                if(freq[fruits[l]] == 0)
                    freq.erase(fruits[l]);
                
                // move from the leftmost tree to it's right tree
                l++;
            }
            
            // update max_fruits can collect with the size of the range
            max_fruits = max(max_fruits, r - l + 1);

            // move the rightmost tree
            r++;
        }

        // maximum number of fruits can be picked
        return max_fruits;
    }
};
