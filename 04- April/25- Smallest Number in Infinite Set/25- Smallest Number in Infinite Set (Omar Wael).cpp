// Author : Omar Wael
// leetcode account : https://leetcode.com/OmarWael1/

class SmallestInfiniteSet {
public:
    int ans=1;
    priority_queue<int,vector<int>,greater<int>>pq;
    int vis[1005];
    SmallestInfiniteSet() {
        // min number is 1
        ans=1;
        // visit all numbers
        for(int i=1;i<=1004;i++){
            vis[i]=1;
        }
    }
    int popSmallest() {
        // if there is number less than the ans 
        // then unvisit it and return it
        if(!pq.empty() && pq.top()<ans){
            int cur=pq.top();
            pq.pop();
            vis[cur]=0;
            return cur;
        }
        // otherwise unvisit the answer and return it
        vis[ans]=0;
        ans++;
        return ans-1;
    }
    void addBack(int num) {
        // if current number is unvisited push it
        if(!vis[num]){
            pq.push(num);
            vis[num]=1;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
