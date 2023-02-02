// Author: Mina Magdy

unordered_map<int, int> val, cnt, lu; // lu: last_used maintained by 'ins' (aka. instruction_pointer)

class LFUCache {
public:
    int cap; // capacity
    int ins; // instruction_pointer: increased every put() and get() calls
    /*
        user-defined data type 'Node' for comparing firstly 'cnt' (aka. use counter)
        secondly if 'cnt' are tie sort by 'lu' (aka. last_used)
    */
    class Node {
    public:
        int key;
        Node(int _key = 0) : key(_key) {}
        bool operator<(const Node & p) const {
            if (cnt[key] == cnt[p.key]) return lu[key] < lu[p.key];
            return cnt[key] < cnt[p.key];
        }
    };
    set<Node> st;
    LFUCache(int capacity) {
        ins = 0;
        cap = capacity;
        /*
            using clear here because they was in global scope
            the reason of putting them in global,
             is to be able to access them inside class 'Node' while using 'operator<'
        */
        val.clear();
        cnt.clear();
        lu.clear();
    }
    
    int get(int key) {
        if (!cap) return -1;
        if (val.find(key) == val.end()) return -1;
        /*
            every update:
            1- erase 'key'
            2- update 'key'
            3- insert 'key' again
        */
        st.erase(key);
        lu[key] = ins++;
        cnt[key]++;
        st.insert(key);
        return val[key];
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (val.size() == cap && val.find(key) == val.end()) {
            /*
                the st.begin()->key is the key which is LFU and LRU, to be removed
            */
            int ans = st.begin()->key;
            val.erase(ans);
            cnt.erase(ans);
            lu.erase(ans);
        }
        /*
            every update:
            1- erase 'key'
            2- update 'key'
            3- insert 'key' again
        */
        st.erase(key);
        cnt[key]++;
        lu[key] = ins++;
        st.insert(key);
        val[key] = value;
    }
};
