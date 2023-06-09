// Author: Ahmed Gamal

// for this problem, we will implement exactly what the problem asks for by using a vector of bools
// we will keep track of the numbers that we add to the set by setting the corresponding index in the vector to true

class MyHashSet {
    // table: vector of bools
    vector<bool> table;
public:
    MyHashSet() {
        // initialize the vector with a size of 1e6 + 5 and set all values to false
        table.assign(1e6 + 5, false);
    }
    
    void add(int key) {
        // set the corresponding index to true
        table[key] = true;
    }
    
    void remove(int key) {
        // set the corresponding index to false
        table[key] = false;
    }
    
    bool contains(int key) {
        // return the value of the corresponding index
        return table[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */