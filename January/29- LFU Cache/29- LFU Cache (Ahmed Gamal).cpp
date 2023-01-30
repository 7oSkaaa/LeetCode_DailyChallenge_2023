// Author: Ahmed Gamal

class LFUCache {
public:

    // we are going to use a vector to store the value of each key, and a vector to store the frequency of each key (the number of times the key is accessed)
    // we are going to use a priority queue to store the keys in sorted order according to the frequency of the keys (the key with the lowest frequency will be at the top of the priority queue) 
    // and the time of the last access to the key (the key with the lowest time will be at the top of the priority queue if the frequencies of the keys are equal)
    // we can't directly use the keys as the elements of the priority queue because we need to update the frequency of the keys and the time of the last access to the keys
    // we can't also directly access the elements of the priority queue, so we will push a new element with the same key and the new frequency and the new time of the last access to the key to the priority queue every time we access a key
    // when we want to remove a key from the cache we will remove the key with the lowest frequency and the lowest time of the last access to the key from the cache and this key will shouldn't be the top of the priority queue (we may find some out of date elements while searching for the key to remove from the cache)
    // so, we will pop the top of the priority queue until we find the key with up to date frequency and time of the last access to the key

    // the item struct is used to store the frequency, the key, and the time of the last access to the key in the priority queue
    struct Item {
        int freq, key, time;

        Item(){
            freq = key = time = -1;
        }

        Item(int freq, int key, int time){
            this -> freq = freq;
            this -> key = key;
            this -> time = time;
        }
    };


    // Compare: custome comparator to use it in the priority queue while sorting the items
    class Compare {
        public:
            bool operator()(Item& a, Item& b){
                if(a.freq == b.freq){
                    return a.time > b.time;
                }
                return a.freq > b.freq;
            }
    };
    
    // time: vector to store the time of the last access to each key
    // freq: vector to store the frequency of each key (the number of times the key is accessed)
    // cache: vector to store the value of each key
    // pq: priority queue to store the keys in sorted order according to the frequency of the keys and the time of the last access to the key
    // timer: the current time
    // size: the number of keys in the cache (the number of keys with non-zero frequency)
    // capacity: the maximum number of keys in the cache
    vector<int> cache, freq, time;
    priority_queue<Item, vector<Item>, Compare> pq;
    int timer, size, capacity;

    // constructor
    LFUCache(int capacity) {
        cache = freq = time = vector<int>(1e5 + 5, 0);
        timer = 1;
        size = 0;
        this -> capacity = capacity;
    }
    
    // add a new key to the cache
    void add(int freq, int value, int key){
        // update the frequency, the value, and the time of the last access to the key
        this -> freq[key] = freq;
        cache[key] = value;
        time[key] = timer++;

        // push the new element to the priority queue
        pq.emplace(1, key, time[key]);
    }

    // update the frequency, the value, and the time of the last access to the key
    void update(int key, int value){
        freq[key]++;
        cache[key] = value;
        time[key] = timer++;

        // push the updated element to the priority queue
        pq.emplace(freq[key], key, time[key]);
    }

    // get the value of the key if the key exists in the cache, otherwise return -1
    int get(int key) {
        if(not freq[key]){
            return -1;
        }

        // update the frequency, the value (with the same value stored because we need only to increase the frequency and time, and push the new instance), and the time of the last access to the key
        update(key, cache[key]);
        return cache[key];
    }
    
    // update the value of the key if the key exists in the cache, otherwise add the key if the cache has a spare capacity (otherwise remove the least frequently used key and add the new key)
    void put(int key, int value) {
        if(freq[key]){
            update(key, value);
        }else{
            // remove the least frequently used key if the cache is full
            if(size == capacity){
                // the capacity is zero (we won't be able to pop any element from the priority queue)
                if(not capacity)
                    return;
                
                // remove the key with the lowest frequency and the lowest time of the last access to the key from the cache
                // do this until we find the key with up to date frequency and time of the last access to the key
                Item curr;
                do {
                    curr = pq.top();
                    pq.pop();
                }while(curr.freq != freq[curr.key]);

                // remove the key from the cache (set the frequency to zero and the value to -1)
                freq[curr.key] = 0;
                cache[curr.key] = -1;

                // add the new key to the cache
                add(1, value, key);
            }else{
                // add the new key to the cache
                size++;
                add(1, value, key);
            }
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
