// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // devide the projects into two parts
        // first part contain projects that you can finish it
        // second part contain projects that you cannot finish it
        priority_queue<int> canChoose;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>canNotChoose;
        int n=capital.size();
        for(int i=0;i<n;i++){
            if(capital[i]<=w){
                canChoose.push(profits[i]);
            }else{
                canNotChoose.push({capital[i],profits[i]});
            }
        }
        while(k-- && !canChoose.empty()){
            // choose best profit from projects you can finish it
            w+=canChoose.top();
            canChoose.pop();
            // update the progects you cannot finish
            while(!canNotChoose.empty() && canNotChoose.top().first<=w){
                canChoose.push(canNotChoose.top().second);
                canNotChoose.pop();
            }
        }
        return w;
    }
};
