// Author: Mahmoud Aboelsoud

class LFUCache {
public:
    // counter to keep track of the recent used, n is the capacity
    int counter = 0, n;
    // cnt to keep track of the frequency of each key, ma to keep track of the value of each key, lru to keep track of the recent used of each key
    unordered_map<int,int> cnt, ma, lru;
    // pq to keep track of the least frequency and the recent used of each key in the cache to help in removing the lfu when the cache is full 
    priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>, greater<pair<pair<int,int>, int>>> pq;
    
    LFUCache(int capacity) {
        n = capacity;
    }
    

    int get(int key) {
        // if the key is in the cache
        if(ma.count(key)){
            // update the frequency and the recent used of the key
            lru[key] = counter, counter++, cnt[key]++;
            // update the pq to keep the least frequency and the recent used of each key in the cache
            pq.push({{cnt[key], lru[key]}, key});
            // return the value of the key
            return ma[key];
        }
        // if the key is not in the cache return -1
        return -1;
    }
    
    void put(int key, int value) {
        // if the capacity is 0 return
        if(n == 0) return;
        // if the key is in the cache or the cache is not full 
        if(ma.count(key) || ma.size() < n){
            // update the frequency and the recent used of the key
            // update the value of the key
            // update the pq to keep the least frequency and the recent used of each key in the cache
            ma[key] = value, cnt[key]++, lru[key] = counter, counter++;
            pq.push({{cnt[key], lru[key]}, key});
        }else{
            // if the cache is full
            // remove the least frequency and the recent used key from the cache with the help of the pq
            while(ma.size() == n){
                auto x = pq.top();
                pq.pop();
                int freq = x.first.first, recent = x.first.second;
                int k = x.second;
                // if the frequency and the recent used of the key is the same as the least frequency and the recent used of the key in the cache
                // remove the key from the cache
                if(cnt[k] == freq && lru[k] == recent)
                    ma.erase(k), cnt.erase(k), lru.erase(k);
            }
            // add the new key to the cache
            // update the frequency and the recent used of the key
            // update the value of the key
            // update the pq to keep the least frequency and the recent used of each key in the cache
            ma[key] = value, cnt[key]++, lru[key] = counter, counter++;
            pq.push({{cnt[key], lru[key]}, key});
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
