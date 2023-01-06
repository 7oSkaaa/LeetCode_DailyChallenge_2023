// Author           : Khaled Waleed
// File Created on  : 06/Jan/2023 on 18:14:12


// The idea is.. we have limited coins and just want to buy the largest number
// so we will buy the cheapest bars !

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end()); // we  sort the bars to get them ordered from the cheapest to the most expensive
        int answer = 0;
        for (int i = 0; i < costs.size() && coins > 0; ++i) { // we keep buying bars until our money becomes less than or equal to zero
            coins -= costs[i];
            answer++;
        }

        if(coins < 0){ // if the last bar was so expensive that our money became negative then we undo the latest bar and turn it back
            answer--;
        }

        return answer;
    }
};
